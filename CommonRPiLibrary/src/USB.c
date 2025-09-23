#include <asm/termbits.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>

#include "USB.h"

int handle;
int baud;

bool Init_PiSerial(const char* path, int baud_)
{
    handle = -1;
    struct termios tio;
    baud = baud_;
    handle = open(path, O_RDWR | O_NOCTTY | O_NONBLOCK);

    if (handle < 0)
        return false;
    tio.c_cflag = CS8 | CLOCAL | CREAD;
    tio.c_oflag &= ~(OPOST | ONLCR | OCRNL);
    tio.c_iflag &= ~(INLCR | IGNCR | ICRNL | IGNBRK | IUCLC | PARMRK);
    tio.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ISIG | IEXTEN | ECHOCTL | ECHOKE);

    tio.c_cflag &= ~(CSTOPB); // stopbit one
    tio.c_iflag &= ~(INPCK | ISTRIP);
    tio.c_cflag &= ~(PARENB | PARODD | CMSPAR); // parity none
    
    tio.c_cc[VMIN] = 0;
    tio.c_cc[VTIME] = 0;
    ioctl(handle, TCSETS, &tio);
    
    // flush buffer
    ioctl(handle, TCFLSH, TCIOFLUSH);

    return true;
}

void Kill_PiSerial()
{
    if (handle >= 0)
        close(handle);
    handle = -1;
}

bool PiSerial_Send(unsigned char* data, int len)
{
    int rlen = write(handle, data, len);
    ioctl(handle, TCFLSH, TCOFLUSH);
    return(rlen == len);
}

int PiSerial_Receive(unsigned char* data, int len)
{
    int lenRCV = 0;
    while (lenRCV < len)
    {
        int rlen = read(handle, &data[lenRCV], len - lenRCV);
        lenRCV += rlen;
    }
    ioctl(handle, TCFLSH, TCIFLUSH);
    return lenRCV;
}
