#ifndef USB_H
#define USB_H

#include <string>

class PiSerial
{
public:
	int handle;
	std::string  deviceName;
	int baud;

	PiSerial(std::string deviceName, int baud);
	~PiSerial();

	bool Send(unsigned char* data, int len);
	bool Send(unsigned char value);
	bool Send(std::string value);
	int Receive(unsigned char* data, int len);
	bool IsOpen(void);
	void Close(void);
	bool Open(std::string deviceName, int baud);
	bool NumberByteRcv(int& bytelen);
};


#endif // USB_H