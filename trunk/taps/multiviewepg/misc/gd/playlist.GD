#include "type.h"
byte _playlistCpm[] = 
{
0x00,0x08,0x1b,0x90,0xff,0xff,0x00,0x01,0x00,0x01,0x00,0xd8,0x76,0x32,0xff,0xff,
0x02,0x80,0x00,0x9c,0x52,0x43,0x0d,0x39,0x6d,0x39,0x3b,0x27,0x39,0xd5,0xf3,0x7d,
0x4e,0xac,0xa4,0xa5,0x31,0x21,0x90,0x90,0x90,0x90,0xa0,0xc8,0x65,0x72,0x12,0x12,
0x12,0x30,0x64,0x3c,0xa6,0x82,0x42,0x83,0x29,0xd5,0xe8,0x4a,0x5c,0x24,0x25,0x3d,
0xb8,0x63,0x18,0xc7,0xfc,0xcc,0x76,0xbf,0xb8,0xc0,0x91,0x36,0xe3,0x5f,0xf2,0x46,
0xc0,0xef,0xc5,0x23,0x69,0x03,0x34,0x14,0x0c,0x25,0x1b,0xc4,0xc8,0xbc,0x96,0x89,
0xdc,0x6f,0x06,0xfa,0x07,0x2b,0xe7,0x0a,0x4d,0x3d,0x77,0xfb,0x1f,0xa4,0xe0,0x09,
0x51,0xb7,0x08,0xb0,0x8b,0x51,0x29,0x67,0xcd,0x1d,0x75,0x42,0x37,0x91,0xac,0xd6,
0xed,0xd0,0xd4,0xa9,0x8f,0xa8,0x93,0x00,0x8b,0x34,0x87,0xf1,0xbe,0x61,0x13,0x03,
0xef,0x13,0x95,0x41,0xcd,0x6a,0x1e,0x7d,0x76,0x50,0x73,0xc9,0xa8,0xd7,0x8c,0x78,
0xc6,0xb8,0xfd,0x21,0xe8,0x1c,0xd0,0x25,0x9f,0xdb,0x81,0xfa,0xd8,0xcf,0x9c,0x00,
0x76,0xca,0xd4,0x1d,0x8c,0xfb,0x2b,0x03,0xad,0x34,0x87,0xc9,0xa9,0x5d,0x15,0x4d,
0x17,0x09,0x4f,0x63,0xe5,0xe2,0x9a,0x36,0xc5,0x54,0x27,0xb1,0xfe,0x44,0xbe,0x12,
0x8b,0x3b,0x9c,0x5f,0x7d,0xce,0x13,0x22,0x64,0x1b,0xe6,0x83,0xef,0x81,0xe4,0x6c,
0xeb,0xf7,0x94,0x40,
};


TYPE_GrData _playlistGd =
{
	1,		//version
	0,		//reserved
	OSD_1555,		//data format
	COMPRESS_Tfp,		//compressed method
	_playlistCpm,		//data
	640,		//size
	20,		//width
	16		//height
};
