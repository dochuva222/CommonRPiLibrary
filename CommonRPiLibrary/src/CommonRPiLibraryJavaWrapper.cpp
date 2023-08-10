#include "CommonRPiLibrary.h"
#include <stdlib.h>
#include <jni.h>

extern "C"
{
static const char *JNIT_CLASS = "JavaWrapper";

static jbyteArray Java_RP_ReadWriteSPI(JNIEnv *env, jobject obj, jbyteArray data, jint length)
{
	jbyte *dataArray = env->GetByteArrayElements(data, NULL);
	if (dataArray == NULL)
	{
		return NULL;
	}

	unsigned char *resultArray = RP_ReadWriteSPI((unsigned char *)dataArray, (unsigned int)length);
	// (*env)-ReleaseByteArrayElements(env, data, dataArray, 0);

	jbyteArray resultByteArray = env->NewByteArray(length);
	if (resultByteArray != NULL)
	{
		env->SetByteArrayRegion(resultByteArray, 0, length, (jbyte *)resultArray);
	}
	return resultByteArray;
}

static jbyteArray Java_RP_ReadWriteUSB(JNIEnv *env, jobject obj, jbyteArray data, jint length)
{
        jbyte *dataArray = env->GetByteArrayElements(data, NULL);
        if (dataArray == NULL) 
        {
                return NULL;
        }

        unsigned char *resultArray = RP_ReadWriteUSB((unsigned char *)dataArray, (unsigned int)length);
        // (*env)-ReleaseByteArrayElements(env, data, dataArray, 0);

        jbyteArray resultByteArray = env->NewByteArray(length);
        if (resultByteArray != NULL)
        {
                env->SetByteArrayRegion(resultByteArray, 0, length, (jbyte *)resultArray);
        }
        return resultByteArray;
}

static JNINativeMethod funcs[] = {
	{ "Java_RP_ReadWriteSPI", "([BI)[B", (void *)&c_destroy },
	{ "Java_RP_ReadWriteUSB", "([BI)[B", (void *)&c_add }
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
	JNIEnv *env;
	jclass  cls;
	jint    res;

	(void)reserved;

	if ((*vm)->GetEnv(vm, (void **)&env, JNI_VERSION_1_8) != JNI_OK)
		return -1;

	cls = (*env)->FindClass(env, JNIT_CLASS);
	if (cls == NULL)
		return -1;

	res = (*env)->RegisterNatives(env, cls, funcs, sizeof(funcs)/sizeof(*funcs));
	if (res != 0)
		return -1;

	return JNI_VERSION_1_8;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{
	JNIEnv *env;
	jclass  cls;

	(void)reserved;

	if ((*vm)->GetEnv(vm, (void **)&env, JNI_VERSION_1_8) != JNI_OK)
		return;

	cls = (*env)->FindClass(env, JNIT_CLASS);
	if (cls == NULL)
		return;

	(*env)->UnregisterNatives(env, cls);
}
}
