#include "type.h"

byte _MsgBox_E_SubTitle_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x75, 0xFE, 0x66, 0xFF, 0xFF, 0x09, 0x12, 
  0x00, 0x41, 0x4D, 0x52, 0xD9, 0x9F, 0xF2, 0x44, 0x89, 0x1C, 0x0C, 0x70, 0x13, 0x70, 0x11, 0x23, 
  0x80, 0x89, 0x12, 0x68, 0x54, 0x68, 0x10, 0x7F, 0x02, 0x04, 0x29, 0x34, 0x1A, 0x04, 0x1F, 0xC0, 
  0x81, 0x0A, 0x0D, 0x22, 0x44, 0x88, 0x10, 0x3C, 0x95, 0xBD, 0x9B, 0xCE, 0x00, 0xBC, 0xE1, 0x6B, 
  0x8E, 0xBF, 0x4B, 0x42, 0x00, 0x44, 0xDB, 0xBC, 0xD9, 0x8C, 0x99, 0x44, 0x5D, 0x68, 0x2B, 0x9C, 
  0xA6, 0x4B, 0x47, 0xAA, 0xE2, 0x7F, 0x2A, 0x65, 0x7C, 0x81, 0x50, 0xA8, 0x54, 0x2A, 0x15, 0x0A, 
  0xF8, 0xAD, 0xDA, 0x0F, 0xAF, 0xFA, 0xB8, 0x54, 0xF5, 0x72, 0xD5, 0xF2, 0xD0, 0x4A, 0x54, 0xEE, 
  0x56, 0xD6, 0x42, 0xB2, 0x94, 0xB5, 0xCA, 0xD7, 0x1F, 0x12, 0x5B, 0xBF, 0x3C, 0xCE, 0x54, 
};

TYPE_GrData _MsgBox_E_SubTitle_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _MsgBox_E_SubTitle_Cpm,         //data
  2322,                           //size
    27,                           //width
    43                            //height
};

