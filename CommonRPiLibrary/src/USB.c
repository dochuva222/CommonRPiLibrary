#include <asm/termbits.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>

#include "USB.h"

bool Init_PiSerial(int baud_)
{
    handle = -1;
    struct termios tio;
    struct termios2 tio2;
    baud = baud_;
    handle = open("/dev/ttyACM0", O_RDWR | O_NOCTTY /* | O_NONBLOCK */);

    if (handle < 0)
        return false;
    tio.c_cflag = CS8 | CLOCAL | CREAD;
    tio.c_oflag = 0;
    tio.c_lflag = 0;       //ICANON;
    tio.c_cc[VMIN] = 0;
    tio.c_cc[VTIME] = 1;     // time out every .1 sec
    ioctl(handle, TCSETS, &tio);

    ioctl(handle, TCGETS2, &tio2);
    tio2.c_cflag &= ~CBAUD;
    tio2.c_cflag |= BOTHER;
    tio2.c_ispeed = baud;
    tio2.c_ospeed = baud;
    ioctl(handle, TCSETS2, &tio2);

    //   flush buffer
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
    return(rlen == len);
}

int PiSerial_Receive(unsigned char* data, int len)
{
    // this is a blocking receives
    int lenRCV = 0;
    while (lenRCV < len)
    {
        int rlen = read(handle, &data[lenRCV], len - lenRCV);
        lenRCV += rlen;
    }
    return lenRCV;
}
