/*

-Header_File system_.c ( CSPICE version of the system_.c routine )

-Abstract

   This file replaces the standard f2c system_.c library file. The system_
   code now branches to Mac classic and non Mac classic code. The non Mac
   code matches the standard f2c library version, the Mac classic code
   returns a 0 as Mac classic has no system call facility.
      
-Disclaimer

   THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE
   CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S.
   GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE
   ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE
   PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS"
   TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY
   WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A
   PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC
   SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE
   SOFTWARE AND RELATED MATERIALS, HOWEVER USED.

   IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA
   BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT
   LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND,
   INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS,
   REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE
   REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY.

   RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF
   THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY
   CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE
   ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE.

-Required_Reading

   None.
   
-Particulars 
   

-Literature_References

   None.

-Author_and_Institution

   E.D. Wright       (JPL)
   
-Restrictions

  1) Requires CSPICE f2c.h header file.
   
-Version

   -CSPICE Version 1.0.0, 02-JAN-2002 (EDW)  

*/

#include "f2c.h"


#include <stdio.h>


// tootzoe testing
#if 0

integer system_(register char *s, ftnlen n) {
    return 0;
}

#else


#ifdef KR_headers
@#$%^&*
   extern char *F77_aloc();

   integer system_(s, n) register char *s; ftnlen n;

#else

   #undef abs
   #undef min
   #undef max
   #include "stdlib.h"

   extern char *F77_aloc(ftnlen, char*);

   integer system_(register char *s, ftnlen n)

#endif

   {

#ifndef CSPICE_MACPPC

   char buff0[256], *buff;
   register char *bp, *blast;
   integer rv;

   buff = bp = n < sizeof(buff0) ? buff0 : F77_aloc(n+1, "system_");
   blast = bp + n;

   while(bp < blast && *s)
      {
      *bp++ = *s++;
      }

   *bp = 0;


#if defined(__APPLE__)
    #include <TargetConditionals.h>

    #if TARGET_OS_IPHONE == 1
        // iOS  physical device
    // need to rerount to objc to do same cmd as system()....
   printf("\n\ntootzoe :  need to rerount to objc to do same cmd as system()....\n\n");
    #elif TARGET_OS_MAC == 1
          rv  = system(buff);
    #endif

#else
   rv  = system(buff);
#endif




   if (buff != buff0)
       {
       free(buff);
       }
   return rv;

#endif

#ifdef CSPICE_MACPPC

   /* 
   The Macintosh Classic environment lacks a system command.
   
   Return a fail.
   */
    
   return 0;

#endif

   }


#endif