#
# Copyright (c) 2005 Simon Capewell. All Rights Reserved.
#
#  This file is part of the TAPs for Topfield PVRs project.
#      http://tap.berlios.de/
#
#  This is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  The software is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this software; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#


INCLUDEDIRS=-I../../libs/libutils -I../../libs/libc++utils -I../../libs/Framework -I../../libs/FireBird
LIBDIRS=-L../../libs/libutils -L../../libs/libc++utils -L../../libs/Framework -L../../libs/FireBird

LIBRARIES=../../libs/libutils/libutils.a ../../libs/libc++utils/libc++utils.a ../../libs/Framework/libFramework.a
OBJECTS=tap.o TAPLists.o TAPCommander.o LoadedTAPPage.o AutoStartPage.o ConfigPage.o

include ../../tools/build/tap.mk
include ../../libs/libc++utils/tap++.mk

all: TAPCommander.tap

# Copy files to the Toppy using tfcopy
copy: all
	tfcopy.cmd TAPCommander.tap '#:\ProgramFiles\'

# A target for removing generated files.
clean:
	-rm -f *.tap *.o *.elf *.map VTableFix.cpp

CFLAGS+=$(INCLUDEDIRS)
CXXFLAGS+=$(INCLUDEDIRS)

LDFLAGS:= -u TAP_Main $(LIBDIRS) -lFramework -lc++utils -lutils -lFireBird -lc $(LDFLAGS)

TAPCommander.tap:	TAPCommander.elf
TAPCommander.elf:	$(OBJECTS) $(VTABLEFIX)
tap.o:				tap.c
TAPLists.o:			TAPLists.c
TAPCommander.o:		TAPCommander.cpp
LoadedTAPPage.o:	LoadedTAPPage.cpp LoadedTAPPage.h
AutoStartPage.o:	AutoStartPage.cpp AutoStartPage.h
ConfigPage.o:		ConfigPage.cpp ConfigPage.h


