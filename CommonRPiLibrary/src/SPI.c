#include "SPI.h"
#include <cstdio>
#include <string.h>
#include <string>
#include <ios>
#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <unistd.h>

mutex PiSPI::mutexSPI[3];

void Init_PiSPI(uint8_t channel, int speed, int mode, uint8_t bitsperword)
{
	char device[16] = "";
	_u8Channel = channel;
	_iFD = 0;

	snprintf(device, sizeof(device), "/dev/spidev1.%d", channel);
	_iFD = open(device, O_RDWR);

	if (_iFD < 0)
		throw ios_base::failure(string("Could not open device!"));

	if (!SetMode(mode))
		throw ios_base::failure(string("Could set SPI mode!"));

	if (!SetBitsPerWord(bitsperword))
		throw ios_base::failure(string("Could set SPI bits per word!"));

	if (!SetSpeed(speed))
		throw ios_base::failure(string("Could set SPI speed!"));
}

void Kill_PiSPI()
{
	close(_iFD);
}

bool PiSPI_SetBitsPerWord(uint8_t bpw)
{
	int retVal = 0;
	if ((retVal = ioctl(_iFD, SPI_IOC_WR_BITS_PER_WORD, &bpw)) != -1)
	{
		_iBitsPerWord = bpw;
		return true;
	}
	return false;
}

bool PiSPI_SetSpeed(int speed)
{
	int retVal = 0;
	if ((retVal = ioctl(_iFD, SPI_IOC_WR_MAX_SPEED_HZ, &speed)) != -1)
	{
		_iSpeed = speed;
		return true;
	}
	return false;
}

bool PiSPI_SetMode(int mode)
{
	int retVal = 0;
	if ((retVal = ioctl(_iFD, SPI_IOC_WR_MODE, &mode)) != -1)
	{
		_iMode = mode;
		return true;
	}
	return false;
}

bool PiSPI_SyncReadWrite(uint8_t* pData, size_t length)
{
	struct spi_ioc_transfer spi = { 0 };
	int retVal = 0;

	if (pData == NULL)
		return false;

	spi.tx_buf = (unsigned long)pData;
	spi.rx_buf = (unsigned long)pData;
	spi.len = length;
	spi.cs_change = 0;

	PiSPI::mutexSPI[_u8Channel].lock();
	retVal = ioctl(_iFD, SPI_IOC_MESSAGE(1), &spi);
	PiSPI::mutexSPI[_u8Channel].unlock();
	return retVal != -1;
}



/*
Copyright (c) 2018 Tobias Eiseler

This file is part of LibPiSPI.

Foobar is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/
