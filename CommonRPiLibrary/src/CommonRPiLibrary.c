// CommonRPiLibrary.cpp: определяет точку входа для приложения.
//

#include "CommonRPiLibrary.h"

void StopUSB()
{
	Kill_PiSerial();
}

void StopSPI()
{
	Kill_PiSPI();
}

void StartSPI(const char* path, int channel, int speed, int mode)
{
	Init_PiSPI(path, channel, speed, mode);
}

void StartUSB(const char* path, int baud)
{
	Init_PiSerial(path, baud);
}

unsigned char* ReadWriteSPI(unsigned char* data, unsigned int len)
{
	PiSPI_SyncReadWrite(data, len);
	return data;
}

unsigned char* ReadWriteUSB(unsigned char* data, unsigned int len)
{
	PiSerial_Send(data, len);
	PiSerial_Receive(data, len);
	return data;
}
