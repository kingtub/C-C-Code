#include"Dim2Arr.h"

JNIEXPORT jobjectArray JNICALL Java_Dim2Arr_get2DimArr
  (JNIEnv *env, jobject jobj, const jint size) {
  	jclass iaClass = env->FindClass("[I");
  	jobjectArray oArr = env->NewObjectArray(size, iaClass, NULL);
  	jint count = 0;
  	for(jint i = 0; i < size; i++) {
  		
  		
	  	jintArray iarr = env->NewIntArray(size);
	  	jint ia0[size];
	  	for(jint k = 0; k < size; k++) {
	  		ia0[k] = ++count;
	  	}
	  	env->SetIntArrayRegion(iarr, 0, size, ia0);
	  	
	  	
	  	env->SetObjectArrayElement(oArr, i, iarr);
	  	
	  	env->DeleteLocalRef(iarr);
	  }


    return oArr;
  }