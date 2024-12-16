#include "com_i_uf_Main.h"

#include <iostream>
#include <string>

using namespace std;

JNIEXPORT void JNICALL Java_com_i_1uf_Main_helloWorld(JNIEnv* env, jclass jclass) {
    cout << "Hello, World!" << endl;
}
JNIEXPORT jobject JNICALL Java_com_i_1uf_Main_second(JNIEnv* env, jclass jcl, jobject first) {
    jclass personClass = env->GetObjectClass(first);
    jmethodID constructor = env->GetMethodID(personClass, "<init>", "(ILjava/lang/String;)V");
    jfieldID ageField = env->GetFieldID(personClass, "age", "I");
    jfieldID nameField = env->GetFieldID(personClass, "name", "Ljava/lang/String;");
    jint age = env->GetIntField(first, ageField);
    jstring name = (jstring)env->GetObjectField(first, nameField);
    jobject newPerson = env->NewObject(personClass, constructor, age + 1, name);
    return newPerson;
}
JNIEXPORT jobject JNICALL Java_com_i_1uf_Main_fourth(JNIEnv* env, jclass jcl, jobject third) {
    jclass personClass = env->GetObjectClass(third);
    jmethodID constructor = env->GetMethodID(personClass, "<init>", "(ILjava/lang/String;)V");
    jfieldID ageField = env->GetFieldID(personClass, "age", "I");
    jfieldID nameField = env->GetFieldID(personClass, "name", "Ljava/lang/String;");
    jstring name = (jstring)env->GetObjectField(third, nameField);
    string nativeName = string(env->GetStringUTFChars(name, nullptr)) + "신";
    jint age = env->GetIntField(third, ageField);
    jobject newPerson = env->NewObject(personClass, constructor, age, env->NewStringUTF(nativeName.c_str()));
    return newPerson;
}