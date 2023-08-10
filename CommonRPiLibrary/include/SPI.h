#ifndef SPI_H
#define SPI_H

// Includes
#include <stdint.h>
#include <stdbool.h>
#include <linux/spi/spidev.h>
#include <stddef.h>

void Init_PiSPI(uint8_t channel, int speed, int mode);
void Kill_PiSPI();

bool PiSPI_SetMode(int mode);
bool PiSPI_SetBitsPerWord(uint8_t bpw);
bool PiSPI_SetSpeed(int speed);
bool PiSPI_SyncReadWrite(uint8_t* pData, size_t length);

uint8_t  _u8Channel;
int _iSpeed;
uint8_t _iBitsPerWord;
int _iMode;
int _iFD;


#endif //SPI_H

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
