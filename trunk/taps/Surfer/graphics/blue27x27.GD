#include "type.h"
byte _blue27x27Cpm[] = 
{
0x00,0x08,0x1b,0x90,0xff,0xff,0x00,0x01,0x00,0x01,0x01,0x01,0x6e,0x24,0xff,0xff,
0x05,0xb2,0x00,0xb2,0x5c,0x72,0x82,0x26,0xbf,0xce,0x23,0x04,0xca,0x5b,0xe0,0x21,
0x7c,0x0f,0x05,0xd0,0x59,0xa0,0xb3,0x41,0x67,0x40,0xb0,0x18,0x0c,0x0b,0x11,0x87,
0x63,0x30,0x19,0x0e,0x84,0x6c,0x47,0x40,0x9d,0xff,0xff,0x9e,0xdc,0x1c,0x61,0x89,
0x4a,0xe6,0x5b,0x01,0xd0,0xeb,0xa9,0x4b,0x96,0x01,0x71,0x71,0xdd,0xd9,0xd7,0x9f,
0xfc,0x1d,0xc2,0x30,0x90,0xa1,0x50,0xd6,0x35,0x08,0x3f,0x93,0x8c,0x78,0x3b,0x2c,
0x15,0x96,0xe9,0x1a,0x7a,0x27,0x39,0x37,0xc5,0xd8,0xd5,0xea,0x14,0x08,0xff,0x53,
0x91,0xa7,0xec,0xb7,0x05,0x69,0x3a,0xa7,0x46,0x7b,0x3d,0x92,0x7d,0xbb,0xbd,0xf7,
0xed,0xdd,0x84,0xaf,0x58,0xef,0x1d,0xb9,0xed,0x12,0xaf,0xa6,0xff,0x8b,0x7d,0xaf,
0x72,0xaa,0x62,0xb3,0x95,0x61,0xc5,0x5a,0x1a,0xaf,0x95,0xde,0xb7,0x79,0xdf,0xc2,
0x86,0xa4,0x4c,0x25,0xfc,0xa2,0x64,0x3f,0xba,0x12,0xb4,0xdb,0xa7,0xe4,0x1a,0xb1,
0x55,0x46,0x3b,0xf5,0x5d,0x5b,0xb4,0xe6,0x29,0xc7,0x92,0xa9,0x24,0xd8,0xcc,0xad,
0xe9,0xa4,0xed,0x39,0x56,0x98,0x8b,0x15,0x50,0x63,0xaa,0x61,0xea,0x65,0x6f,0x6c,
0x9e,0x53,0x29,0x41,0x56,0x1c,0xab,0xcd,0x24,0xda,0x9c,0x8a,0x78,0x26,0x8e,0x5e,
0x2c,0x9f,0xae,0x86,0x62,0xd1,0x9d,0xc9,0xaf,0x4e,0xe5,0x29,0x7d,0xb3,0x59,0xff,
0x28,0xae,0x4a,0x8e,0x3e,0x0c,0xbd,0x7d,0x06,0x42,0xb4,0x5b,0x25,0x47,0x39,0x3b,
0xd7,0x80,0x42,0x34,0xb1,0x18,0x8f,0x4c,0x1d,0x7f,0x0e,0x79,0xf0,
};


TYPE_GrData _blue27x27Gd =
{
	1,		//version
	0,		//reserved
	OSD_1555,		//data format
	COMPRESS_Tfp,		//compressed method
	_blue27x27Cpm,		//data
	1458,		//size
	27,		//width
	27		//height
};
