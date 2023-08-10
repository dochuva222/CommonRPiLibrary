#ifndef USB_H
#define USB_H

#include <string>

int handle;
std::string deviceName;
int baud;

void Init_PiSerial(std::string deviceName, int baud);
void Kill_PiSerial();

bool PiSerial_Send(unsigned char* data, int len);
int PiSerial_Receive(unsigned char* data, int len);


#endif // USB_H