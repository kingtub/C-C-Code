#include<iostream>
#include"S.h"

using namespace std;


JNIEXPORT void JNICALL Java_S_pass
  (JNIEnv *env, jobject obj, jstring jstr) {
  	jsize unicodeLen = env->GetStringLength(jstr);
  	jsize utf8Len = env->GetStringUTFLength(jstr);
  	
  	jboolean b1, b2;
  	const jchar* unicodeChars = env->GetStringChars(jstr, &b1);
  	
  	const char* utf8Chars = env->GetStringUTFChars(jstr, &b2);
  	
  	cout<<"unicodeLen is "<<unicodeLen<<endl;
  	cout<<"b1 is "<<(b1 == JNI_TRUE? "true":"false")<<endl;
  	
  	for(jsize i = 0; i < unicodeLen; i++) {
	  	cout<<(char)unicodeChars[i]<<" ";
	  }
    cout<<endl;
   	for(jsize i = 0; i < unicodeLen; i++) {
	  	cout<<unicodeChars[i]<<" ";
	  }
    cout<<endl;
    env->ReleaseStringChars(jstr, unicodeChars);
  	
	  
    cout<<"utf8Len is "<<utf8Len<<endl;
  	cout<<"b2 is "<<(b2 == JNI_TRUE? "true":"false")<<endl;
 	
  	for(jsize i = 0; i < utf8Len; i++) {
	  	cout<<utf8Chars[i];
    }
    cout<<endl;
    env->ReleaseStringUTFChars(jstr, utf8Chars);
  }