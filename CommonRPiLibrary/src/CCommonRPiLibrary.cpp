// CommonRPiLibrary.cpp: определяет точку входа для приложения.
//

#include "CCommonRPiLibrary.h"

CCommonRPiLibrary::CCommonRPiLibrary() :
	spi(0), usb(0)
{

}

CCommonRPiLibrary::~CCommonRPiLibrary()
{
	if (spi != 0)
		spi->~PiSPI();

	if (usb != 0)
		usb->~PiSerial();
}

void CCommonRPiLibrary::StartSPI()
{
	spi = new PiSPI(2, 1000000, 0);
}

void CCommonRPiLibrary::StartUSB()
{
	usb = new PiSerial("/dev/ttyACM0", 115200);
}

void CCommonRPiLibrary::ReadWriteSPI(uint8_t* data, uint8_t len)
{
	spi->SyncReadWrite(data, len);
}

void CCommonRPiLibrary::ReadWriteUSB(uint8_t* data, uint8_t len)
{
	usb->Send(data, len);
	usb->Receive(data, len);
}
