// CommonRPiLibrary.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include "SPI.h"
#include "USB.h"

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.

using namespace std;

class CommonRPiLibrary
{
	//Constructor / Destructor
	//Constructor - Sets up the SPI Port and opens it. Singleton due to HW.
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