#include "type.h"

byte _key_voldown_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0x2C, 0xED, 0xEF, 0xFF, 0xFF, 0x03, 0x2A, 
  0x00, 0xF4, 0x5C, 0x43, 0x8D, 0x37, 0x26, 0xA2, 0x22, 0xE0, 0xE8, 0xA8, 0x9B, 0x17, 0x4D, 0x50, 
  0xE0, 0x8E, 0x12, 0x88, 0x89, 0x44, 0xA2, 0xB4, 0x36, 0xF7, 0x20, 0x40, 0x20, 0x08, 0x28, 0x08, 
  0x08, 0x0D, 0xEE, 0x40, 0x80, 0x20, 0x40, 0x70, 0x0D, 0xEE, 0x80, 0x20, 0x20, 0x40, 0x28, 0xA8, 
  0x08, 0x08, 0x10, 0x0C, 0x02, 0x24, 0x7F, 0x7E, 0x6B, 0xB7, 0x60, 0x75, 0xD8, 0x0C, 0x05, 0xE4, 
  0x4D, 0x71, 0x01, 0x22, 0x8E, 0x4D, 0x5E, 0xD4, 0x6A, 0x92, 0x4E, 0x8A, 0xD0, 0x42, 0xCB, 0x2E, 
  0xAE, 0xB4, 0x92, 0x2F, 0x7F, 0x45, 0x28, 0xFD, 0xCB, 0x0B, 0x61, 0x52, 0x48, 0xEE, 0xC9, 0x9D, 
  0xEF, 0x28, 0xE9, 0x22, 0x17, 0xDC, 0xA6, 0xB3, 0xF2, 0xA3, 0x8C, 0xEF, 0x83, 0x73, 0x54, 0xBD, 
  0xEA, 0x3F, 0xA7, 0x85, 0x35, 0xD1, 0xC6, 0xED, 0x98, 0x22, 0x88, 0x72, 0x3D, 0x63, 0xBF, 0xCF, 
  0x3B, 0xA2, 0x4E, 0xFC, 0xCE, 0x48, 0xD4, 0x0D, 0x84, 0x9E, 0x92, 0x62, 0xCF, 0x1C, 0x1A, 0xF7, 
  0x31, 0x89, 0x24, 0xEF, 0x80, 0x85, 0xB1, 0x95, 0xEE, 0x1B, 0x7F, 0x24, 0xCE, 0x1B, 0x9C, 0x3B, 
  0x42, 0x4F, 0x42, 0xC3, 0x79, 0x03, 0x04, 0x5D, 0xB0, 0x6C, 0xDB, 0xAF, 0x04, 0x7D, 0xB3, 0x76, 
  0x5F, 0x13, 0x55, 0x14, 0x1E, 0xED, 0x61, 0x1C, 0x55, 0x1D, 0x8C, 0x3F, 0x29, 0xDF, 0xA2, 0x16, 
  0x31, 0x47, 0xFF, 0x6B, 0x92, 0xDB, 0x0A, 0xC6, 0x06, 0x1D, 0xEF, 0x33, 0xAD, 0x06, 0x3F, 0xEB, 
  0x5C, 0xA1, 0x9C, 0x11, 0x6E, 0xB0, 0xBB, 0xFC, 0xD6, 0xC2, 0x8F, 0x05, 0xE7, 0xC0, 0xB6, 0xEB, 
  0x18, 0x9F, 0xB7, 0x05, 0x8B, 0x54, 0x2F, 0xE9, 0xA8, 0xEB, 0xF7, 0xBD, 0xF8, 0xCD, 0xD9, 0x7C, 
  0xA4, 0x68, 0xB2, 0xC3, 0xB6, 0x2E, 0x09, 0x20, 0xF2, 0x0C, 0xCE, 0x89, 0x4D, 0x6A, 0x3D, 0x35, 
  0xE5, 0x77, 0xE0, 0x73, 0x26, 0x61, 0xE1, 0xB8, 0xEE, 0x0D, 0xE4, 0x37, 0xBD, 0x01, 0x67, 0x03, 
  0x63, 0xE5, 0x38, 0xEE, 0x91, 0xA3, 0x73, 0x35, 0x5A, 0x11, 0x70, 0xCD, 0x98, 0x54, 0x0D, 0xE3, 
  0x15, 0xC1, 0xA0, 0x30, 0xD8, 0x50, 
};

TYPE_GrData _key_voldown_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _key_voldown_Cpm,               //data
   810,                           //size
    27,                           //width
    15                            //height
};

