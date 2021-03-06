/*
Copyright Pavel Kopylov

v. 1.08

26.09.2007
*/

#include "RasterFontBrowser.h"
#include <string.h>
#include <stdio.h>


#define htonl(A) ((((long)(A) & 0xff000000) >> 24) | (((long)(A) & 0x00ff0000) >> 8)  | (((long)(A) & 0x0000ff00) << 8)  | (((long)(A) & 0x000000ff) << 24)    )
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

#ifdef HOOK
extern FONT FONT_SMALL;
extern FONT FONT_MEDIUM;
extern FONT FONT_BIG;
#endif // HOOK
 
int Load_Font_Height(FONT *font);
int Load_Font_Baseline(FONT *font);
int Load_Char_Table(FONT* font);
void FillImage(FONT *font, word *image, int width, int height);
void ComputeAntialiasingMap(FONT *font, word foreColor, word backColor);
int CalcSize(FONT *font, unsigned char* text, int* width, int *text_length);
int RenderString(FONT *font, unsigned char* text, int text_length, int width, word** image);

void draw_bitmap(FONT *font, unsigned char* bitmap, unsigned char *image, int width, int height, int x_offset, int y_offset, int bitmap_rows, int bitmap_width);


//////////////////////////////////////////////////////////////////////////
int TAP_Osd_PutS_Font(word rgn, dword x, dword y, dword maxX, char *str, word fcolor, word bcolor, FONT *font, byte align)
{
    int err=0;


    SetColors(font, fcolor, bcolor);
    err = TAP_Osd_PutS_FontL(rgn, x, y, maxX, str, font, align);

    return err;
};


//////////////////////////////////////////////////////////////////////////
int TAP_Osd_PutS_FontEx(word rgn, dword x, dword y, dword maxX, dword maxY, int baseline_shift, char *str, word fcolor, word bcolor, FONT *font, byte align)
{
    int err=0;


    font->m_fontHeight = max((int)maxY, font->m_fontHeight);
    if (font->m_bShifted==0)
    {
        font->m_fontBaseline += baseline_shift;
        font->m_bShifted=1;
    }
    err = TAP_Osd_PutS_Font(rgn, x, y, maxX, str, fcolor, bcolor, font, align);

    return err;
};

//////////////////////////////////////////////////////////////////////////
int TAP_Osd_PutS_FontL(word rgn, dword x, dword y, dword maxX, char *str, FONT *font, byte align)
{
    int new_x;
    int width;
    int strlen_original, strlen_new;
    int err=0;
    word *image=0;

    width = (maxX == 0) ? 0 : maxX - x;

    strlen_original = (int)strlen(str);
    err = CalcSize(font, (unsigned char *)str, &width, &strlen_new);
    if (err != 0)
        return err;

    // Draw background rectangle
    if (maxX == 0)
        TAP_Osd_FillBox(rgn, x, y, width, font->m_fontHeight, font->m_backColor);
    else
        TAP_Osd_FillBox(rgn, x, y, maxX-x, font->m_fontHeight, font->m_backColor);

    // Decision of placement
    if (strlen_new < strlen_original)    // the required area is not enough for "str"
    {
        err = RenderString(font, (unsigned char*)str, strlen_new, width, &image);
        if (err==0)
        {
            TAP_Osd_DrawPixmap(rgn, (int)x, (int)y, width, font->m_fontHeight, image, FALSE, OSD_1555);
#ifndef NO_ALLOC
            TAP_MemFree(image);
#endif            
        }
    }
    else
    {
        switch(align)
        {
        case ALIGN_LEFT:
            new_x = (int)x;
            break;
        case ALIGN_CENTER:
            new_x = (int)( (x + maxX)/2 - width/2);
            break;
        case ALIGN_RIGHT:
            new_x = (int)(x + maxX - width);
            break;
        }
        err = RenderString(font, (unsigned char*)str, strlen_original, width, &image);
        if (err==0)
        {
            TAP_Osd_DrawPixmap(rgn, new_x, (int)y, width, font->m_fontHeight, image, FALSE, OSD_1555);
#ifndef NO_ALLOC
            TAP_MemFree(image);
#endif            
        }
    }

    return err;
}

//////////////////////////////////////////////////////////////////////////
int Draw_Font_String(word region, dword x, dword y, char *str, char* fontname,  word foreColor, word backColor)
{
    int err1, width=0, text_length;
    FONT font;
    word *image=NULL;


    err1 = Load_Font(&font, fontname);
    if (err1==0)
    {
        SetColors(&font, COLOR_Yellow, COLOR_DarkBlue);
        err1 = CalcSize(&font, (unsigned char *)str, &width, &text_length);
        if (err1==0)
        {
            err1 = RenderString(&font, (unsigned char *)str, text_length, width, &image);
            if (err1==0)
            {
                TAP_Osd_DrawPixmap(region, x, y, width, font.m_fontHeight, image, FALSE, OSD_1555);
#ifndef NO_ALLOC
                TAP_MemFree(image);
#endif            
            }
        }
        Delete_Font(&font);
    }

    return err1;
}

//////////////////////////////////////////////////////////////////////////
int Load_Font(FONT *font, char *fileName)
{
    int            ret=-1, read, err;
    TYPE_File    *f;
    long        flen;
    //char        msg[256];

    
#ifdef NO_ALLOC
    font->m_grayBuffer = NULL;
    font->m_wordBuffer = NULL;
#endif

    font->m_bShifted = 0;
    f = TAP_Hdd_Fopen(fileName);
    if (f!=0)
    {
        font->m_bmpHeaderArray=NULL;

        flen = TAP_Hdd_Flen(f);
        font->m_data = (unsigned char*)TAP_MemAlloc(flen);
        if (font->m_data!=NULL)
        {
            read = TAP_Hdd_Fread(font->m_data, flen, 1, f);
            TAP_Hdd_Fclose(f);
            if (read==1)
            {
                err = Load_Font_Height(font);
                if (err==0)
                {
                    //TAP_SPrint(msg, "height: %d", font->m_fontHeight);
                    //TAP_Osd_PutS(rgn, 50, 500, 150, msg, COLOR_Yellow, COLOR_DarkBlue, 0, FNT_Size_1419, 0, ALIGN_LEFT);
                    err = Load_Font_Baseline(font);
                    if (err==0)
                    {
                        //TAP_SPrint(msg, "baseline: %d", font->m_fontBaseline);
                        //TAP_Osd_PutS(rgn, 180, 500, 280, msg, COLOR_Yellow, COLOR_DarkBlue, 0, FNT_Size_1419, 0, ALIGN_LEFT);
                        err = Load_Char_Table(font);
                        if (err==0)
                        {
#ifdef NO_ALLOC
                            font->m_grayBuffer = (unsigned char*)TAP_MemAlloc(720 * font->m_fontHeight * sizeof(unsigned char));
                            font->m_wordBuffer = (word*)TAP_MemAlloc(720 * font->m_fontHeight * sizeof(word)); // word
                            if (font->m_grayBuffer==NULL || font->m_wordBuffer==NULL)
                            {
                                return 7;
                            }
#endif
                            ret = 0;
                        } 
                        else //Font table didn't load
                        {
                            ret = 6;
                        }
                    }
                    else //Font baseline not determined
                    {
                        ret = 5;
                    }
                }
                else //Font height not determined
                {
                    ret = 4;
                }
            }
            else //File didn't read
            {
                ret = 3;
            }
        }
        else // not enough memory
        {
            ret = 2;
        }
    }
    else
    {
        // File didn't open
        ret = 1;
    }

    return ret;
}

//////////////////////////////////////////////////////////////////////////
void Delete_Font(FONT *font)
{
#ifdef NO_ALLOC
    if (font->m_grayBuffer != NULL)
    {
        TAP_MemFree(font->m_grayBuffer);
    }
    if (font->m_wordBuffer != NULL)
    {
        TAP_MemFree(font->m_wordBuffer);
    }
#endif

    if (font != NULL)
    {
        TAP_MemFree(font->m_data);
    }
}

//////////////////////////////////////////////////////////////////////////
int Load_Font_Height(FONT *font)
{
    int error=1;
    long *ptr;


    if (font!=NULL)
    {
        ptr = (long*)(font->m_data);
        font->m_fontHeight = *ptr;
#ifdef _WIN32
        font->m_fontHeight = htonl(font->m_fontHeight);
#endif
        error=0;
    }

    return error;
}

//////////////////////////////////////////////////////////////////////////
int Load_Font_Baseline(FONT *font)
{
    int error=1;
    long *ptr;


    if (font!=NULL)
    {
        ptr = (long*)(font->m_data+4);
        font->m_fontBaseline = *ptr;
#ifdef _WIN32
        font->m_fontBaseline = htonl(font->m_fontBaseline);
#endif
        error=0;
    }

    return error;
}

//////////////////////////////////////////////////////////////////////////
int Load_Char_Table(FONT* font)
{
    int error=1;
#ifdef _WIN32
    int i;
#endif


    if (font!=NULL)
    {
        font->m_bmpHeaderArray = (TableItem*)(font->m_data+8);
        error=0;
    }

#ifdef _WIN32
    for (i=0; i<256; i++)
    {
        font->m_bmpHeaderArray[i].slot_advance_x = htonl(font->m_bmpHeaderArray[i].slot_advance_x);
        font->m_bmpHeaderArray[i].slot_advance_y = htonl(font->m_bmpHeaderArray[i].slot_advance_y);
        font->m_bmpHeaderArray[i].slot_bitmap_left = htonl(font->m_bmpHeaderArray[i].slot_bitmap_left);
        font->m_bmpHeaderArray[i].slot_bitmap_top = htonl(font->m_bmpHeaderArray[i].slot_bitmap_top);
        font->m_bmpHeaderArray[i].bitmap_rows = htonl(font->m_bmpHeaderArray[i].bitmap_rows);
        font->m_bmpHeaderArray[i].bitmap_width = htonl(font->m_bmpHeaderArray[i].bitmap_width);
        font->m_bmpHeaderArray[i].offset = htonl(font->m_bmpHeaderArray[i].offset);
    }
#endif

    return error;
}


//////////////////////////////////////////////////////////////////////////
void SetColors(FONT *font, word foreColor, word backColor)
{
    if (font->m_foreColor != foreColor || font->m_backColor != backColor)
    {
        font->m_foreColor=foreColor;
        font->m_backColor=backColor;
        ComputeAntialiasingMap(font, foreColor, backColor);
    }
}

//////////////////////////////////////////////////////////////////////////
int CalcSize(FONT *font, unsigned char* text, int* width, int *text_length)
{
    int pen_x=0, pen_y=0, i, int_adv, tmp_len;
    //int t_max_bmp_top=0, t_min_bmp_bottom=0;


    if (font==NULL || font->m_bmpHeaderArray==NULL)
    {
        return -1;
    }    

    // First calculating resulting bitmap size & cashing bitmaps
    tmp_len = (int)strlen((char*)text);
    (*text_length) = tmp_len;

    for (i=0; i<tmp_len; i++)
    {
        int_adv = max(font->m_bmpHeaderArray[text[i]].slot_advance_x, font->m_bmpHeaderArray[text[i]].bitmap_width);
        if ((*width)>0)
        {
            if (((pen_x + int_adv)>>6)>(*width))
            {
                (*text_length) = i;
                break;
            }
        }
        pen_x += int_adv;

        //t_min_bmp_bottom = max(t_min_bmp_bottom, font->m_bmpHeaderArray[text[i]].bitmap_rows-font->m_bmpHeaderArray[text[i]].slot_bitmap_top);
        //t_max_bmp_top = max(t_max_bmp_top, font->m_bmpHeaderArray[text[i]].slot_bitmap_top);
    }

    (*width) = pen_x>>6;
    (*width) = ((*width)/2+1)*2;
    //font->m_fontHeight = max(font->m_fontHeight, t_min_bmp_bottom+t_max_bmp_top);

    return 0;
}

//////////////////////////////////////////////////////////////////////////
int RenderString(FONT *font, unsigned char* text, int text_length, int width, word** image)
{
    int             pen_x=0, pen_y=0, i;
    int             y_offset, x_offset;
    unsigned char    *img;      // whole string
    word            C, *imagePtr;
    int             x, y;
    unsigned char    pixel;
    unsigned char    *bitmap;  // character bitmap


    if (font==NULL || font->m_bmpHeaderArray==NULL)
    {
        return -1;
    }    

#ifdef NO_ALLOC
    img = font->m_grayBuffer;
#else
    // Create bitmap buffer
    img = (unsigned char*)TAP_MemAlloc(width * font->m_fontHeight * sizeof(unsigned char));
    if (img==NULL)
    {
        return -2;
    }
#endif
    for (i=0; i<width*font->m_fontHeight; i++) img[i] = 0;

    // Render string to a buffer
    for (i=0; i<text_length; i++)
    {    
        if (i==0)
        {
            pen_x = -font->m_bmpHeaderArray[text[i]].slot_bitmap_left;
            pen_y = font->m_fontBaseline;
        }
        x_offset = pen_x+font->m_bmpHeaderArray[text[i]].slot_bitmap_left;
        y_offset = pen_y-font->m_bmpHeaderArray[text[i]].slot_bitmap_top;

        LOAD_CHAR(font, text[i], &bitmap);
        draw_bitmap(font, bitmap, img, width, font->m_fontHeight, x_offset, y_offset, font->m_bmpHeaderArray[text[i]].bitmap_rows, font->m_bmpHeaderArray[text[i]].bitmap_width);

        pen_x += font->m_bmpHeaderArray[text[i]].slot_advance_x >> 6; // increment pen position
        pen_y += font->m_bmpHeaderArray[text[i]].slot_advance_y >> 6; // increment pen position
    }


#ifdef NO_ALLOC
    (*image) = font->m_wordBuffer;
#else
    (*image) = (word*)TAP_MemAlloc(width * font->m_fontHeight * sizeof(word)); // word
    if ((*image)==NULL)
    {
        return -2;
    }
#endif
    imagePtr = (*image);

    // Transfer buffer to the image
    y = font->m_fontHeight*width;
    for (x=0; x<y; x++)
    {
        pixel = img[x];
        C = font->m_antialiasmap[pixel>>4];
        imagePtr[x] = C; 
    }

#ifdef NO_ALLOC
    ;
#else
    TAP_MemFree(img);
#endif

    return 0;
}

//////////////////////////////////////////////////////////////////////////
void draw_bitmap(FONT *font, unsigned char* bitmap, unsigned char *image, int width, int height, int x_offset, int y_offset, int bitmap_rows, int bitmap_width)
{
    int  i, j, q;
    int  bx, by;
    unsigned char pixel;


    q=0;
    for (by = 0; by<bitmap_rows; by++)
    {
        j = by + y_offset;
        for (bx = 0; bx<bitmap_width; bx++)
        {
            i = bx + x_offset;
            if (i>=0 && j>=0 && i<width && j<height)
            {
                pixel = bitmap[q];
                PUTPIXEL_OR(image, i, j, pixel); //image[j*width+i] = pixel;
            }
            q++;
        }
    }
}

//////////////////////////////////////////////////////////////////////////
// computes 16 anti-aliasing steps trough RGB space
void ComputeAntialiasingMap(FONT *font, word foreColor, word backColor)
{
    int dimmer=16, i;
    int fr, fg, fb, br, bg, bb;


    if (foreColor!=backColor)
    {
        fr = GETR(foreColor); fg = GETG(foreColor);  fb = GETB(foreColor);
        br = GETR(backColor); bg = GETG(backColor);  bb = GETB(backColor);

        for(i=0; i<16; i++)
        {
            font->m_antialiasmap[i] = RGB( (fr*dimmer+(255-dimmer)*br)>>8, (fg*dimmer+(255-dimmer)*bg)>>8, (fb*dimmer+(255-dimmer)*bb)>>8);
            dimmer += 16;
        }
        font->m_antialiasmap[0] = backColor;
        font->m_antialiasmap[15] = foreColor;
    }
    else
    {
        for(i=0; i<16; i++)
        {
            font->m_antialiasmap[i] = backColor;
        }
    }
}

//////////////////////////////////////////////////////////////////////////
// Hook    for TAP_Osd_GetW
#ifdef HOOK

int TAP_Osd_GetW_HOOK(const char *str, byte fntType, byte fntSize)
{
    int retval=0;
    FONT *font=NULL;


    if (fntType!=FONT_OVERRIDE)
    {
        retval = TAP_Osd_GetW(str, fntType, fntSize);
    }
    else
    {
        switch(fntSize)
        {
        case FNT_Size_1419:
            font = &FONT_SMALL;
            break;
        case FNT_Size_1622:
            font = &FONT_MEDIUM;
            break;
        case FNT_Size_1926:
            font = &FONT_BIG;
            break;
        }

        CalcSize(font, (unsigned char*)str, &retval, 0);
    }

    return retval;
}

//////////////////////////////////////////////////////////////////////////
// Hook    for TAP_Osd_PutS
// fntType : font type. It SHOULD be 0.
// fntSize : font size. FNT_Size_1419, FNT_Size_1622 or FNT_Size_1926
// bDot    : It decides to print ��� in case that the string is over the maxX. - not used so far
int TAP_Osd_PutS_HOOK(word rgn, dword x, dword y, dword maxX, const char *str, word fcolor, word bcolor, byte fntType, byte fntSize, byte bDot, byte align)
{
    int retval=0;
    FONT *font=NULL;


    if (fntType!=FONT_OVERRIDE)
    {
        retval = TAP_Osd_PutS(rgn, x, y, maxX, str, fcolor, bcolor, fntType, fntSize, bDot, align);
    }
    else
    {
        switch(fntSize)
        {
        case FNT_Size_1419:
            font = &FONT_SMALL;
            break;
        case FNT_Size_1622:
            font = &FONT_MEDIUM;
            break;
        case FNT_Size_1926:
            font = &FONT_BIG;
            break;
        }

        retval = TAP_Osd_PutS_Font(rgn, x, y, maxX, (unsigned char *)str, fcolor, bcolor, font, align);
    }
    
    return retval;
}

#endif //HOOK