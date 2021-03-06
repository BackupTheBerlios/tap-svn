//Tapulator - An emulator for the Topfield PVR TAP API
//Copyright (C) 2005  Robin Glover
//
//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either version 2
//of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
// You can contact the author via email at robin.w.glover@gmail.com

#pragma once
#include "InfoLogger.h"

class CChannelList;

class Timers : public InfoLogger
{
public:
	Timers( CChannelList* channelList );
	~Timers(void);

	int GetTotalNum(void );
	bool GetInfo(unsigned int entryNum, TYPE_TimerInfo *info );
	int Add(TYPE_TimerInfo *info );
	int Modify(unsigned int entryNum, TYPE_TimerInfo *info );
	bool Delete(unsigned int entryNum );

private:
	// Timer loading functions from UKTimers
	CString ReadTimerField();
	word ExtractServiceID( char *LCN_str, char *serviceName, byte serviceType );
	dword ReadTimerStart();
	word ReadTimerDuration();
	bool ProcessTimerLine();

private:

	std::vector<TYPE_TimerInfo> m_vecTimers;
	CChannelList* m_ChannelList;
	CString m_line;
};
