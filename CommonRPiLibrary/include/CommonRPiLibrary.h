// CommonRPiLibrary.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef COMMON_RPI_LIBRARY_H
#define COMMON_RPI_LIBRARY_H

void StopUSB();
void StopSPI();
void StartSPI();
void StartUSB();

unsigned char* ReadWriteSPI(unsigned char*, unsigned int);
unsigned char* ReadWriteUSB(unsigned char*, unsigned int);

#endif // COMMON_RPI_LIBRARY_H