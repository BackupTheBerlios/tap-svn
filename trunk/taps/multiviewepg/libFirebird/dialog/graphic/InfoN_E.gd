#include "type.h"

byte _InfoN_E_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x56, 0x97, 0x95, 0xFF, 0xFF, 0x00, 0xF0, 
  0x00, 0x38, 0x4C, 0x53, 0x49, 0xC7, 0x37, 0x80, 0xDF, 0x06, 0x5E, 0x04, 0xC2, 0x3E, 0x04, 0x84, 
  0xBC, 0x09, 0x84, 0xBC, 0x09, 0x09, 0x89, 0xC0, 0x40, 0x60, 0x11, 0x10, 0x50, 0x20, 0x10, 0x20, 
  0x20, 0x11, 0x90, 0x31, 0xF9, 0xEA, 0x19, 0x00, 0x04, 0xFC, 0xE7, 0xE2, 0x07, 0x1F, 0xEF, 0x7A, 
  0x75, 0xE7, 0x79, 0x95, 0xA2, 0x3A, 0x02, 0x01, 0xB1, 0xB1, 0x5B, 0x7C, 0xF5, 0x17, 0x62, 0x46, 
  0xCA, 0x31, 0x1F, 0x55, 0x76, 0x69, 0x89, 0x66, 0x91, 0x1D, 0xBB, 0x76, 0xAA, 0xA3, 0xB8, 0xE0, 
};

TYPE_GrData _InfoN_E_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _InfoN_E_Cpm,                   //data
   240,                           //size
    20,                           //width
     6                            //height
};
