#include "CommonRPiLibrary.h"
#include "CCommonRPiLibrary.h"

CCommonRPiLibrary* lib = 0;

void Create()
{
	if (lib == 0)
	{
		lib = new CCommonRPiLibrary();
		lib->StartSPI();
		lib->StartUSB();
	}
}

unsigned char* RP_ReadWriteSPI(unsigned char* buf, unsigned int cnt)
{
	Create();
	lib->ReadWriteSPI(buf, cnt);
	return buf;
}

unsigned char* RP_ReadWriteUSB(unsigned char* buf, unsigned int cnt)
{
	Create();
	lib->ReadWriteUSB(buf, cnt);
	return buf;
}