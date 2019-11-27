//
// Created by txs on 19-11-26.
//
#include <jni.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif
void callJavaMethod(JNIEnv *env, jobject thiz){
    jclass clazz = env->FindClass("com/coobee/jnitest/MainActivity");
if (clazz == NULL){
printf("find class MainActivity error !");
return;
}
jmethodID id = env->GetStaticMethodID(clazz,"methodCalledByJni","(Ljava/lang/String;)V");
if(id == NULL){
printf("find method methodCalledByJni error !");
}
jstring msg = env->NewStringUTF("msg send by callJava in test.cpp");
env->CallStaticVoidMethod(clazz,id,msg);
}


jstring Java_com_coobee_jnitest_MainActivity_get(JNIEnv *env, jobject thiz){
printf("invoke get in c++ \n");
callJavaMethod(env,thiz);
return env->NewStringUTF("Hello from JNI in libjni-test.so !");
}
void Java_com_coobee_jnitest_MainActivity_set(JNIEnv *env, jobject thiz, jstring string){
printf("invoke set from C++ \n");
char* str = (char*)env->GetStringUTFChars(string,NULL);
printf("%s\n,s",str);
env->ReleaseStringUTFChars(string,str);
}
#ifdef __cplusplus
}
#endif