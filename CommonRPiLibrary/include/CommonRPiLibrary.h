// CommonRPiLibrary.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef COMMON_RPI_LIBRARY_H
#define COMMON_RPI_LIBRARY_H

#include <iostream>
#include "SPI.h"
#include "USB.h"

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

class CommonRPiLibrary
{
public:
	CommonRPiLibrary();
	~CommonRPiLibrary();

	//Methods
public:
	void StartSPI();
	void StartUSB();
	void ReadWriteSPI(uint8_t* data, uint8_t len);
	void ReadWriteUSB(uint8_t* data, uint8_t len);

private:
	PiSPI* spi;
	PiSerial* usb;
};

#ifdef __cplusplus
}
#endif

#endif // COMMON_RPI_LIBRARY_H