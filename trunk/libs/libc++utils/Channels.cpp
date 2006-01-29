/*
Copyright (C) 2006 Robin Glover

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
#include ".\channels.h"


Channels::Channels(void)
{
	int nTv, nRadio;
	TAP_Channel_GetTotalNum(&nTv, &nRadio);

	for (int i=0; i<nTv; i++)
	{
		TYPE_TapChInfo info;
		TAP_Channel_GetInfo(SVC_TYPE_Tv, i, &info);

		m_names.push_back(info.chName);
		m_lcns.push_back(info.logicalChNum);
	}
}

Channels::~Channels(void)
{
}

int Channels::ToppyToLogical(int iToppyChan)
{
	return m_lcns[iToppyChan];
}

int Channels::LogicalToToppy(int iLogicalChannelNum)
{
	for (unsigned int i=0; i<m_lcns.size(); i++)
	{
		if (m_lcns[i] == iLogicalChannelNum)
			return i;
	}
	return -1;
}

const string& Channels::NameForLCN(int iLogicalChannelNum)
{
	for (unsigned int i=0; i<m_lcns.size(); i++)
	{
		if (m_lcns[i] == iLogicalChannelNum)
			return m_names[i];
	}

	return m_names.nullObject();
}

int Channels::GetCount()
{
	return m_names.size();
}
