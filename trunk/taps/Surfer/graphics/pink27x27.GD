#include "type.h"
byte _pink27x27Cpm[] = 
{
0x00,0x08,0x1b,0x90,0xff,0xff,0x00,0x01,0x00,0x01,0x01,0x30,0x42,0x9c,0xff,0xff,
0x05,0xb2,0x00,0xdf,0x5b,0x5b,0xd5,0x29,0xfe,0xed,0xd4,0x0b,0xaa,0x55,0x69,0xbc,
0xaf,0x96,0xef,0x81,0x77,0xc0,0xbb,0xe0,0x5c,0x2f,0x01,0x01,0x17,0x02,0x89,0x01,
0x01,0x00,0x80,0x80,0x80,0x80,0x81,0x01,0x00,0x80,0x81,0xed,0xa4,0x04,0x04,0x0f,
0x00,0x80,0x81,0x00,0xbb,0xb7,0xf7,0x97,0x3a,0xd6,0xe0,0x9c,0xef,0x68,0x0e,0x03,
0xb7,0x7c,0x1c,0xef,0x92,0x1c,0x07,0x5c,0x80,0x00,0x63,0x73,0xd3,0xff,0x3f,0x73,
0x6e,0x17,0xd3,0x20,0x8a,0x39,0x99,0x8f,0x3b,0xa8,0xec,0xc1,0xf6,0x9b,0xe9,0xf5,
0xd0,0x6d,0xa1,0xb9,0xda,0x28,0xe5,0x63,0x8e,0x4f,0xa4,0xe2,0x5b,0xae,0x8a,0x7d,
0x8d,0xa6,0x5e,0x66,0x64,0x5d,0xf4,0xfc,0xa7,0x02,0x95,0xa3,0xa7,0xba,0xb2,0xb1,
0x1e,0x7d,0xf8,0x8f,0x27,0xd7,0xd3,0xee,0xab,0xa5,0x3b,0xbb,0xf5,0x71,0xe7,0xe5,
0x97,0xdf,0xd4,0xf2,0x8f,0x65,0x7a,0x7c,0x69,0xab,0x59,0x95,0x0a,0x27,0x22,0xf1,
0x2d,0xcb,0x2b,0x88,0x5c,0xac,0x8b,0xd6,0xae,0xaa,0xb5,0x53,0xae,0xda,0x1a,0x41,
0x73,0xcd,0x0a,0xb7,0xd1,0x39,0xda,0xf9,0xa1,0x20,0x99,0xa1,0xf8,0x14,0x75,0x1b,
0x95,0x28,0xe8,0x6f,0xc5,0x75,0x34,0xa7,0xcf,0x34,0x0a,0x3e,0x9d,0xea,0x90,0x53,
0xb5,0x43,0x61,0xb3,0xb5,0x62,0x64,0x14,0x4b,0x42,0xa8,0x27,0xc3,0x1d,0xca,0xbc,
0x91,0x46,0x51,0x81,0xe0,0x89,0xa1,0xb0,0x94,0x60,0x51,0xe4,0x9d,0x46,0xfa,0x1b,
0xb7,0x0c,0xac,0x4c,0xc8,0x68,0x22,0x41,0x5a,0x98,0x2a,0x7f,0x2c,0xba,0x8c,0x8b,
0x86,0x82,0x31,0x2c,0x64,0xc2,0x1d,0x3f,0x53,0x65,0xb3,0x03,0xed,0x44,0x3a,0x57,
0x92,0x3f,0x86,0x6c,0xcd,0xf8,0xa1,0x54,0x11,0x37,0x4b,0xe6,0x51,0xf1,0x9b,0x30,
0x38,0x87,0x1c,0x80,0x8f,0x0c,0x6e,0x21,0xf9,0xf2,0x9f,0xec,
};


TYPE_GrData _pink27x27Gd =
{
	1,		//version
	0,		//reserved
	OSD_1555,		//data format
	COMPRESS_Tfp,		//compressed method
	_pink27x27Cpm,		//data
	1458,		//size
	27,		//width
	27		//height
};
