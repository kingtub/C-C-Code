#include<iostream>
#include"Array.h"

using namespace std;

JNIEXPORT jintArray JNICALL Java_Array_sumAndSquare
  (JNIEnv *env, jobject jobj, jintArray jiarr) {
  	jsize len = env->GetArrayLength(jiarr);
  	jboolean b;
  	jint sum = 0;
  	jint *arr = env->GetIntArrayElements(jiarr, &b);
  	cout<<"b is "<<(b == JNI_TRUE? "true":"false")<<endl;
  	
  	for(int i = 0; i < len; i++) {
	  	sum += arr[i];
	  }
    jint square = sum * sum;
    
    env->ReleaseIntArrayElements(jiarr, arr, 0);
    
    jintArray ret = env->NewIntArray(2);
    
    jint a[] = { sum, square};
    env->SetIntArrayRegion(ret, 0, 2, a);
    
    return ret;
  }