#include "type.h"

byte _MsgBox_Out_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x02, 0x3B, 0x1E, 0x09, 0xFF, 0xFF, 0x1E, 0x2A, 
  0x01, 0x97, 0x63, 0x56, 0xA2, 0x29, 0x1F, 0x33, 0x44, 0xA2, 0x22, 0x3E, 0x02, 0x22, 0x69, 0xBA, 
  0x22, 0x26, 0x1B, 0xA2, 0x22, 0x26, 0xA2, 0x22, 0x20, 0xD1, 0x38, 0x04, 0x04, 0x0C, 0x03, 0x00, 
  0xC0, 0x50, 0x10, 0x10, 0x30, 0x04, 0x0C, 0x01, 0x03, 0x01, 0x40, 0xD0, 0x10, 0x30, 0x04, 0x0C, 
  0x03, 0x40, 0x67, 0xE6, 0x4C, 0x8D, 0x63, 0x25, 0xE9, 0xC0, 0x20, 0x59, 0x65, 0x12, 0xF8, 0x73, 
  0x7C, 0x09, 0xE0, 0x3A, 0x70, 0x56, 0x59, 0xC0, 0xF7, 0x01, 0xB2, 0xDE, 0x96, 0x59, 0xB3, 0xA5, 
  0x9D, 0x2C, 0xB3, 0x65, 0x12, 0xF4, 0x62, 0x8E, 0xEC, 0xAA, 0x95, 0xEC, 0xF7, 0x61, 0x67, 0xA2, 
  0x42, 0xCE, 0x75, 0xF7, 0x43, 0x20, 0xC8, 0xA5, 0xE1, 0x28, 0x93, 0xAB, 0x77, 0xB7, 0xD9, 0xB3, 
  0xDF, 0x85, 0x9E, 0xB8, 0x51, 0x11, 0x91, 0xDE, 0x43, 0x10, 0x08, 0xD1, 0x11, 0xD7, 0x3E, 0xF1, 
  0xD6, 0xF9, 0xF7, 0xE8, 0x49, 0x49, 0x6F, 0x22, 0x22, 0xB2, 0x5B, 0x9F, 0xBC, 0x8B, 0x8F, 0xBE, 
  0x61, 0x36, 0x13, 0x70, 0xDB, 0x64, 0xB5, 0x40, 0x64, 0x51, 0x24, 0xFB, 0xC1, 0x25, 0xC4, 0x3B, 
  0x9F, 0xB5, 0x36, 0xA7, 0x8A, 0xB1, 0xF1, 0xC6, 0x1D, 0x4C, 0xAE, 0x13, 0xAC, 0x11, 0x4B, 0x3B, 
  0x48, 0x75, 0x41, 0x79, 0x31, 0xFC, 0x60, 0xEC, 0x98, 0x4B, 0xE6, 0x40, 0x23, 0xAE, 0x3C, 0xC8, 
  0x7C, 0x55, 0xC5, 0x43, 0xB6, 0xFF, 0x08, 0xC3, 0xB0, 0xFA, 0xF3, 0xD2, 0x7C, 0xBE, 0x27, 0xE7, 
  0x33, 0xF8, 0xB0, 0x21, 0x08, 0xDD, 0x87, 0xB9, 0xF4, 0x95, 0x25, 0xAA, 0x0A, 0x5E, 0x3A, 0xF2, 
  0x21, 0xE1, 0x35, 0xE4, 0xBC, 0x9C, 0x36, 0xF6, 0xCC, 0xC2, 0xEE, 0x64, 0x37, 0x91, 0x4C, 0x49, 
  0x54, 0xC3, 0x22, 0xB8, 0x5D, 0xD8, 0x3E, 0xE1, 0xFE, 0xB1, 0x71, 0xF0, 0xDA, 0xA6, 0x09, 0x64, 
  0xAA, 0x63, 0x48, 0x61, 0xFD, 0xF9, 0x47, 0x23, 0x34, 0x96, 0xD4, 0x8D, 0x55, 0xF0, 0x98, 0x11, 
  0x41, 0x5F, 0x94, 0x71, 0x14, 0x6C, 0x3A, 0xB8, 0xDA, 0xC9, 0xFE, 0xE9, 0x35, 0xD1, 0x25, 0x44, 
  0x4A, 0x62, 0xE3, 0x61, 0xDA, 0xF5, 0x7D, 0x48, 0xA1, 0x28, 0xF9, 0xA4, 0xFC, 0x88, 0xB5, 0xC3, 
  0x6A, 0x41, 0x17, 0x8A, 0xBF, 0x64, 0x5A, 0xA0, 0x49, 0x7A, 0x11, 0x6D, 0x4B, 0x77, 0x0B, 0xE8, 
  0x45, 0xE6, 0xC5, 0xC6, 0x92, 0x39, 0x31, 0x71, 0xA5, 0x1F, 0xF5, 0x8B, 0xFF, 0x08, 0xAE, 0x62, 
  0xFD, 0x08, 0xBE, 0xBD, 0x8B, 0xCB, 0x62, 0xFE, 0x8C, 0x5F, 0xFC, 0x94, 0x43, 0x17, 0xF4, 0xF1, 
  0x47, 0xCD, 0x8B, 0xF3, 0x22, 0xDA, 0x9F, 0xFE, 0xC5, 0xFC, 0xD8, 0xBB, 0x77, 0xBB, 0xD1, 0x8B, 
  0xF9, 0xA5, 0x3C, 0xC8, 0xA3, 0xD7, 0xB4, 0x25, 0x1F, 0xD3, 0x19, 0xB2, 0x5A, 0x5E, 0x04, 0x5B, 
  0xC9, 0xE9, 0xE5, 0xA6, 0x28, 0xE3, 0xD2, 0xF2, 0x4B, 0x84, 0xCA, 0x60, 0xEC, 0x7F, 0xE5, 0x27, 
  0xDE, 0x41, 0xA5, 0x09, 0x90, 0x2A, 0xCD, 0xA2, 0x2B, 0x9F, 0xCA, 0x88, 0xCF, 0x27, 0xB7, 0x64, 
  0xA2, 0xC0, 0x5D, 0xCF, 0xE3, 0x89, 0x90, 0x28, 0x85, 0xF6, 0x53, 0x81, 0xF0, 0xF2, 0x09, 0xA2, 
  0x4A, 0xA0, 0x14, 0x3F, 0xF6, 0x6C, 0xAE, 0x11, 0x53, 0xB5, 0x4C, 0xE4, 0x47, 0x09, 0x36, 0x89, 
  0x0C, 0x81, 0x50, 0x55, 0x87, 0x75, 0x97, 0xF1, 0x4D, 0x95, 0xA4, 0x96, 0xB2, 0x37, 0x26, 0x37, 
  0x76, 0x77, 0x5E, 0x7F, 0x42, 0x08, 0xB1, 0x83, 0x44, 0x94, 0x49, 0x64, 0xAD, 0xAE, 0x7A, 0xDB, 
  0x48, 0xE7, 0x5D, 0x2F, 0x55, 0x00, 0x25, 0xBA, 0x0B, 0x1A, 0x3F, 0x1E, 0x6E, 0xFE, 0x7D, 0x39, 
  0xF5, 0xC1, 0xFE, 0x3D, 0x91, 0x4C, 0xD7, 0xF4, 0xEB, 0x1B, 0xF1, 0xE8, 0x88, 0x59, 0x83, 0x16, 
  0x93, 0x5A, 0x43, 0x09, 0x3D, 0xB8, 0x2D, 0x2F, 0x8B, 0x00, 0xE1, 0x96, 0xFD, 0x60, 0xB4, 0x87, 
  0xD5, 0xB8, 0xEB, 0xB5, 0x3A, 0x10, 0xC6, 0x0B, 0x7F, 0x62, 0xE4, 0xEF, 0xDA, 0x04, 0x73, 0x64, 
  0xBC, 0x36, 0xF5, 0x90, 0xDB, 0x8D, 0xB3, 0x36, 0x25, 0x70, 0xF6, 0xC0, 0x19, 0x49, 0x45, 0x72, 
  0x36, 0xDB, 0xBD, 0xC8, 0x82, 
};

TYPE_GrData _MsgBox_Out_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _MsgBox_Out_Cpm,                //data
  7722,                           //size
    99,                           //width
    39                            //height
};
