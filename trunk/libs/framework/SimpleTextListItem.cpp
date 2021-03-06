/*
Copyright (C) 2005 Robin Glover

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
#include "simpletextlistitem.h"

SimpleTextListItem::SimpleTextListItem(ListPage* pParentList, dword dwFlags, const char* pszCol1, const char* pszCol2, const char* pszCol3, const char* pszCol4, const char* pszCol5) 
: ListItem(pParentList, dwFlags)
{
	m_asItemText[0] = pszCol1;
	m_asItemText[1] = pszCol2;
	m_asItemText[2] = pszCol3;
	m_asItemText[3] = pszCol4;
	m_asItemText[4] = pszCol5;
}

SimpleTextListItem::~SimpleTextListItem(void)
{
}

void SimpleTextListItem::DrawSubItem(short int iColumn, Rect rcBounds)
{
	DrawSubItemString(iColumn, rcBounds, m_asItemText[iColumn]);
}
