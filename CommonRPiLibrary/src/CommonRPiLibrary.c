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

void StartSPI()
{
	Init_PiSPI(2, 1000000, 0);
}

void StartUSB()
{
	Init_PiSerial(115200);
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
