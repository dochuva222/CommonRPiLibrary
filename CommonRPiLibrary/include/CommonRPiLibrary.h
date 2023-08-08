// CommonRPiLibrary.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef COMMON_RPI_LIBRARY_H
#define COMMON_RPI_LIBRARY_H

//#ifdef __cplusplus
extern "C"
{
//#endif

	void RP_ReadWriteSPI(unsigned char[], unsigned int);
	void RP_ReadWriteUSB(unsigned char[], unsigned int);

//#ifdef __cplusplus
}
//#endif

#endif // COMMON_RPI_LIBRARY_H