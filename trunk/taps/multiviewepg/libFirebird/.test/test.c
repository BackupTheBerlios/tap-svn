/************************************************/
/* USE ONLY TO TEST LINKING AGAINST libFireBird */
/* CHECKS ALL libFireBird FUNCTIONS             */
/************************************************/

#include "tap.h"
#include "../av/FBLib_av.h"
#include "../dialog/FBLib_dialog.h"
#include "../flash/FBLib_flash.h"
#include "../hdd/FBLib_hdd.h"
#include "../hook/FBLib_hook.h"
#include "../imem/imem.h"
#include "../ini/FBLib_ini.h"
#include "../libFireBird.h"
#include "../main/FBLib_main.h"
#include "../mpvfd/FBLib_mpvfd.h"
#include "../rec/FBLib_rec.h"
#include "../shutdown/FBLib_shutdown.h"
#include "../string/FBLib_string.h"
#include "../tap/FBLib_tap.h"
#include "../tapcom/FBLib_tapcom.h"

TAP_ID(0);
TAP_PROGRAM_NAME("");
TAP_AUTHOR_NAME("");
TAP_DESCRIPTION("");
TAP_ETCINFO(__DATE__);


dword TAP_EventHandler (word event, dword param1, dword param2)
{
  (void) event;
  (void) param2;

  return param1;
}


int TAP_Main (void)
{
  AddTime(0, 0);
  BMP_WriteHeader(NULL, 0, 0);
  BootReason();
  BuildWindowBorder();
  BuildWindowInfo();
  BuildWindowLine();
  BuildWindowLineSelected();
  BuildWindowScrollBar();
  BuildWindowTitle();
  busyWait();
  CalcAbsSectorFromFAT(NULL, 0);
  CalcPrepare();
  CalcTopIndex(0, 0);
  Callback(0, NULL, 0, 0, 0, 0);
  CallbackHelper(NULL, NULL, 0, 0, 0, 0);
  CallBIOS(0, 0, 0, 0, 0);
  CallFirmware(0, 0, 0, 0, 0);
  CallTraceEnable(FALSE);
  CallTraceEnter(NULL);
  CallTraceExit(NULL);
  CallTraceInit();
  CaptureScreen(0, 0, 0, NULL, 0, 0);
  ChangeDirRoot();
  CheckSelectable(0, 0);
  combineVfdData(NULL, NULL);
  compact(NULL, 0);
  CompressBlock(NULL, 0, NULL);
  CompressedTFDSize(NULL, 0, NULL);
  CompressTFD(NULL, 0, NULL, 0, 0, NULL);
  CRC16(0, NULL, 0);
  CRC32 (0, NULL, 0);
  Delay(0);
  DialogEvent(NULL, NULL, NULL);
  DialogMsgBoxButtonAdd(NULL, FALSE);
  DialogMsgBoxExit();
  DialogMsgBoxInit(NULL, NULL, NULL, NULL);
  DialogMsgBoxShow();
  DialogMsgBoxShowInfo(0);
  DialogMsgBoxShowOK();
  DialogMsgBoxShowOKCancel(0);
  DialogMsgBoxShowYesNo(0);
  DialogMsgBoxShowYesNoCancel(0);
  DialogMsgBoxTitleSet(NULL, NULL);
  DialogProfileChange(NULL);
  DialogProfileCheck(NULL, NULL, FALSE);
  DialogProfileLoad(NULL);
  DialogProfileLoadDefault();
  DialogProfileLoadMy(NULL, FALSE);
  DialogProfileSave(NULL);
  DialogProfileSaveDefault();
  DialogProfileScrollBehaviourChange(FALSE, FALSE);
  DialogProgressBarExit();
  DialogProgressBarInit(NULL, NULL, 0, 0, NULL, 0, 0);
  DialogProgressBarSet(0, 0);
  DialogProgressBarShow();
  DialogProgressBarTitleSet(NULL);
  DialogWindowChange(NULL, FALSE);
  DialogWindowCursorChange(FALSE);
  DialogWindowCursorSet(0);
  DialogWindowExit();
  DialogWindowHide();
  DialogWindowInfoAddIcon(0, 0, NULL);
  DialogWindowInfoAddS(0, 0, 0, NULL, 0, 0, 0, 0, 0);
  DialogWindowInfoDeleteAll();
  DialogWindowInit(NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, 0, 0, 0);
  DialogWindowItemAdd(NULL, 0, NULL, 0, FALSE, FALSE, 0, NULL);
  DialogWindowItemAddSeparator();
  DialogWindowItemChangeFlags(0, FALSE, FALSE);
  DialogWindowItemChangeIcon(0, 0, NULL);
  DialogWindowItemChangeParameter(0, NULL, 0);
  DialogWindowItemChangeValue(0, NULL, 0);
  DialogWindowItemDelete(0);
  DialogWindowItemDeleteAll();
  DialogWindowRefresh();
  DialogWindowReInit(0, 0, 0, 0, 0, 0);
  DialogWindowScrollDown();
  DialogWindowScrollDownPage();
  DialogWindowScrollUp();
  DialogWindowScrollUpPage();
  DialogWindowShow();
  DialogWindowTabulatorSet(0, 0);
  DialogWindowTitleChange(NULL, NULL, NULL);
  DialogWindowTypeChange(0);
  DrawMsgBoxButtons();
  DrawMsgBoxTitle();
  DrawOSDLine(0, 0, 0, 0, 0, 0);
  DrawProgressBarBar(0, 0);
  DrawProgressBarTitle();
  DrawWindowBorder();
  DrawWindowInfo();
  DrawWindowLine(0);
  DrawWindowLines();
  DrawWindowScrollBar();
  DrawWindowTitle();
  EndMessageWin();
  exitHook();
  ExtractLine(NULL, NULL);
  FileSelector(NULL, NULL, NULL, 0);
  FileSelectorKey(0, 0);
  FindDBTrack();
  FindInstructionSequence(NULL, NULL, 0, 0, 0, 0);
  findSendToVfdDisplay(0, 0);
  FlashAddFavourite(NULL, 0, FALSE);
  FlashDeleteFavourites();
  FlashFindEndOfServiceNameTableAddress();
  FlashFindEndOfServiceTableAddress(0);
  FlashFindServiceAddress(0, 0, 0, 0);
  FlashFindTransponderIndex(0, 0, 0);
  FlashGetBlockStartAddress(0);
  FlashGetChannelNumber(0, 0, 0, 0);
  FlashGetSatelliteByIndex(0);
  FlashGetServiceByIndex(0, FALSE);
  FlashGetServiceByName (NULL, FALSE);
  FlashGetTransponderCByIndex(0);
  FlashGetTransponderSByIndex(0, 0);
  FlashGetTransponderTByIndex(0);
  FlashGetTrueLocalTime(0, 0);
  FlashGetType();
  FlashInitialize(0);
  FlashProgram();
  FlashReindexFavourites(0, 0, 0);
  FlashReindexTimers(0, 0, 0);
  FlashRemoveCASServices(FALSE);
  FlashRemoveServiceByIndex(0, FALSE);
  FlashRemoveServiceByIndexString(NULL, FALSE);
  FlashRemoveServiceByLCN(NULL, FALSE);
  FlashRemoveServiceByName(NULL, FALSE);
  FlashRemoveServiceByPartOfName(NULL, FALSE);
  FlashRemoveServiceByUHF(NULL, FALSE, FALSE);
  FlashServiceAddressToServiceIndex(NULL);
  FlashWrite(NULL, NULL, 0, NULL);
  FlushCache(NULL, 0);
  FreeOSDRegion(0);
  fwHook(0);
  GetAudioTrackPID(0, NULL);
  GetClusterPointer(0);
  GetCurrentEvent(NULL);
  GetEEPROMAddress();
  GetEEPROMPin();
  GetFrameBufferPixel(0, 0);
  GetFrameSize(0, 0);
  GetFWInfo(0, 0, 0, 0, 0, 0, 0, 0);
  GetHeapParameter(NULL, 0);
  GetLine(NULL, 0);
  GetOSDMapAddress();
  GetOSDRegionHeight(0);
  GetOSDRegionWidth(0);
  GetPinStatus();
  GetPIPPosition(NULL, NULL, NULL, NULL);
  getRECSlotAddress();
  GetSysOsdControl(0);
  GetToppyString(0);
  HasEnoughItemMemory();
  HDD_AAM_Disable();
  HDD_AAM_Enable(0);
  HDD_APM_Disable();
  HDD_APM_Enable(0);
  HDD_BigFile_Read(NULL, 0, 0, NULL);
  HDD_BigFile_Size(NULL);
  HDD_BigFile_Write(NULL, 0, 0, NULL);
  HDD_ChangeDir(NULL);
  HDD_DecodeRECHeader(NULL, NULL);
  HDD_EncodeRECHeader(NULL, NULL, 0);
  HDD_FappendOpen(NULL);
  HDD_FappendWrite(NULL, NULL);
  HDD_FindPCR(NULL, 0);
  HDD_FindPMT(NULL, 0, NULL);
  HDD_FreeSize();
  HDD_GetClusterSize();
  HDD_GetFileDir(NULL, 0, NULL);
  HDD_GetFirmwareDirCluster();
  HDD_GetHddID(NULL, NULL, NULL);
  HDD_IdentifyDevice(NULL);
  HDD_isAnyRecording();
  HDD_isCryptedStream(NULL, 0);
  HDD_isRecording(0);
  HDD_LiveFS_GetChainLength(0);
  HDD_LiveFS_GetFAT1Address();
  HDD_LiveFS_GetFAT2Address();
  HDD_LiveFS_GetFirstCluster(0);
  HDD_LiveFS_GetLastCluster(0);
  HDD_LiveFS_GetNextCluster(0);
  HDD_LiveFS_GetPreviousCluster(0);
  HDD_LiveFS_GetRootDirAddress();
  HDD_LiveFS_GetSuperBlockAddress();
  HDD_MakeNewRecName(NULL, 0);
  HDD_Move(NULL, NULL, NULL);
  HDD_ReadClusterDMA(0, NULL);
  HDD_ReadSector(0, 0);
  HDD_ReadSectorDMA(0, 0, NULL);
  HDD_RECSlotGetAddress(0);
  HDD_RECSlotIsPaused(0);
  HDD_RECSlotPause(0, FALSE);
  HDD_RECSlotSetDuration(0, 0);
  HDD_SetCryptFlag(NULL, 0);
  HDD_SetFileDateTime(NULL, 0, 0, 0);
  HDD_SetSkipFlag (NULL, FALSE);
  HDD_SetStandbyTimer(0);
  HDD_Smart_DisableAttributeAutoSave();
  HDD_Smart_DisableOperations();
  HDD_Smart_EnableAttributeAutoSave();
  HDD_Smart_EnableOperations();
  HDD_Smart_ExecuteOfflineImmediate(0);
  HDD_Smart_ReadData(0);
  HDD_Smart_ReadThresholdData(0);
  HDD_Smart_ReturnStatus();
  HDD_Stop();
  HDD_TAP_Callback(0, NULL, 0, 0, 0, 0);
  HDD_TAP_Disable(0, 0);
  HDD_TAP_DisableAll(0);
  HDD_TAP_DisabledEventHandler(0, 0, 0);
  HDD_TAP_GetCurrentDir(NULL);
  HDD_TAP_GetCurrentDirCluster();
  HDD_TAP_GetIDByFileName(NULL);
  HDD_TAP_GetIDByIndex(0);
  HDD_TAP_GetIndexByID(0);
  HDD_TAP_GetInfo(0, NULL);
  HDD_TAP_GetStartParameter();
  HDD_TAP_isAnyRunning();
  HDD_TAP_isBatchMode();
  HDD_TAP_isDisabled(0);
  HDD_TAP_isDisabledAll();
  HDD_TAP_isRunning(0);
  HDD_TAP_SendEvent(0, FALSE, 0, 0, 0);
  HDD_TAP_SetCurrentDirCluster(0);
  HDD_TAP_Start(NULL, FALSE, NULL, NULL);
  HDD_TAP_StartedByTAP();
  HDD_TAP_Terminate(0);
  HDD_TouchFile(NULL);
  HDD_TranslateDirCluster(0, NULL);
  HDD_TruncateFile(NULL, 0);
  HDD_Write(NULL, 0, NULL);
  HDD_WriteClusterDMA(0, NULL);
  HDD_WriteSectorDMA(0, 0, NULL);
  HookEnable(0, 0);
  HookExit();
  HookIsEnabled(0);
  HookMIPS_Clear(0, 0, 0);
  HookMIPS_Set(0, 0, 0);
  HookSet(0, 0);
  IMEM_Alloc(0);
  IMEM_Init(0);
  IMEM_isInitialized();
  IMEM_Compact();
  IMEM_Free(NULL);
  IMEM_GetInfo(NULL, NULL);
  IMEM_Kill();
  InfoTestGrid();
  INICloseFile();
  INIFindStartEnd(NULL, NULL, NULL, 0);
  INIGetARGB(NULL, NULL, NULL, NULL, NULL, 0);
  INIGetHexByte(NULL, 0, 0, 0);
  INIGetHexDWord(NULL, 0, 0, 0);
  INIGetHexWord(NULL, 0, 0, 0);
  INIGetInt(NULL, 0, 0, 0);
  INIGetString(NULL, NULL, NULL, 0);
  INIKillKey(NULL);
  INIOpenFile(NULL);
  INISaveFile(NULL);
  INISetARGB(NULL, 0, 0, 0, 0);
  INISetComment(NULL);
  INISetHexByte(NULL, 0);
  INISetHexDWord(NULL, 0);
  INISetHexWord(NULL, 0);
  INISetInt(NULL, 0);
  INISetString(NULL, NULL);
  initCodeWrapper(0);
  InitTAPAPIFix();
  InitTAPex();
  InteractiveGetStatus();
  InteractiveSetStatus(FALSE);
  intLock();
  intUnlock(0);
  isAnyOSDVisible(0, 0, 0, 0);
  isLegalChar(0, 0);
  isMasterpiece();
  isMPMenu();
  iso639_1(0);
  isOSDRegionAlive(0);
  isValidChannel(NULL);
  LangGetString(0);
  LangLoadStrings(NULL, 0, 0);
  LangUnloadStrings();
  Log(NULL, NULL, FALSE, 0, NULL);
  LowerCase(NULL);
  MakeValidFileName(NULL, 0);
  MHEG_Status();
  MPDisplayClearDisplay();
  MPDisplayClearSegments(0, 0);
  MPDisplayDisplayLongString(NULL);
  MPDisplayDisplayShortString(NULL);
  MPDisplayGetDisplayByte(0);
  MPDisplayGetDisplayMask(0);
  MPDisplayInstallMPDisplayFwHook();
  MPDisplaySetAmFlag(0);
  MPDisplaySetColonFlag(0);
  MPDisplaySetDisplayByte(0, 0);
  MPDisplaySetDisplayMask(0, 0);
  MPDisplaySetDisplayMemory(NULL);
  MPDisplaySetDisplayMode(0);
  MPDisplaySetPmFlag(0);
  MPDisplaySetSegments(0, 0);
  MPDisplayToggleSegments(0, 0);
  MPDisplayUninstallMPDisplayFwHook();
  MPDisplayUpdateDisplay();
  Now(NULL);
  OSDCopy(0, 0, 0, 0, 0, 0, 0);
  OSDLinesForeDirty(FALSE);
  ParseLine(NULL, NULL, 0);
  ProfileDirty();
  ProfileInit();
  ProfileLoad(NULL, FALSE);
  ProfileMayReload();
  ReadEEPROM(0, 0, NULL);
  ReadIICRegister(0, 0, 0, 0, NULL);
  Reboot(0);
  ReceiveSector(0);
  RTrim(NULL);
  SaveBitmap(NULL, 0, 0, NULL);
  SendEvent(0, 0, 0, 0);
  SendEventHelper(NULL, 0, 0, 0);
  SendHDDCommand(0, 0, 0, 0, 0, 0, 0);
  SendToFP(NULL);
  SeparatePathComponents(NULL, NULL, NULL, NULL);
  SetCrashBehaviour(0);
  setSymbol14(0, 0);
  setSymbol17(0, 0);
  ShowMessageWin(NULL, NULL, NULL, 0);
  ShowMessageWindow(NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  Shutdown(0);
  SoundSinus(0, 0, 0);
  StrEndsWith(NULL, NULL);
  stricstr(NULL, NULL);
  SubtitleGetStatus();
  SubtitleSetStatus(FALSE);
  SuppressedAutoStart();
  SwapDWords(0);
  SwapWords(0);
  TAP_Osd_PutFreeColorGd(0, 0, 0, NULL, FALSE, 0);
  TAPCOM_CloseChannel(NULL);
  TAPCOM_Finish(NULL, 0);
  TAPCOM_GetChannel(0, NULL, NULL, NULL, NULL);
  TAPCOM_GetReturnValue(NULL);
  TAPCOM_GetStatus(NULL);
  TAPCOM_LastAlive(NULL);
  TAPCOM_OpenChannel(0, 0, 0, NULL);
  TAPCOM_Reject(NULL);
  TAPCOM_StillAlive(NULL);
  TFDSize(NULL);
  TimeDiff(0, 0);
  TimeFormat(0, 0, 0);
  TunerGet(0);
  TunerSet(0);
  UncompressBlock(NULL, 0, NULL, 0);
  UncompressedFirmwareSize(NULL);
  UncompressedLoaderSize(NULL);
  UncompressedTFDSize(NULL);
  UncompressFirmware(NULL, NULL, NULL);
  UncompressLoader(NULL, NULL, NULL);
  UncompressTFD(NULL, NULL, NULL);
  UpperCase(NULL);
  ValidFileName(NULL, 0);
  WindowDirty();
  WriteIICRegister(0, 0, 0, 0, NULL);
  YUV2RGB(0, 0, 0, NULL, NULL, NULL);
  YUV2RGB2(0, 0, 0, NULL, NULL, NULL);

  return 0;
}
