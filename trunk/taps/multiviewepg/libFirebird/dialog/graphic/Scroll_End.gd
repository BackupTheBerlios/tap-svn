#include "type.h"

byte _Scroll_End_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x21, 0x6C, 0xA3, 0xFF, 0xFF, 0x00, 0x78, 
  0x00, 0x0B, 0x3A, 0x69, 0x6D, 0xCF, 0x12, 0x37, 0x45, 0xBD, 0x1D, 0x68, 0x9E, 0x45, 0x91, 0x83, 
  0x06, 0x42, 0xBD, 0x91, 0x00, 0x22, 0x4B, 0x03, 0xB5, 0xBF, 0x3A, 
};

TYPE_GrData _Scroll_End_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Scroll_End_Cpm,                //data
   120,                           //size
    10,                           //width
     6                            //height
};

