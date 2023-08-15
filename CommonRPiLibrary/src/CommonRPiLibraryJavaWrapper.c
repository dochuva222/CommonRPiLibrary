#include "CommonRPiLibrary.h"
#include <stdlib.h>
#include <jni.h>

static const char *JNIT_CLASS = "io/github/crackanddie/jni/JavaWrapper";

static jbyteArray Java_ReadWriteSPI(JNIEnv *env, jobject obj, jbyteArray data, jint length)
{
	jbyte *dataArray = (*env)->GetByteArrayElements(env, data, NULL);
	if (dataArray == NULL)
	{
		return NULL;
	}

	unsigned char *resultArray = ReadWriteSPI((unsigned char *)dataArray, (unsigned int)length);
	// (*env)-ReleaseByteArrayElements(env, data, dataArray, 0);

	jbyteArray resultByteArray = (*env)->NewByteArray(env, length);
	if (resultByteArray != NULL)
	{
		(*env)->SetByteArrayRegion(env, resultByteArray, 0, length, (jbyte *)resultArray);
	}
	return resultByteArray;
}

static jbyteArray Java_ReadWriteUSB(JNIEnv *env, jobject obj, jbyteArray data, jint length)
{
    jbyte *dataArray = (*env)->GetByteArrayElements(env, data, NULL);
    if (dataArray == NULL) 
    {
            return NULL;
    }

    unsigned char *resultArray = ReadWriteUSB((unsigned char *)dataArray, (unsigned int)length);
    // (*env)-ReleaseByteArrayElements(env, data, dataArray, 0);

    jbyteArray resultByteArray = (*env)->NewByteArray(env, length);
    if (resultByteArray != NULL)
    {
		(*env)->SetByteArrayRegion(env, resultByteArray, 0, length, (jbyte *)resultArray);
    }
    return resultByteArray;
}

static void Java_StartSPI(JNIEnv *env, jobject obj)
{
	(void)env;
	(void)obj;
	StartSPI();
}

static void Java_StartUSB(JNIEnv *env, jobject obj)
{
	(void)env;
	(void)obj;
	StartUSB();
}

static void Java_StopSPI(JNIEnv *env, jobject obj)
{
	(void)env;
	(void)obj;
	StopSPI();
}

static void Java_StopUSB(JNIEnv *env, jobject obj)
{
	(void)env;
	(void)obj;
	StopUSB();
}

static JNINativeMethod funcs[] = {
	{ "Java_ReadWriteSPI", "([BI)[B", (void *)&Java_ReadWriteSPI },
	{ "Java_ReadWriteUSB", "([BI)[B", (void *)&Java_ReadWriteUSB },
	{ "Java_StartSPI", "()V", (void *)&Java_StartSPI },
	{ "Java_StartUSB", "()V", (void *)&Java_StartUSB },
	{ "Java_StopSPI", "()V", (void *)&Java_StopSPI },
	{ "Java_StopUSB", "()V", (void *)&Java_StopUSB }
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

