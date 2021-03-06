#pragma once

typedef unsigned int uint;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

int crc16(u16 *crc, u8 *buf, uint len);
int unlh5(u8 *srcpt, uint srcln, u8 *dstpt, uint dstln);

#define SWAPWORD(x) (MAKEWORD(HIBYTE(x), LOBYTE(x)))
#define SWAPDWORD(x) ((SWAPWORD(x>>16)) + (SWAPWORD(x&0xFFFF)<<16))
