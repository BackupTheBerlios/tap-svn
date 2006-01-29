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
#include ".\globals.h"
#include "Timers.h"
#include "EPGData.h"
#include "MEIReader.h"
#include "Channels.h"
#include "Logger.h"
#include "ProgressNotification.h"

Timers* Globals::m_pTheTimers = NULL;
EPGdata* Globals::m_pEPGdata = NULL;
Channels* Globals::m_pChannels = NULL;


Globals::Globals(void)
{
}

Globals::~Globals(void)
{
}

Timers* Globals::GetTimers()
{
	if (m_pTheTimers == 0)
		m_pTheTimers = new Timers();

	return m_pTheTimers;
}

Channels* Globals::GetChannels()
{
	if (m_pChannels == 0)
		m_pChannels = new Channels();

	return m_pChannels;
}

EPGdata* Globals::GetEPGdata(ProgressNotification* pProgress)
{
	if (m_pEPGdata == 0)
	{
		m_pEPGdata = new EPGdata();

		MEIReader mei;
		if (mei.CanRead())
		{
			if (pProgress)
				pProgress->Start();

			while (mei.Read(*m_pEPGdata, 250))
			{
				if (pProgress)
					pProgress->Step(mei.GetPercentDone());
			}

			m_pEPGdata->CheckForContinuedPrograms();

			if (pProgress)
				pProgress->Finish();

			TRACE("Loaded EPG data\n");
			TRACE_MEMORY();
		}
	}

	return m_pEPGdata;
}

void Globals::Cleanup()
{
	delete m_pTheTimers;
	m_pTheTimers = NULL;
	delete m_pEPGdata;
	m_pEPGdata = NULL;
	delete m_pChannels;
	m_pChannels = NULL;
}
