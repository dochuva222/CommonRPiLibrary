// CommonRPiLibrary.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef COMMON_RPI_LIBRARY_H
#define COMMON_RPI_LIBRARY_H

#include <stdint.h>

void StopUSB();
void StopSPI();
void StartSPI(const char* path, int channel, int speed, int mode);
void StartUSB(const char* path, int baud);

unsigned char* ReadWriteSPI(unsigned char* data, unsigned int len);
unsigned char* ReadWriteUSB(unsigned char* data, unsigned int len);

#endif // COMMON_RPI_LIBRARY_H
