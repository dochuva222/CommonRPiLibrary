#ifndef CCOMMON_RPI_LIBRARY_H
#define CCOMMON_RPI_LIBRARY_H

#include "SPI.h"
#include "USB.h"

class CCommonRPiLibrary
{
public:
	CCommonRPiLibrary();
	~CCommonRPiLibrary();

	void StartSPI();
	void StartUSB();
	void ReadWriteSPI(uint8_t*, uint8_t);
	void ReadWriteUSB(uint8_t*, uint8_t);

private:
	PiSPI* spi;
	PiSerial* usb;
};

#endif // COMMON_RPI_LIBRARY_H