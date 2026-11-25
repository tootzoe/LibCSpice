# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 4.1.2)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("cspice" LANGUAGES C CXX)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.
#
# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.

# file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")
file(GLOB_RECURSE CSPICESRC CONFIGURE_DEPENDS "cspice/*.c" )

add_library(${CMAKE_PROJECT_NAME}
        SHARED
        # List C/C++ source files with relative paths to this CMakeLists.txt.
        native-lib.cpp
        ${CSPICESRC}
        )

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.




#include(ExternalProject)
#add_definitions(-DASSIMP_ANDROID_JNIIOSYSTEM=ON)
#add_definitions(-DCMAKE_TOOLCHAIN_FILE=C:/Android/SDK/ndk/28.0.12433566/build/cmake/android.toolchain.cmake)
#add_definitions(-DCMAKE_MAKE_PROGRAM=C:/Android/SDK/cmake/3.31.0/bin/ninja.exe)


# androidPrj\TestNativeCpp\app\src\main\cpp
# set(tootassimp_src  ../../../../../../misc/assimp/tootand2)
# set(tootassimp_bd  ./tootassimp_bd)

#file(MAKE_DIRECTORY ${tootassimp_bd})  # create a folder

#add_subdirectory(${tootassimp_src} ${tootassimp_bd})  ### ??????

#ExternalProject_Add(assimp
#        GIT_REPOSITORY "https://github.com/assimp/assimp.git"
#        CMAKE_CACHE_ARGS "-DCMAKE_INSTALL_PREFIX:STRING=${tootassimp_bd} -DASSIMP_ANDROID_JNIIOSYSTEM=ON -DASSIMP_ANDROID_JNIIOSYSTEM=ON -DCMAKE_TOOLCHAIN_FILE=C:/Android/SDK/ndk/28.0.12433566/build/cmake/android.toolchain.cmake -DCMAKE_MAKE_PROGRAM=C:/Android/SDK/cmake/3.31.0/bin/ninja.exe"
#        BUILD_BYPRODUCTS ${tootassimp_bd}/${ANDROID_ABI}/libtootassimp.so
#)

# add_library(tootassimp STATIC IMPORTED)
# set_target_properties(tootassimp PROPERTIES IMPORTED_LOCATION
#                      ${tootassimp_bd}/${ANDROID_ABI}/libtootassimp.so )
# include_directories(${tootassimp_src}/include)


if(ANDROID)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
        "-Wl,--no-gc-sections")

target_link_libraries(
        ${CMAKE_PROJECT_NAME}
 #       tootassimp
        # List libraries link to the target library
        android
        log)


elseif(APPLE)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
 #   FRAMEWORK TRUE
    FRAMEWORK_VERSION "1.0.1"
    MACOSX_FRAMEWORK_IDENTIFIER com.tootzoe.libcspice
 #   PUBLIC_HEADER "cspice/aa.h cspice/bb.h"
    XCODE_ATTRIBUTE_SKIP_INSTALL "NO"
    XCODE_ATTRIBUTE_BUILD_LIBRARY_FOR_DISTRIBUTION "YES"
)



target_link_libraries(
        ${CMAKE_PROJECT_NAME}
 #       tootassimp
        # List libraries link to the target library
        )

endif()


## toot generate .xcodeproj
#  cmake -S . -B tootbd_iOS -G Xcode -DCMAKE_SYSTEM_NAME=iOS
#  cmake -S . -B tootbd_Mac -G Xcode -DCMAKE_SYSTEM_NAME=Darwin

# on Mac , if 'No CMAKE_C_COMPILER could be found.'

# cmake -D CMAKE_C_COMPILER="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc" -D CMAKE_CXX_COMPILER="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++"  -S . -B tootbd_Mac -G Xcode -DCMAKE_SYSTEM_NAME=Darwin




