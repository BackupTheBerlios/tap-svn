#
#  Copyright (c) 2005 Simon Capewell. All Rights Reserved.
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

include ../../tools/build/tap.mk

all: VirtualRemote.tap ../../libs/Firmware/libfirmware.a

# Copy files to the Toppy using tfcopy
copy: all
	tfcopy *.tap '#:\ProgramFiles\Auto Start\'
#	tfcopy *.tap '#:\ProgramFiles\'

# A target for removing generated files.
clean:
	-rm -f *.tap *.o *.elf *.map

VirtualRemote.elf::	VirtualRemote.o ScreenCapture.o ../../libs/libutils/libutils.a ../../libs/Firmware/libfirmware.a
VirtualRemote.o:	VirtualRemote.c
ScreenCapture.o:	ScreenCapture.c

CFLAGS+=-I../../libs/TSRCommander -I../../libs/libutils -I../../libs/Firmware

../../libs/libutils/libutils.a::
	$(MAKE) -C ../../libs/libutils

../../libs/Firmware/libfirmware.a::
	$(MAKE) -C ../../libs/Firmware
