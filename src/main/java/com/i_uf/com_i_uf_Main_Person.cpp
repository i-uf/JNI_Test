#include "com_i_uf_Main_Person.h"

#include <string>
#include <locale>
#include <Windows.h>

using namespace std;

jstring string_to_wstring(JNIEnv* env, const string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
    wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size_needed);
    const jchar* chars = reinterpret_cast<const jchar*>(wstr.c_str());
    return env->NewString(chars, wstr.length());
}
JNIEXPORT jstring JNICALL Java_com_i_1uf_Main_00024Person_getID(JNIEnv* env, jobject obj) {
    jclass personClass = env->GetObjectClass(obj);
    jfieldID ageField = env->GetFieldID(personClass, "age", "I");
    jfieldID nameField = env->GetFieldID(personClass, "name", "Ljava/lang/String;");
    jint age = env->GetIntField(obj, ageField);
    jstring name = (jstring)env->GetObjectField(obj, nameField);
    string nativeName = "[" + string(env->GetStringUTFChars(name, nullptr)) + ":" + to_string(age) + "]";
    return env->NewStringUTF(nativeName.c_str());
}