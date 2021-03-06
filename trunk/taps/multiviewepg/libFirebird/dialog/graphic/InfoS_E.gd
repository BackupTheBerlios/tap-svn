#include "type.h"

byte _InfoS_E_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x22, 0x6B, 0x76, 0xFF, 0xFF, 0x06, 0x3C, 
  0x00, 0x0C, 0x38, 0x04, 0x61, 0xAF, 0xF4, 0x54, 0x41, 0x2F, 0x03, 0xA0, 0x0A, 0x02, 0x60, 0xBE, 
  0x15, 0x74, 0x14, 0x00, 0x01, 0x4B, 0xDA, 0xB1, 0xDA, 0x20, 0x07, 0x80, 
};

TYPE_GrData _InfoS_E_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _InfoS_E_Cpm,                   //data
  1596,                           //size
    42,                           //width
    19                            //height
};

