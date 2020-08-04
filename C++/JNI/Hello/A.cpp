#include<string>
#include"A.h"

using namespace std;
extern "C"
JNIEXPORT jstring JNICALL Java_A_getStringFromCpp
  (JNIEnv *env, jobject thiz)
  {
  	string s = "Hello, asdfg";
  	return env->NewStringUTF(s.c_str());
  }
  