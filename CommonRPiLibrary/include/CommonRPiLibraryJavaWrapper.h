#ifndef COMMON_RPI_LIBRARY_JAVA_WRAPPER_H
#define COMMON_RPI_LIBRARY_JAVA_WRAPPER_H

extern "C"
{
#include <jni.h>

JNIEXPORT jbyteArray JNICALL Java_RP_ReadWrite_SPI(JNIEnv *, jobject, jbyteArray, jint);
JNIEXPORT jbyteArray JNICALL Java_RP_ReadWrite_USB(JNIEnv *, jobject, jbyteArray, jint);
}
#endif
