// CommonRPiLibrary.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef COMMON_RPI_LIBRARY_H
#define COMMON_RPI_LIBRARY_H

#include <stdint.h>
#include "SPI.h"
#include "USB.h"

void StopUSB();
void StopSPI();
void StartSPI();
void StartUSB();

unsigned char* ReadWriteSPI(unsigned char* data, unsigned int len);
unsigned char* ReadWriteUSB(unsigned char* data, unsigned int len);

#endif // COMMON_RPI_LIBRARY_H
