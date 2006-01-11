/*
Copyright (C) 2005 Simon Capewell

This file is part of the TAPs for Topfield PVRs project.
http://tap.berlios.de/

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include ".\dialogbox.h"

#include "Tapplication.h"
#include "TextTools.h"
#include "graphics.c"


DialogBox::DialogBox(const char* title, const char* line1, const char* line2)
{
	this->title		= title;
	this->line1		= line1;
	this->line2		= line2;
}

DialogBox::~DialogBox(void)
{
}

void DialogBox::CreateDialog()
{
	// Store the currently displayed screen area where we're about to put our pop-up window on.
    windowCopy = TAP_Osd_SaveBox(GetTAPScreenRegion(), YESNO_WINDOW_X, YESNO_WINDOW_Y, YESNO_WINDOW_W, YESNO_WINDOW_H);

	Draw();
}

void DialogBox::Draw()
{
    // Display the pop-up window.
    TAP_Osd_PutGd( GetTAPScreenRegion(), YESNO_WINDOW_X, YESNO_WINDOW_Y, &_popup360x180Gd, TRUE );

    // Display Title and information in pop-up window
	PrintCenter( GetTAPScreenRegion(), YESNO_WINDOW_X+5, YESNO_WINDOW_Y +  13, YESNO_WINDOW_X+YESNO_WINDOW_W-5, title, MAIN_TEXT_COLOUR, 0, FNT_Size_1926 );
	PrintCenter( GetTAPScreenRegion(), YESNO_WINDOW_X+5, YESNO_WINDOW_Y +  56, YESNO_WINDOW_X+YESNO_WINDOW_W-5, line1, MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
	PrintCenter( GetTAPScreenRegion(), YESNO_WINDOW_X+5, YESNO_WINDOW_Y +  89, YESNO_WINDOW_X+YESNO_WINDOW_W-5, line2, MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
}

//-----------------------------------------------------------------------
//
void DialogBox::DestroyDialog()
{
	TAP_Osd_RestoreBox(GetTAPScreenRegion(), YESNO_WINDOW_X, YESNO_WINDOW_Y, YESNO_WINDOW_W, YESNO_WINDOW_H, windowCopy);
	TAP_MemFree(windowCopy);
}

