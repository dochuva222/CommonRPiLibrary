#include "CommonRPiLibrary.h"
#include "CCommonRPiLibrary"

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


void RP_ReadWriteSPI(unsigned char buf[], unsigned int cnt)
{
	Create();
	lib->ReadWriteSPI(buf, cnt);
}

void RP_ReadWriteUSB(unsigned char buf[], unsigned int cnt)
{
	Create();
	lib->ReadWriteUSB(buf, cnt);
}