/*
	Copyright (C) 2005-2006 Darkmatter

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

// This module handles to loading, and saving of the configuration


#define PROJECT_DIRECTORY "UK TAP Project"
#define OPTIONS_FILENAME "UkTimers.ini"

#define DATA_BUFFER_SIZE_ini 1024

static char *dataBuffer_ini;
static int dataBufferPtr_ini;



//----------------
//
void WriteIniFile( TYPE_File *writeFile )
{
	TAP_Hdd_ChangeDir( PROJECT_DIRECTORY );
	if ( TAP_Hdd_Exist( OPTIONS_FILENAME ) ) TAP_Hdd_Delete( OPTIONS_FILENAME );	// Just delete any old copies

	TAP_Hdd_Create( OPTIONS_FILENAME, ATTR_PROGRAM );						// Create the file

	writeFile = TAP_Hdd_Fopen( OPTIONS_FILENAME );
	if ( writeFile == NULL ) return; 										// Check we can open it

	TAP_Hdd_Fwrite( dataBuffer_ini, DATA_BUFFER_SIZE_ini, 1, writeFile );	// dump the whole buffer in one hit

	TAP_Hdd_Fclose( writeFile );
	TAP_Hdd_ChangeDir("..");												// return to original directory
}



void WriteStrToIniBuf( char *str )											// add str to current end of buffer
{																			// and move end out
	int count, i;

    count = strlen(str);
	
	for ( i=0; i<count; i++)
	{
		dataBuffer_ini[dataBufferPtr_ini+i] = str[i];							// copy accross 1 char at a time
	}
	dataBufferPtr_ini += i;
}



void SaveConfigurationToFile( void )
{
	TYPE_File	*writeFile;
	int i;
	char	str[256];

	dataBuffer_ini = TAP_MemAlloc( DATA_BUFFER_SIZE_ini );				// Buffer the write data to memory before writing all in one hit
	memset( dataBuffer_ini, '\0', DATA_BUFFER_SIZE_ini );				// set the whole buffer to the string termination character (null)
	dataBufferPtr_ini = 0;


	switch ( unitModelType )
	{
	    case TF5800 : TAP_SPrint(str, "TF5800\r\n" ); break;
		case TF5000 : TAP_SPrint(str, "TF5000\r\n" ); break;
		default 	: TAP_SPrint(str, "BAD\r\n" ); break;
	}
	WriteStrToIniBuf( str );

	TAP_SPrint(str, "%d\r\n", mainActivationKey );
	WriteStrToIniBuf( str );


	WriteIniFile( writeFile );										// write all the data in one pass
	TAP_MemFree( dataBuffer_ini );										// must return the memory back to the heap
}


//------------------------------------------------------------------
//
char *ReadIniField( void )
{
	int i;
	char readChar;
	char *oldPtr;

	oldPtr = (char *) dataBuffer_ini + dataBufferPtr_ini;

	i=0;
	while ( dataBufferPtr_ini < DATA_BUFFER_SIZE_ini )					// Bounds check
	{
		readChar = dataBuffer_ini[dataBufferPtr_ini];					// read the file one character at a time

		if ( readChar == '\t' ) break;									// looking for TAB delimiter,
		if ( readChar == '\n' ) break;									// or end of line.
		if ( readChar == '\r' )
		{																// Carriage return is followed by new line -> discard them both.
			dataBuffer_ini[dataBufferPtr_ini] = '\0';
			dataBufferPtr_ini++;
			break;
		}
		if ( readChar == '\0' ) break;									// Null terminator signifies end of file

		dataBufferPtr_ini++;
	}

	dataBuffer_ini[dataBufferPtr_ini] = '\0';							// add a terminator to the string
	dataBufferPtr_ini++;
	return oldPtr;														// return a pointer to the start of the current field
}



dword ReadIniDecimal( void )
{
    char 	str[256];
	dword	tmp;
	int i;
	
	strcpy( str, ReadIniField() );										// Read the Duration
	tmp = 0;
	i = 0;

	while ( str[i] != '\0' )
	{
	    tmp = (tmp * 10) + (str[i] - '0');
		i++;
	}

	return tmp;
}


void SetConfigurationVariables( void )
{
	char *str;

	str = ReadIniField();

	if ( strcmp( str, "TF5000" ) == 0 ) unitModelType = TF5000;
	else unitModelType = TF5800;

	mainActivationKey = ReadIniDecimal();
}


bool ReadConfigurationFile( void )
{
	TYPE_File *readFile;
	int i;
	dword fileLength;

	TAP_Hdd_ChangeDir( PROJECT_DIRECTORY );
	if ( ! TAP_Hdd_Exist( OPTIONS_FILENAME ) ) return FALSE;			// check the timer file exits in the current directory
	
	readFile = TAP_Hdd_Fopen( OPTIONS_FILENAME );
	if ( readFile == NULL ) return FALSE;								// and we can open it ok

	dataBuffer_ini = TAP_MemAlloc( DATA_BUFFER_SIZE_ini );				// Read the data in one hit (quicker), then process from RAM
	memset( dataBuffer_ini, '\0', DATA_BUFFER_SIZE_ini );					// set the whole buffer to the string termination character (null)
	dataBufferPtr_ini = 0;

	fileLength = TAP_Hdd_Flen( readFile );								// how big is the file
	if ( fileLength > DATA_BUFFER_SIZE_ini  ) fileLength = DATA_BUFFER_SIZE_ini;	// ensure we don't overflow the buffer
	
	TAP_Hdd_Fread( dataBuffer_ini, fileLength, 1, readFile );			// grab all the data from the file

	TAP_Hdd_Fclose( readFile );
	TAP_Hdd_ChangeDir("..");											// return to original directory

	SetConfigurationVariables();

	TAP_MemFree( dataBuffer_ini );										// must return the memory back to the heap

	return TRUE;
}


void LoadConfiguration( void )
{
	if ( !ReadConfigurationFile() )
	{
		unitModelType = TF5800;
		mainActivationKey = RKEY_White;

		SaveConfigurationToFile();
	}
}

