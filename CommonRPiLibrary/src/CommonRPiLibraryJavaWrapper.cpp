#include "CommonRPiLibraryJavaWrapper.h"
#include "CommonRPiLibrary.h"

JNIEXPORT jbyteArray JNICALL Java_RP_ReadWriteSPI(JNIEnv *env, jobject obj, jbyteArray data, jint length)
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

JNIEXPORT jbyteArray JNICALL Java_RP_ReadWriteUSB(JNIEnv *env, jobject obj, jbyteArray data, jint length)
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


