/************************************************************
			Part of the ukEPG project
		This module displays the Configuration list

Name	: ConfigMenu.c
Author	: Darkmatter
Version	: 0.0
For		: Topfield TF5x00 series PVRs
Licence	:
Descr.	:
Usage	:
History	: v0.0 Darkmatter: 31-05-05	Inception date

	Last change:  USE   2 Aug 105   11:45 pm
**************************************************************/

#include "RemoteKeys.c"

static int chosenConfigLine;
static char configOption;
static bool returnFromConfig;

//#define X1	130
//#define X2	300
//#define E0	113
//#define E1	275
//#define E2	627
//#define Y	57
//#define Y2	514
//#define Y_STEP 30

#define CONFIG_X2	300
#define CONFIG_E0	113
#define CONFIG_E1	275
#define CONFIG_E2	627

#define CONFIG_Y_OFFSET 36
#define CONFIG_Y_STEP 42					// was 44

#define TOTAL_PAGES 2
#define LINES_PER_PAGE 10
#define CONFIG_LINES (LINES_PER_PAGE*TOTAL_PAGES)
#define DEFUALT_EXIT_OPTION 0

#define TF5000_GMT_OFFSET_DEFAULT (10*60)
#define TF5800_GMT_OFFSET_DEFAULT 0

static keyCodes_Struct localKeyCodes;
static dword CurrentActivationKey;
static TYPE_ModelType currentModelType;

static int currentGMToffsetOption;
static int currentRecordingRateOption;
static int currentSortOrderOption;
static int currentProgressBarOption;
static int currentColumn1Option;
static int currentColumn2Option;
static int currentColumn3Option;
static int currentColumn4Option;
static int currentColumn5Option;
static int currentInfoLineOption;
static int currentNumberLinesOption;
static int currentBorderOption;
static int currentRecCheckOption;



static bool enterActivateKey;
static byte keyStage;
static byte oldLineNumber;


void DisplayConfigLine(char lineNumber)
{
    char	str[80], str2[80];
	char	*text;
	int     optionNumber, page;


	if (( lineNumber < 1 ) || ( lineNumber > CONFIG_LINES )) return;		// bound check

    optionNumber = lineNumber;
    page = ((optionNumber-1)/LINES_PER_PAGE)+1;
    lineNumber = lineNumber % LINES_PER_PAGE;
    if (lineNumber == 0) lineNumber = 10;  // Put the Save/Cancel options always on line 10.	

	if (( chosenConfigLine == optionNumber ) && ( optionNumber != 10 ))		// highlight the current cursor line
    {																	// save, cancel, delete looks after itself
		TAP_Osd_PutGd( rgn, 53, lineNumber*CONFIG_Y_STEP+CONFIG_Y_OFFSET-8, &_highlightGd, FALSE );
	}
	else
	{
		TAP_Osd_PutGd( rgn, 53, lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET - 8, &_rowaGd, FALSE );
	}
	TAP_SPrint(str,"%d.",optionNumber);
	TAP_Osd_PutStringAf1622(rgn, 75, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), 700, str, MAIN_TEXT_COLOUR, 0 );
	

	switch ( optionNumber )
	{
		case 1 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1, "Model Type", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );


				if ( currentModelType == TF5800t ) TAP_SPrint(str,"TF5800  (UK)");
				else TAP_SPrint(str,"TF5000  (International)");
				
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
				break;


		case 2 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1, "Language", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );

				TAP_SPrint(str, "English");
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, COLOR_DarkGray, 0 );
			    break;

				
		case 3 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Activation Key", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );

				switch ( keyStage )
				{
				    case 0 : 	text = GetButtonText( &localKeyCodes, CurrentActivationKey );
								strcpy( str, text );
								break;
								
					case 1 : 	TAP_SPrint( str, "Press new key NOW !" );
								break;

					case 2 : 	TAP_SPrint( str, "Invalid choice" );
						    	break;

					default : 	TAP_SPrint( str, "[Invalid value]" );
								break;
				}
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;

		case 4 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "GMT Time Offset", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
                if (currentGMToffsetOption > 0 )  // Handle positve offsets.
                	TAP_SPrint( str, "%+02d:%02d hours", currentGMToffsetOption/60, currentGMToffsetOption%60  );
                else     // Handle negative offsets.
                	TAP_SPrint( str, "%+02d:%02d hours", currentGMToffsetOption/60, -currentGMToffsetOption%60  );
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;

		case 5 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Recording Rate", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );

				TAP_SPrint( str, "%dMB per hour", currentRecordingRateOption  );
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;

		case 6 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Column 2", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				switch ( currentColumn2Option )
				{
				    case 0 : 	TAP_SPrint( str, "Filename (without '.rec')" );
								break;
								
					case 1 : 	TAP_SPrint( str, "Filename (without date/time stamps)" );
								break;

					case 2 : 	TAP_SPrint( str, "Full Filename" );
						    	break;

					default : 	TAP_SPrint( str, "[Invalid value]" );
								break;
				}
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;
				
		case 7 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Column 3", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				switch ( currentColumn3Option )
				{
				    case 0 : 	TAP_SPrint( str, "DDD # MMM" );
								break;
								
					case 1 : 	TAP_SPrint( str, "DDD x wks ago" );
								break;

					default : 	TAP_SPrint( str, "[Invalid value]" );
								break;
				}
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;
				
		case 8 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Column 4", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				switch ( currentColumn4Option )
				{
				    case 0 : 	TAP_SPrint( str, "HH:MM (Duration)" );
								break;
								
					case 1 : 	TAP_SPrint( str, "HH:MM ~ HH:MM" );
								break;

					case 2 : 	TAP_SPrint( str, "Duration" );
								break;

					default : 	TAP_SPrint( str, "[Invalid value]" );
								break;
				}
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;
				
		case 9 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Column 5", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				switch ( currentColumn5Option )
				{
				    case 0 : 	TAP_SPrint( str, "Channel Logo" );
								break;
								
					case 1 : 	TAP_SPrint( str, "Recording Size (MB)" );
								break;

					case 2 : 	TAP_SPrint( str, "Recording Size (GB)" );
								break;
								
					case 3 : 	TAP_SPrint( str, "Recording Size (MB, without unit)" );
								break;
								
					case 4 : 	TAP_SPrint( str, "Recording Size (GB, without unit)" );
								break;
								
					case 5 : 	TAP_SPrint( str, "Recording Size (MB/GB)" );
								break;
								
					default : 	TAP_SPrint( str, "[Invalid value]" );
								break;
				}
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;
				
		case 11 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "File Info Lines", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				switch ( currentInfoLineOption )
				{
				    case 0 : 	TAP_SPrint( str, "Event Description" );
								break;
								
					case 1 : 	TAP_SPrint( str, "Event Description & Recording Info." );
								break;

					default : 	TAP_SPrint( str, "[Invalid value]" );
								break;
				}
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;
				
		case 12 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Sort Order", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				switch ( currentSortOrderOption )
				{
				    case 0 : 	TAP_SPrint( str, "Date" );
								break;
								
					case 1 : 	TAP_SPrint( str, "Name" );
								break;

					case 2 : 	TAP_SPrint( str, "Channel Number" );
						    	break;

					case 3 : 	TAP_SPrint( str, "Recording Size" );
								break;
					default : 	TAP_SPrint( str, "[Invalid value]" );
								break;
				}
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;
				
		case 13 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Progress Bars", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				switch ( currentProgressBarOption )
				{
				    case 0 : 	TAP_SPrint( str, "Multi Coloured" );
								break;
								
					case 1 : 	sprintf( str, "Single colour, %% filled" );
						    	break;

					case 2 : 	TAP_SPrint( str, "Single colour, all filled" );
								break;

					case 3 : 	TAP_SPrint( str, "Playback=Green, Recording=Red" );
								break;

					case 4 : 	sprintf( str, "White colour, %% filled" );
								break;

					default : 	TAP_SPrint( str, "[Invalid value]" );
								break;
				}
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;
				
		case 14 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Number of Lines", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
                TAP_SPrint( str, "%d lines per page.", currentNumberLinesOption );
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;
				
		case 15 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Screen Border", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				switch ( currentBorderOption )
				{
				    case 0 : 	TAP_SPrint( str, "Traditional Blue" );
								break;
								
					case 1 : 	sprintf( str, "No background border" );
						    	break;

					default : 	TAP_SPrint( str, "[Invalid value]" );
								break;
				}
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;
				
		case 16 :
				PrintCenter(rgn, CONFIG_E0, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E1,  "Recording Check", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				switch ( currentRecCheckOption )
				{
				    case 0 : 	TAP_SPrint( str, "'.rec' and file attribute" );
								break;
								
					case 1 : 	sprintf( str, "'.rec' only" );
						    	break;

					default : 	TAP_SPrint( str, "[Invalid value]" );
								break;
				}
				TAP_Osd_PutStringAf1622(rgn, CONFIG_X2, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), CONFIG_E2, str, MAIN_TEXT_COLOUR, 0 );
			    break;
				
		case 10 :		
		case 20 :
				TAP_Osd_PutGd( rgn, 53, lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET - 8, &_rowaGd, FALSE );		// No highlight for us
	            TAP_SPrint(str,"%d.",optionNumber);
                TAP_Osd_PutStringAf1622(rgn, 75, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), 700, str, MAIN_TEXT_COLOUR, 0 );

				if (( configOption == 0 ) && ( chosenConfigLine%10 == 0 ))
				{
					TAP_Osd_PutGd( rgn, 116, lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET - 8, &_smallgreenbarGd, FALSE );
				    PrintCenter(rgn, 144, lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET, 244, "Save", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				}
				else PrintCenter(rgn, 144, lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET, 244, "Save", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );

				if (( configOption == 1 ) && ( chosenConfigLine%10 == 0 ))
				{
					TAP_Osd_PutGd( rgn, 278, lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET - 8, &_smallgreenbarGd, FALSE );
					PrintCenter(rgn, 306, lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET, 406, "Cancel", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );
				}
				else PrintCenter(rgn, 306, lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET, 406, "Cancel", MAIN_TEXT_COLOUR, 0, FNT_Size_1622 );

			    TAP_Osd_FillBox( rgn, 437, lineNumber*CONFIG_Y_STEP+CONFIG_Y_OFFSET-8, 3, CONFIG_Y_STEP, FILL_COLOUR );		// one extra column seperator for us
			    
	            TAP_SPrint(str,"Page %d of %d",page,TOTAL_PAGES);
	            TAP_Osd_PutStringAf1622(rgn, 470, (lineNumber * CONFIG_Y_STEP + CONFIG_Y_OFFSET), 700, str, MAIN_TEXT_COLOUR, 0 );
			    
				break;


		default :
			break;
	}


    TAP_Osd_FillBox( rgn, CONFIG_E0, lineNumber*CONFIG_Y_STEP+CONFIG_Y_OFFSET-8, 3, CONFIG_Y_STEP, FILL_COLOUR );		// draw the column seperators
    TAP_Osd_FillBox( rgn, CONFIG_E1, lineNumber*CONFIG_Y_STEP+CONFIG_Y_OFFSET-8, 3, CONFIG_Y_STEP, FILL_COLOUR );

}

//-----------------------------------------------------------------------
//
void CopyConfiguration( void )
{
	CurrentActivationKey   = mainActivationKey;
	currentModelType       = unitModelType;
	currentGMToffsetOption = GMToffsetOption;
	currentRecordingRateOption = recordingRateOption;
	currentColumn1Option       = column1Option;
	currentColumn2Option       = column2Option;
	currentColumn3Option       = column3Option;
	currentColumn4Option       = column4Option;
	currentColumn5Option       = column5Option;
	currentInfoLineOption      = infoLineOption;
	currentSortOrderOption     = sortOrderOption;
	currentProgressBarOption   = progressBarOption;
	currentNumberLinesOption   = numberLinesOption;
    currentBorderOption        = borderOption;
    currentRecCheckOption      = recCheckOption;
}

void SaveConfiguration( void )
{
	mainActivationKey = CurrentActivationKey;
	unitModelType     = currentModelType;
	GMToffsetOption   = currentGMToffsetOption;
	recordingRateOption = currentRecordingRateOption;
	column1Option       = currentColumn1Option;
	column2Option       = currentColumn2Option;
	column3Option       = currentColumn3Option;
	column4Option       = currentColumn4Option;
	column5Option       = currentColumn5Option;
	infoLineOption      = currentInfoLineOption;
	sortOrderOption     = currentSortOrderOption;
    progressBarOption   = currentProgressBarOption;
    numberLinesOption   = currentNumberLinesOption;
    borderOption        = currentBorderOption;
    recCheckOption      = currentRecCheckOption;

    ResetScreenColumns();        // Set column widths according to column options.

	SaveConfigurationToFile();
}



//------------------
//
void CreateConfigWindow(void)
{
	configWindowShowing = TRUE;
	returnFromConfig = FALSE;
	DrawGraphicBorders();
	TAP_Osd_PutStringAf1926( rgn, 58, 40, 390, "Configuration", TITLE_COLOUR, COLOR_Black );
}


void CloseConfigWindow(void)
{
	configWindowShowing = FALSE;
    if (CalledByTSRCommander)   // If the Config Window was called by TSR Commander, then we need to do some extra cleanup.
    {
       CalledByTSRCommander=FALSE;
	   TAP_Osd_FillBox( rgn, 0, 0, 720, 576, 0 );							// clear the screen.  Added for TSR Commander support.
	   TAP_EnterNormal();                                                  // Added for TSR Commander support.  Needed to return to normal.
    }
    else
        returnFromConfig = TRUE;					// will cause a redraw of archive list

	
}


void RedrawConfigPage(int lineNumber)
{
	int i, currentPage, oldPage;
    currentPage = (lineNumber-1)    / LINES_PER_PAGE;   // Calculate page #.  Lines 1-10=page 0   11-20= page 1, etc.
    oldPage     = (oldLineNumber-1) / LINES_PER_PAGE;   // Calculate page #.  Lines 1-10=page 0   11-20= page 1, etc.
    if ( currentPage != oldPage )  // We're on a new page so redraw all lines.
    {
	    for ( i=1+(currentPage*LINES_PER_PAGE); i<=((currentPage+1)*LINES_PER_PAGE) ; i++)
	    {
	        DisplayConfigLine(i);
        }
    }
    oldLineNumber = lineNumber;
	
}


void RedrawConfigWindow( void )
{
	int i;
	
	CreateConfigWindow();
	UpdateListClock();
	CopyConfiguration();

    RedrawConfigPage( chosenConfigLine );

	TAP_Osd_PutStringAf1419( rgn, 58, 490, 666, "Quick keys", COLOR_Gray, 0 );
	TAP_Osd_PutStringAf1419( rgn, 58, 515, 666, "EXIT = quit without saving, RECORD = save and exit", COLOR_Gray, 0 );
}


void DisplayConfigWindow( void )
{
	chosenConfigLine = 10;
	configOption = 1;
	oldLineNumber = LINES_PER_PAGE * 4;   // Initialise the oldLineNumber to force a page redisplay on first pass.
	configWindowShowing = TRUE;
	
	RedrawConfigWindow();
}



//--------------------------------------------------------
//
void DirectEnterActivateKey( void )
{
	enterActivateKey = TRUE;
	keyStage = 1;
	DisplayConfigLine( chosenConfigLine );							// will display the message "Press new key NOW!"
}


void NewActiveKeyHandler( dword key )
{
	if ( IsKeyValid( &localKeyCodes, key ) )
	{
		CurrentActivationKey = key;
	}
	else
	{
	    keyStage = 2;
		DisplayConfigLine( chosenConfigLine );							// will display the message "invalid choice"
		TAP_Delay( 100 );
	}

	enterActivateKey = FALSE;
	keyStage = 0;
	DisplayConfigLine( chosenConfigLine );								// redraw the key desciption
}



//--------------------------------------------------------
//
void ConfigActionHandler(dword key)
{
	int		count, result;

	switch ( chosenConfigLine )
	{
		case 1 :    switch ( key )										// Model type
					{
						case RKEY_VolUp:	if ( currentModelType == TF5800t )
						    				{
											    currentModelType = TF5000t;
												CreateTF5000Keys( &localKeyCodes );
											}
											else
											{
                                                currentModelType = TF5800t;
												CreateTF5800Keys( &localKeyCodes );
											}
											DisplayConfigLine( chosenConfigLine );
											DisplayConfigLine( 3 );					// update the activation key code
											break;

											
						case RKEY_VolDown:	if ( currentModelType == TF5800t )
						    				{
											    currentModelType = TF5000t;
												CreateTF5000Keys( &localKeyCodes );
											}
											else
											{
                                                currentModelType = TF5800t;
												CreateTF5800Keys( &localKeyCodes );
											}
											DisplayConfigLine( chosenConfigLine );
											DisplayConfigLine( 3 );					// update the activation key code
											break;


						case RKEY_Ok :		break;

						default :			break;
					}
					break;

		case 2 :														// Language
				    break;

					
		case 3 :	switch ( key )										// Activation key
					{
						case RKEY_VolUp:	CurrentActivationKey = GetNextKey( &localKeyCodes, CurrentActivationKey );
											DisplayConfigLine( chosenConfigLine );
											break;

						case RKEY_VolDown:	CurrentActivationKey = GetPreviousKey( &localKeyCodes, CurrentActivationKey );
											DisplayConfigLine( chosenConfigLine );
											break;


						case RKEY_Ok :		DirectEnterActivateKey();
											break;

						default :			break;
					}
					break;


		case 4 :	switch ( key )										// GMT Offset 
					{
		            	case RKEY_VolUp:	currentGMToffsetOption = currentGMToffsetOption + 30;
		            	                    if (currentGMToffsetOption > (13 * 60))   //  > 12 hours (ie. 13:30) wrap to -12
		            	                       currentGMToffsetOption = -(12*60);
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	currentGMToffsetOption = currentGMToffsetOption - 30;
		            	                    if (currentGMToffsetOption < -(12 * 60))   //  < -12 hours (ie. -12:30) wrap to +13
		            	                       currentGMToffsetOption = (13*60);
											DisplayConfigLine( chosenConfigLine );
											break;
						default :			break;
					}
					break;

		case 5 :	switch ( key )										// Recording Rate
					{
		            	case RKEY_VolUp:	if (currentRecordingRateOption < 6000) currentRecordingRateOption = currentRecordingRateOption + 100;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentRecordingRateOption > 1000) currentRecordingRateOption = currentRecordingRateOption - 100;
											DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 6 :	switch ( key )										// Column 2 - Filename
					{
		            	case RKEY_VolUp:	if (currentColumn2Option < 2) currentColumn2Option = currentColumn2Option + 1;
		            	                    else currentColumn2Option = 0;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentColumn2Option > 0) currentColumn2Option = currentColumn2Option - 1;
		            	                    else currentColumn2Option = 2;
											DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 7 :	switch ( key )										// Column 3 - Date
					{
		            	case RKEY_VolUp:	if (currentColumn3Option < 1) currentColumn3Option = currentColumn3Option + 1;
		            	                    else currentColumn3Option = 0;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentColumn3Option > 0) currentColumn3Option = currentColumn3Option - 1;
		            	                    else currentColumn3Option = 1;
											DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 8 :	switch ( key )										// Column 4 - Time/Duration
					{
		            	case RKEY_VolUp:	if (currentColumn4Option < 2) currentColumn4Option = currentColumn4Option + 1;
		            	                    else currentColumn4Option = 0;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentColumn4Option > 0) currentColumn4Option = currentColumn4Option - 1;
		            	                    else currentColumn4Option = 2;
											DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 9 :	switch ( key )										// Column 5 - Logo/size
					{
		            	case RKEY_VolUp:	if (currentColumn5Option < 5) currentColumn5Option = currentColumn5Option + 1;
		            	                    else currentColumn5Option = 0;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentColumn5Option > 0) currentColumn5Option = currentColumn5Option - 1;
		            	                    else currentColumn5Option = 5;
											DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 11 :	switch ( key )										// Info Lines
					{
		            	case RKEY_VolUp:	if (currentInfoLineOption < 1) currentInfoLineOption = currentInfoLineOption + 1;
		            	                    else currentInfoLineOption = 0;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentInfoLineOption > 0) currentInfoLineOption = currentInfoLineOption - 1;
		            	                    else currentInfoLineOption = 1;
											DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 12 :	switch ( key )										// Sort Order
					{
		            	case RKEY_VolUp:	if (currentSortOrderOption < 3) currentSortOrderOption = currentSortOrderOption + 1;
		            	                    else currentSortOrderOption = 0;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentSortOrderOption > 0) currentSortOrderOption = currentSortOrderOption - 1;
		            	                    else currentSortOrderOption = 3;
											DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 13 :	switch ( key )										// Progress Bar colours
					{
		            	case RKEY_VolUp:	if (currentProgressBarOption < 4) currentProgressBarOption = currentProgressBarOption + 1;
		            	                    else currentProgressBarOption = 0;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentProgressBarOption > 0) currentProgressBarOption = currentProgressBarOption - 1;
		            	                    else currentProgressBarOption = 4;
											DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 14 :	switch ( key )										// Number Of Lines per page
					{
		            	case RKEY_VolUp:	if (currentNumberLinesOption == 9 ) currentNumberLinesOption = 10;
		            	                    else currentNumberLinesOption = 9;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentNumberLinesOption == 10 ) currentNumberLinesOption = 9;
		            	                    else currentNumberLinesOption = 10;
                                            DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 15 :	switch ( key )										// Background border option
					{
		            	case RKEY_VolUp:	if (currentBorderOption == 0 ) currentBorderOption++;
		            	                    else currentBorderOption = 0;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentBorderOption == 1 ) currentBorderOption--;
		            	                    else currentBorderOption = 1;
                                            DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 16 :	switch ( key )										// Recording Check Option
					{
		            	case RKEY_VolUp:	if (currentRecCheckOption == 0 ) currentRecCheckOption++;
		            	                    else currentRecCheckOption = 0;
											DisplayConfigLine( chosenConfigLine );
											break;

											
						case RKEY_VolDown:	if (currentRecCheckOption == 1 ) currentRecCheckOption--;
		            	                    else currentRecCheckOption = 1;
                                            DisplayConfigLine( chosenConfigLine );
											break;

						default :			break;
					}
					break;

		case 10 :														// bottom line commands : Save, or Cancel
		case 20 :
						switch ( key )
						{
							case RKEY_VolUp:	if ( configOption < 1 ) configOption++;
												else configOption = 0;
												break;

							case RKEY_VolDown:	if ( configOption > 0 ) configOption--;
												else configOption = 1;
												break;


							case RKEY_Ok :		switch ( configOption )
												{
													case 0 :	SaveConfiguration();		// save
																break;
																
													case 1 :	break;						// cancel
													default :	break;
												}

												CloseConfigWindow();		// Close the edit window
												break;

							default :			break;
						}

						if (key != RKEY_Ok)  // If we're not trying exit, redisplay the config line.
                           DisplayConfigLine( chosenConfigLine );
					    break;
						
		default :		break;
	}
}


//------------
//
dword ConfigKeyHandler(dword key)
{
	int i, oldEditLine;

	oldEditLine = chosenConfigLine;

	if ( enterActivateKey ) { NewActiveKeyHandler( key ); return; }			// handle our sub processes
	
	switch ( key )
	{
		case RKEY_ChDown :	configOption = 0;
							if ( chosenConfigLine < CONFIG_LINES )
		    				{
							    chosenConfigLine++;
								DisplayConfigLine( chosenConfigLine - 1);
								RedrawConfigPage( chosenConfigLine );
                                DisplayConfigLine( chosenConfigLine );
							}
							else
							{
							    chosenConfigLine = 1;						// 0=hidden - can't hide once cursor moved
								DisplayConfigLine( CONFIG_LINES );
								RedrawConfigPage( chosenConfigLine );
                                DisplayConfigLine( chosenConfigLine );
							}
							break;

							
		case RKEY_ChUp :	configOption = 0;
							if ( chosenConfigLine > 1 )					// 0=hidden - can't hide once cursor moved
		    				{
							    chosenConfigLine--;
								DisplayConfigLine( chosenConfigLine + 1 );
								RedrawConfigPage( chosenConfigLine );
                                DisplayConfigLine( chosenConfigLine );
							}
							else
							{
							    chosenConfigLine = CONFIG_LINES;
								DisplayConfigLine( 1 );
								RedrawConfigPage( chosenConfigLine );
                                DisplayConfigLine( chosenConfigLine );
							}
								
							break;

							
		case RKEY_1 :
		case RKEY_2 :
		case RKEY_3 :
		case RKEY_4 :
		case RKEY_5 :
		case RKEY_6 :
		case RKEY_7 :
		case RKEY_8 :
		case RKEY_9 :		chosenConfigLine = (key - RKEY_0)+ (((oldEditLine-1)/LINES_PER_PAGE)*LINES_PER_PAGE);				// direct keyboard selection of any line
							DisplayConfigLine( oldEditLine );
							DisplayConfigLine( chosenConfigLine );
							configOption = 0;								// will move the cursor to "Save" when last line selected
							break;

		case RKEY_0 :		chosenConfigLine = 10+ (((oldEditLine-1)/LINES_PER_PAGE)*LINES_PER_PAGE);		// make "0" select the last line
							DisplayConfigLine( oldEditLine );
							DisplayConfigLine( chosenConfigLine );
							break;

							
		case RKEY_Ok :
		case RKEY_TvRadio :
		case RKEY_VolUp :
		case RKEY_VolDown : ConfigActionHandler( key );
							break;

		case RKEY_Recall :	CopyConfiguration();					// reload the original data
							oldLineNumber = LINES_PER_PAGE * 4;     // Initialise the oldLineNumber to force a page redisplay.RedrawConfigWindow();
							RedrawConfigWindow();
							break;
							
		case RKEY_Record :	SaveConfiguration();
							CloseConfigWindow();					// Close the edit window
							break;


		case RKEY_Exit : 	CloseConfigWindow();					// Close the edit window
							break;
							
		case RKEY_Mute :	return key;


		default :
			break;
	}
	return 0;
}



//------------
//
void InitialiseConfigRoutines(void)
{
	configWindowShowing = FALSE;
	enterActivateKey    = FALSE;
	chosenConfigLine    = 0;
	oldLineNumber       = LINES_PER_PAGE * 4;   // Initialise the oldLineNumber to force a page redisplay on first pass.
	configOption        = 0;
	keyStage            = 0;
	returnFromConfig    = FALSE;

//	CreateTF5800Keys( &localKeyCodes );
	CreateTF5000Keys( &localKeyCodes );
}


void TerminateConfigMenu( void )
{
	KeyDestory( &localKeyCodes );
}
