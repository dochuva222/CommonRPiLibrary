// CommonRPiLibrary.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef COMMON_RPI_LIBRARY_H
#define COMMON_RPI_LIBRARY_H

extern "C"
{
	void RP_ReadWriteSPI(unsigned char[], unsigned int);
	void RP_ReadWriteUSB(unsigned char[], unsigned int);
}

#endif // COMMON_RPI_LIBRARY_H