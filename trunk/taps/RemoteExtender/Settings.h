/*
	Copyright (C) 2007 Simon Capewell

	This file is part of the TAPs for Topfield PVRs project.
		http://tap.berlios.de/

	This is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	The software is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this software; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __SETTINGS_H
#define __SETTINGS_H


typedef struct
{
	bool mheg;
	bool quickAspectBlocker;
} Settings;

extern Settings settings;

void OptionsMenu_Show();
void OptionsMenu_Close();
dword OptionsMenu_HandleKey( dword key, dword keyHW );
bool OptionsMenu_IsActive();

void Settings_Load();
void Settings_Save();
void Settings_Reset();


#endif