#include "type.h"

byte _Border_N_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x2E, 0x9E, 0x8C, 0xFF, 0xFF, 0x03, 0xD4, 
  0x00, 0x12, 0x44, 0x4A, 0x89, 0xFF, 0xB1, 0x99, 0x0A, 0x49, 0x3B, 0x21, 0x19, 0x03, 0xC2, 0xC4, 
  0x42, 0x40, 0x46, 0x7F, 0x1F, 0x20, 0x09, 0x21, 0xC8, 0x2B, 0x23, 0x9F, 0x22, 0x6B, 0x12, 0xC3, 
  0x1E, 0xFD, 0xD0, 0x57, 0xB7, 0xE1, 0x16, 0x80, 
};

TYPE_GrData _Border_N_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Border_N_Cpm,                  //data
   980,                           //size
    10,                           //width
    49                            //height
};

