#include <jni.h>
#include <string>

// extern "C" JNIEXPORT jstring JNICALL
// Java_com_tootzoe_libcspice_MainActivity_stringFromJNI(
//         JNIEnv* env,
//         jobject /* this */) {
//     std::string hello = "Hello from C++ by tootzoe.com";
//     return env->NewStringUTF(hello.c_str());
// }

int tootfunc(int a , int b)
{
 return a + b;
}