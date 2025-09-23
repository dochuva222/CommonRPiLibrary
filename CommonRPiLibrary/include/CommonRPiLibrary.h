// CommonRPiLibrary.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef COMMON_RPI_LIBRARY_H
#define COMMON_RPI_LIBRARY_H

#include <stdint.h>
#include "SPI.h"
#include "USB.h"

void StopUSB();
void StopSPI();
int StartSPI(const char* path, int channel, int speed, int mode);
int StartUSB(const char* path, int baud);

unsigned char* ReadWriteSPI(unsigned char* data, unsigned int len);
unsigned char* ReadWriteUSB(unsigned char* data, unsigned int len);

#endif // COMMON_RPI_LIBRARY_H
