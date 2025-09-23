#ifndef USB_H
#define USB_H

#include <string.h>
#include <stdbool.h>
#include <stddef.h>

extern int handle;
extern int baud;

bool Init_PiSerial(const char* path, int baud);
void Kill_PiSerial();

bool PiSerial_Send(unsigned char* data, int len);
int PiSerial_Receive(unsigned char* data, int len);


#endif // USB_H
