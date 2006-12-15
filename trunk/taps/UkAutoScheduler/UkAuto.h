struct schDataTag
{
	byte searchStatus;
	byte searchOptions;
	char searchTerm[132];
	char searchFolder[132];
	dword searchStartTime;
	dword searchEndTime;
	byte searchTvRadio;
	word searchStartSvcNum;
	word searchEndSvcNum;
	dword searchStartPadding;
	dword searchEndPadding;
	word searchAttach;
	byte searchDay;
	byte searchKeepMode;
	byte searchKeepValue;
};

struct schMoveTag
{
	bool moveEnabled;
	char moveFileName[132];
	char moveFolder[132];
	dword moveStartTime;
	dword moveEndTime;
	byte moveFailedCount;
};

#define	SCH_USER_DATA_STATUS_DISABLED		0x00
#define	SCH_USER_DATA_STATUS_RECORD_ALL		0x01
#define	SCH_USER_DATA_STATUS_WATCH		0x02
#define	SCH_USER_DATA_STATUS_RECORD_NEW		0x03

#define	SCH_USER_DATA_OPTIONS_EVENTNAME		0x01
#define	SCH_USER_DATA_OPTIONS_DESCRIPTION	0x02
#define	SCH_USER_DATA_OPTIONS_EXT_INFO		0x04
#define	SCH_USER_DATA_OPTIONS_EXACT_MATCH	0x08
#define	SCH_USER_DATA_OPTIONS_ANY_CHANNEL	0x10
#define	SCH_USER_DATA_OPTIONS_ADVANCED_SEARCH	0x20

#define SCH_MAX_SEARCHES			150
#define SCH_MAX_MOVES				80

#define SCH_TV					0
#define SCH_RADIO				1

#define SEARCH_FILENAME		"UkAutoSearch.txt"
#define SEARCH_INFO		"UK Auto Scheduler Search List v0.3\r\n"

#define MOVE_FILENAME		"UkAutoMove.txt"
#define MOVE_INFO		"UK Auto Scheduler Move List v0.1\r\n"

#define REMOTE_FILENAME		"UkAutoRemote.txt"

enum
{
	SCH_SERVICE_INITIALISE = 0,
	SCH_SERVICE_RESET_SEARCH,
	SCH_SERVICE_WAIT_TO_SEARCH,
	SCH_SERVICE_CHECK_FOR_REMOTE_SEARCHES,
	SCH_SERVICE_UPDATE_SEARCH_LIST,
	SCH_SERVICE_BEGIN_SEARCH,
	SCH_SERVICE_INITIALISE_EPG_DATA,
	SCH_SERVICE_PERFORM_SEARCH,
	SCH_SERVICE_NEXT_USER_SEARCH,
	SCH_SERVICE_NEXT_EVENT,
	SCH_SERVICE_NEXT_CHANNEL,
	SCH_SERVICE_COMPLETE
};

enum
{
	SCH_ATTACH_POS_NONE = 0,
	SCH_ATTACH_POS_PREFIX,
	SCH_ATTACH_POS_APPEND
};

enum
{
	SCH_ATTACH_TYPE_DATE = 0,
	SCH_ATTACH_TYPE_NUMBER,
	SCH_ATTACH_TYPE_TIME
};

enum
{
	SCH_CONFIG_SEARCH_PERIOD_TEN_MINS = 0,
	SCH_CONFIG_SEARCH_PERIOD_ONE_HOUR,
	SCH_CONFIG_SEARCH_PERIOD_SPECIFIED
};

enum
{
	SCH_CONFIG_DATE_FORMAT_DD_DOT_MM_DOT_YY = 0,
	SCH_CONFIG_DATE_FORMAT_DD_DOT_MM_DOT_YYYY,
	SCH_CONFIG_DATE_FORMAT_YY_DOT_MM_DOT_DD,
	SCH_CONFIG_DATE_FORMAT_YYYY_DOT_MM_DOT_DD,
	SCH_CONFIG_DATE_FORMAT_DDMMYY,
	SCH_CONFIG_DATE_FORMAT_DDMMYYYY,
	SCH_CONFIG_DATE_FORMAT_YYMMDD,
	SCH_CONFIG_DATE_FORMAT_YYYYMMDD,
	SCH_CONFIG_DATE_FORMAT_DD_SLASH_MM_SLASH_YY,
	SCH_CONFIG_DATE_FORMAT_DD_SLASH_MM_SLASH_YYYY,
	SCH_CONFIG_DATE_FORMAT_YY_SLASH_MM_SLASH_DD,
	SCH_CONFIG_DATE_FORMAT_YYYY_SLASH_MM_SLASH_DD,
	SCH_CONFIG_DATE_FORMAT_DD_DOT_MM,
	SCH_CONFIG_DATE_FORMAT_MM_DOT_DD,
	SCH_CONFIG_DATE_FORMAT_DDMM,
	SCH_CONFIG_DATE_FORMAT_MMDD,
	SCH_CONFIG_DATE_FORMAT_DD_SLASH_MM,
	SCH_CONFIG_DATE_FORMAT_MM_SLASH_DD
};

enum
{
	SCH_CONFIG_TIME_FORMAT_HH_COLON_MM = 0,
	SCH_CONFIG_TIME_FORMAT_HH_DOT_MM,
	SCH_CONFIG_TIME_FORMAT_HHMM
};

enum
{
	SCH_MOVE_SERVICE_INITIALISE = 0,
	SCH_MOVE_SERVICE_WAIT_TO_CHECK,
	SCH_MOVE_SERVICE_CHECK_MOVE,
	SCH_MOVE_SERVICE_CHECK_ARCHIVE,
	SCH_MOVE_SERVICE_CHECK_TARGET_FOLDER,
	SCH_MOVE_SERVICE_PERFORM_MOVE,
	SCH_MOVE_SERVICE_MOVE_NOT_SUCCESSFUL,
	SCH_MOVE_SERVICE_NEXT_MOVE,
	SCH_MOVE_SERVICE_DELETE_EXPIRED_MOVES,
	SCH_MOVE_SERVICE_COMPLETE,
	SCH_MOVE_LOG_ARCHIVE
};

enum
{
	SCH_KEEP_SERVICE_INITIALISE = 0,
	SCH_KEEP_SERVICE_WAIT_TO_CHECK,
	SCH_KEEP_SERVICE_BEGIN,
	SCH_KEEP_SERVICE_CHECK_FOLDER,
	SCH_KEEP_SERVICE_NEXT_KEEP,
	SCH_KEEP_SERVICE_COMPLETE,
	SCH_KEEP_SERVICE_NOT_AVAILABLE
};

enum
{
	SCH_SHOW_SERVICE_INITIALISE = 0,
	SCH_SHOW_SERVICE_BEGIN_SEARCH,
	SCH_SHOW_SERVICE_INITIALISE_EPG_DATA,
	SCH_SHOW_SERVICE_PERFORM_SEARCH,
	SCH_SHOW_SERVICE_NEXT_EVENT,
	SCH_SHOW_SERVICE_NEXT_CHANNEL,
	SCH_SHOW_SERVICE_NEXT_SEARCH,
	SCH_SHOW_SERVICE_WAIT_FOR_PROGRESS,
	SCH_SHOW_SERVICE_DISPLAY_RESULTS,
	SCH_SHOW_SERVICE_COMPLETE
};

enum
{
	SCH_IDLE_HANDLER_INITIALISE = 0,
	SCH_IDLE_HANDLER_SERVICE
};

enum
{
	KEYBOARD_ENGLISH = 0,
	KEYBOARD_FINNISH,
	KEYBOARD_GERMAN
};

enum
{
	SCH_FILE_REMOTE_LOCATION_PROGRAMFILES = 0,
	SCH_FILE_REMOTE_LOCATION_AUTOSTART
};

enum
{
	SCH_MAIN_CONFLICT_DISABLED = 0,
	SCH_MAIN_CONFLICT_COMBINE,
	SCH_MAIN_CONFLICT_SEPARATE,
	SCH_MAIN_CONFLICT_SEPARATE_KEEP_END_PADDING
};

enum
{
	SCH_MAIN_TIMER_SUCCESS = 0,
	SCH_MAIN_TIMER_SUCCESS_WITH_MODIFICATIONS,
	SCH_MAIN_TIMER_FAILED
};
