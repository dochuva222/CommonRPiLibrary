// CommonRPiLibrary.cpp: определяет точку входа для приложения.
//

#include "CommonRPiLibrary.h"

#ifdef __cplusplus
extern "C" {
#endif

CommonRPiLibrary::CommonRPiLibrary()
{
	
}

CommonRPiLibrary::~CommonRPiLibrary()
{
	spi->~PiSPI();
	usb->~PiSerial();
}

void CommonRPiLibrary::StartSPI()
{
	spi = new PiSPI(2, 1000000, 0);
}

void CommonRPiLibrary::StartUSB()
{
	usb = new PiSerial("/dev/ttyACM0", 115200);
}

void CommonRPiLibrary::ReadWriteSPI(uint8_t* data, uint8_t len)
{
	spi->SyncReadWrite(data, len);
}

void CommonRPiLibrary::ReadWriteUSB(uint8_t* data, uint8_t len)
{
	usb->Send(data, len);
	usb->Receive(data, len);
}

#ifdef __cplusplus
}
#endif