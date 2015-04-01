/*
 * Copyright (c) 1995-2014, Paul Mattes.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the names of Paul Mattes nor the names of his contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY PAUL MATTES "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL PAUL MATTES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *	resources.h
 *		x3270/c3270/s3270/tcl3270 resource and option names.
 */

/* Resources. */
#define ResAcs			"acs"
#define ResAcceptHostname	"acceptHostname"
#define ResActiveIcon		"activeIcon"
#define ResAdVersion		"adVersion"
#define ResAidWait		"aidWait"
#define ResAllBold		"allBold"
#define ResAllowResize		"allowResize"
#define ResAltCursor		"altCursor"
#define ResAltScreen		"altScreen"
#define ResAplCircledAlpha	"aplCircledAlpha"
#define ResAplMode		"aplMode"
#define ResAsciiBoxDraw		"asciiBoxDraw"
#define ResAssocCommand		"printer.assocCommandLine"
#define ResAutoShortcut		"autoShortcut"
#define ResBaselevelTranslations	"baselevelTranslations"
#define ResBellMode		"bellMode"
#define ResBellVolume		"bellVolume"
#define ResBindLimit		"bindLimit"
#define ResBlankFill		"blankFill"
#define ResBoldColor		"boldColor"
#define ResBsdTm		"bsdTm"
#define ResCaDir		"caDir"
#define ResCaFile		"caFile"
#define ResCbreak		"cbreak"
#define ResCertFile		"certFile"
#define ResCertFileType		"certFileType"
#define ResChainFile		"chainFile"
#define ResCharClass		"charClass"
#define ResCharset		"charset"
#define ResCharsetList		"charsetList"
#define ResColor8		"color8"
#define ResColorBackground	"colorBackground"
#define ResColorScheme		"colorScheme"
#define ResCommandTimeout	"commandTimeout"
#define ResComposeMap		"composeMap"
#define ResConfDir		"confDir"
#define ResConnectFileName	"connectFileName"
#define ResConsoleColorForHostColor "consoleColorForHostColor"
#define ResCrosshair		"crosshair"
#define ResCursesColorFor	"cursesColorFor"
#define ResCursesColorForDefault ResCursesColorFor "Default"
#define ResCursesColorForHostColor ResCursesColorFor "HostColor"
#define ResCursesColorForIntensified ResCursesColorFor "Intensified"
#define ResCursesColorForProtected ResCursesColorFor "Protected"
#define ResCursesColorForProtectedIntensified ResCursesColorFor "ProtectedIntensified"
#define ResCursesKeypad		"cursesKeypad"
#define ResCursorBlink		"cursorBlink"
#define ResCursorColor		"cursorColor"
#define ResCursorPos		"cursorPos"
#define ResDebugTracing		"debugTracing"
#define ResDefaultFgBg		"defaultFgBg"
#define ResDefScreen		"defScreen"
#define ResDevName		"devName"
#define ResDftBufferSize	"dftBufferSize"
#define ResDisconnectClear	"disconnectClear"
#define ResDoConfirms		"doConfirms"
#define ResDbcsCgcsgid		"dbcsCgcsgid"
#define ResDsTrace		"dsTrace"
#define ResEmulatorFont		"emulatorFont"
#define ResEof			"eof"
#define ResErase		"erase"
#define ResEventTrace		"eventTrace"
#define ResExtended		"extended"
#define ResFixedSize		"fixedSize"
#define ResFtAllocation		"ftAllocation"
#define ResFtAvblock		"ftAvblock"
#define ResFtBlksize		"ftBlksize"
#define ResFtCr			"ftCr"
#define ResFtCodePage		"ftCodePage"
#define ResFtDirection		"ftDirection"
#define ResFtExist		"ftExist"
#define ResFtHost		"ftHost"
#define ResFtHostFile		"ftHostFile"
#define ResFtLocalFile		"ftLocalFile"
#define ResFtLrecl		"ftLrecl"
#define ResFtMode		"ftMode"
#define ResFtPrimarySpace	"ftPrimarySpace"
#define ResFtRecfm		"ftRecfm"
#define ResFtRemap		"ftRemap"
#define ResFtSecondarySpace	"ftSecondarySpace"
#define ResHighlightBold	"highlightBold"
#define ResHostColorFor		"hostColorFor"
#define ResHostColorForDefault ResHostColorFor "Default"
#define ResHostColorForIntensified ResHostColorFor "Intensified"
#define ResHostColorForProtected ResHostColorFor "Protected"
#define ResHostColorForProtectedIntensified ResHostColorFor "ProtectedIntensified"
#define ResHostname		"hostname"
#define ResHostsFile		"hostsFile"
#define ResHttpd		"httpd"
#define ResIconFont		"iconFont"
#define ResIconLabelFont	"iconLabelFont"
#define ResIcrnl		"icrnl"
#define ResIdleCommand		"idleCommand"
#define ResIdleCommandEnabled	"idleCommandEnabled"
#define ResIdleTimeout		"idleTimeout"
#define ResInlcr		"inlcr"
#define ResInputColor		"inputColor"
#define ResInputMethod		"inputMethod"
#define ResIntr			"intr"
#define ResInvertKeypadShift	"invertKeypadShift"
#define ResKeyFile		"keyFile"
#define ResKeyFileType		"keyFileType"
#define ResKeymap		"keymap"
#define ResKeypad		"keypad"
#define ResKeypadBackground	"keypadBackground"
#define ResKeypadOn		"keypadOn"
#define ResKeyPasswd		"keyPasswd"
#define ResKill			"kill"
#define ResLabelIcon		"labelIcon"
#define ResLightPenPrimary	"lightPenPrimary"
#define ResLineWrap		"lineWrap"
#define ResLnext		"lnext"
#define ResLocalCp		"localCp"
#define ResLoginMacro		"loginMacro"
#define ResLockedCursor		"lockedCursor"
#define ResLuCommandLine	"printer.luCommandLine"
#define ResM3279		"m3279"
#define ResMacros		"macros"
#define ResMarginedPaste	"marginedPaste"
#define ResMaxRecent		"maxRecent"
#define ResMenuBar		"menuBar"
#define ResMetaEscape		"metaEscape"
#define ResModel		"model"
#define ResModifiedSel		"modifiedSel"
#define ResModifiedSelColor	"modifiedSelColor"
#define ResMono			"mono"
#define ResMonoCase		"monoCase"
#define ResMouse		"mouse"
#define ResNewEnviron		"newEnviron"
#define ResNoOther		"noOther"
#define ResNoPrompt		"noPrompt"
#define ResNormalColor		"normalColor"
#define ResNormalCursor		"normalCursor"
#define ResNumericLock		"numericLock"
#define ResNvtMode		"nvtMode"
#define ResOerrLock		"oerrLock"
#define ResOnce			"once"
#define ResOnlcr		"onlcr"
#define ResOverlayPaste		"overlayPaste"
#define ResOversize		"oversize"
#define ResPort			"port"
#define ResPreeditType		"preeditType"
#define ResPrinterCodepage	"printer.codepage"
#define ResPrinterCommand	"printer.command"
#define ResPrinterLu		"printerLu"
#define ResPrinterName		"printer.name"
#define ResPrinterOptions	"printer.options"

#define ResProxy		"proxy"
#define ResQuit			"quit"
#define ResQrBgColor		"qrBgColor"
#define ResReconnect		"reconnect"
#define ResRectangleSelect	"rectangleSelect"
#define ResReverseVideo		"reverseVideo"
#define ResRprnt		"rprnt"
#define ResSaveLines		"saveLines"
#define ResSchemeList		"schemeList"
#define ResScreenTrace		"screenTrace"
#define ResScreenTraceFile	"screenTraceFile"
#define ResScripted		"scripted"
#define ResScriptPort		"scriptPort"
#define ResScrollBar		"scrollBar"
#define ResSecure		"secure"
#define ResSelectBackground	"selectBackground"
#define ResSelfSignedOk		"selfSignedOk"
#define ResSbcsCgcsgid		"sbcsCgcsgid"
#define ResShowTiming		"showTiming"
#define ResSocket		"socket"
#define ResSuppressActions	"suppressActions"
#define ResSuppressHost		"suppressHost"
#define ResSuppressFontMenu	"suppressFontMenu"
#define ResSuppress		"suppress"
#define ResTermName		"termName"
#define ResTitle		"title"
#define ResTls			"tls"
#define ResTrace		"trace"
#define ResTraceDir		"traceDir"
#define ResTraceFile		"traceFile"
#define ResTraceFileSize	"traceFileSize"
#define ResTraceMonitor		"traceMonitor"
#define ResTypeahead		"typeahead"
#define ResUnderscore		"underscore"
#define ResUnlockDelay		"unlockDelay"
#define ResUnlockDelayMs	"unlockDelayMs"
#define ResUseCursorColor	"useCursorColor"
#define ResUser			"user"
#define ResUtf8			"utf8"
#define ResV			"v"
#define ResVerifyHostCert	"verifyHostCert"
#define ResVisibleControl	"visibleControl"
#define ResVisualBell		"visualBell"
#define ResVisualSelect		"visualSelect"
#define ResVisualSelectColor	"visualSelectColor"
#define ResWaitCursor		"waitCursor"
#define ResWerase		"werase"

/* Dotted resource names. */
#define DotAcceptHostname	"." ResAcceptHostname
#define DotActiveIcon		"." ResActiveIcon
#define DotAplMode		"." ResAplMode
#define DotCaDir		"." ResCaDir
#define DotCaFile		"." ResCaFile
#define DotCertFile		"." ResCertFile
#define DotCertFileType		"." ResCertFileType
#define DotChainFile		"." ResChainFile
#define DotCbreak		"." ResCbreak
#define DotCharClass		"." ResCharClass
#define DotCharset		"." ResCharset
#define DotColorScheme		"." ResColorScheme
#define DotDevName		"." ResDevName
#define DotDsTrace		"." ResDsTrace
#define DotEmulatorFont		"." ResEmulatorFont
#define DotExtended		"." ResExtended
#define DotHostsFile		"." ResHostsFile
#define DotHttpd		"." ResHttpd
#define DotInputMethod		"." ResInputMethod
#define DotKeyFile		"." ResKeyFile
#define DotKeyFileType		"." ResKeyFileType
#define DotKeymap		"." ResKeymap
#define DotKeypadOn		"." ResKeypadOn
#define DotKeyPasswd		"." ResKeyPasswd
#define DotLoginMacro		"." ResLoginMacro
#define DotM3279		"." ResM3279
#define DotModel		"." ResModel
#define DotMono			"." ResMono
#define DotNvtMode		"." ResNvtMode
#define DotOnce			"." ResOnce
#define DotOversize		"." ResOversize
#define DotPort			"." ResPort
#define DotPreeditType		"." ResPreeditType
#define DotPrinterLu		"." ResPrinterLu
#define DotProxy		"." ResProxy
#define DotReconnect		"." ResReconnect
#define DotSaveLines		"." ResSaveLines
#define DotScripted		"." ResScripted
#define DotScriptPort		"." ResScriptPort
#define DotScrollBar		"." ResScrollBar
#define DotSecure		"." ResSecure
#define DotSelfSignedOk		"." ResSelfSignedOk
#define DotSocket		"." ResSocket
#define DotTermName		"." ResTermName
#define DotTitle		"." ResTitle
#define DotTrace		"." ResTrace
#define DotTraceFile		"." ResTraceFile
#define DotTraceFileSize	"." ResTraceFileSize
#define DotUser			"." ResUser
#define DotV			"." ResV
#define DotVerifyHostCert	"." ResVerifyHostCert

/* Resource classes. */
#define ClsAcceptHostname	"AcceptHostname"
#define ClsActiveIcon		"ActiveIcon"
#define ClsAdVersion		"AdVersion"
#define ClsAidWait		"AidWait"
#define ClsAllBold		"AllBold"
#define ClsAllowResize		"AllowResize"
#define ClsAltCursor		"AltCursor"
#define ClsAplCircledAlpha	"AplCircledAlpha"
#define ClsAplMode		"AplMode"
#define ClsBaselevelTranslations	"BaselevelTranslations"
#define ClsBellVolume		"BellVolume"
#define ClsBindLimit		"BindLimit"
#define ClsBlankFill		"BlankFill"
#define ClsBoldColor		"BoldColor"
#define ClsBsdTm		"BsdTm"
#define ClsCaDir		"CaDir"
#define ClsCaFile		"CaFile"
#define ClsCbreak		"Cbreak"
#define ClsCertFile		"CertFile"
#define ClsCertFileType		"CertFileType"
#define ClsChainFile		"ChainFile"
#define ClsCharClass		"CharClass"
#define ClsCharset		"Charset"
#define ClsColor8		"Color8"
#define ClsColorBackground	"ColorBackground"
#define ClsColorScheme		"ColorScheme"
#define ClsComposeMap		"ComposeMap"
#define ClsConfDir		"ConfDir"
#define ClsConnectFileName	"ConnectFileName"
#define ClsCrosshair		"Crosshair"
#define ClsCursorBlink		"CursorBlink"
#define ClsCursorColor		"CursorColor"
#define ClsCursorPos		"CursorPos"
#define ClsDbcsCgcsgid		"DbcsCgcsgid"
#define ClsDebugTracing		"DebugTracing"
#define ClsDevName		"DevName"
#define ClsDftBufferSize	"DftBufferSize"
#define ClsDisconnectClear	"DisconnectClear"
#define ClsDoConfirms		"DoConfirms"
#define ClsDsTrace		"DsTrace"
#define ClsEmulatorFont		"EmulatorFont"
#define ClsEof			"Eof"
#define ClsErase		"Erase"
#define ClsEventTrace		"EventTrace"
#define ClsExtended		"Extended"
#define ClsFixedSize		"FixedSize"
#define ClsFtAllocation		"FtAllocation"
#define ClsFtAvblock		"FtAvblock"
#define ClsFtBlksize		"FtBlksize"
#define ClsFtCr			"FtCr"
#define ClsFtDirection		"FtDirection"
#define ClsFtExist		"FtExist"
#define ClsFtHost		"FtHost"
#define ClsFtHostFile		"FtHostFile"
#define ClsFtLocalFile		"FtLocalFile"
#define ClsFtLrecl		"FtLrecl"
#define ClsFtMode		"FtMode"
#define ClsFtPrimarySpace	"FtPrimarySpace"
#define ClsFtRecfm		"FtRecfm"
#define ClsFtRemap		"FtRemap"
#define ClsFtSecondarySpace	"FtSecondarySpace"
#define ClsHighlightBold	"HighlightBold"
#define ClsHostname		"Hostname"
#define ClsHostsFile		"HostsFile"
#define ClsHttpd		"Httpd"
#define ClsIconFont		"IconFont"
#define ClsIconLabelFont	"IconLabelFont"
#define ClsIcrnl		"Icrnl"
#define ClsIdleCommand		"IdleCommand"
#define ClsIdleCommandEnabled	"IdleCommandEnabled"
#define ClsIdleTimeout		"IdleTimeout"
#define ClsInlcr		"Inlcr"
#define ClsInputColor		"InputColor"
#define ClsInputMethod		"InputMethod"
#define ClsIntr			"Intr"
#define ClsInvertKeypadShift	"InvertKeypadShift"
#define ClsKeyFile		"KeyFile"
#define ClsKeyFileType		"KeyFileType"
#define ClsKeymap		"Keymap"
#define ClsKeypad		"Keypad"
#define ClsKeypadBackground	"KeypadBackground"
#define ClsKeypadOn		"KeypadOn"
#define ClsKeyPasswd		"KeyPasswd"
#define ClsKill			"Kill"
#define ClsLabelIcon		"LabelIcon"
#define ClsLineWrap		"LineWrap"
#define ClsLnext		"Lnext"
#define ClsLockedCursor		"LockedCursor"
#define ClsLoginMacro		"LoginMacro"
#define ClsM3279		"M3279"
#define ClsMacros		"Macros"
#define ClsMarginedPaste	"MarginedPaste"
#define ClsMaxRecent		"MaxRecent"
#define ClsMenuBar		"MenuBar"
#define ClsMetaEscape		"MetaEscape"
#define ClsModel		"Model"
#define ClsModifiedSel		"ModifiedSel"
#define ClsModifiedSelColor	"ModifiedSelColor"
#define ClsMono			"Mono"
#define ClsMonoCase		"MonoCase"
#define ClsNewEnviron		"NewEnviron"
#define ClsNoOther		"NoOther"
#define ClsNormalColor		"NormalColor"
#define ClsNormalCursor		"NormalCursor"
#define ClsNumericLock		"NumericLock"
#define ClsNvtMode		"NvtMode"
#define ClsOerrLock		"OerrLock"
#define ClsOnce			"Once"
#define ClsOnlcr		"Onlcr"
#define ClsOverlayPaste		"OverlayPaste"
#define ClsOversize		"Oversize"
#define ClsPort			"Port"
#define ClsPreeditType		"PreeditType"
#define ClsPrinterLu		"PrinterLu"
#define ClsProxy		"Proxy"
#define ClsQuit			"Quit"
#define ClsReconnect		"Reconnect"
#define ClsRectangleSelect	"RectangleSelect"
#define ClsRprnt		"Rprnt"
#define ClsSaveLines		"SaveLines"
#define ClsSbcsCgcsgid		"SbcsSgcsgid"
#define ClsScreenTrace		"ScreenTrace"
#define ClsScreenTraceFile	"ScreenTraceFile"
#define ClsScripted		"Scripted"
#define ClsScriptPort		"ScriptPort"
#define ClsScrollBar		"ScrollBar"
#define ClsSecure		"Secure"
#define ClsSelectBackground	"SelectBackground"
#define ClsSelfSignedOk		"SelfSignedOk"
#define ClsShowTiming		"ShowTiming"
#define ClsSocket		"Socket"
#define ClsSuppressActions	"SuppressActions"
#define ClsSuppressHost		"SuppressHost"
#define ClsSuppressFontMenu	"SuppressFontMenu"
#define ClsTermName		"TermName"
#define ClsTls			"Tls"
#define ClsTrace		"Trace"
#define ClsTraceDir		"TraceDir"
#define ClsTraceFile		"TraceFile"
#define ClsTraceFileSize	"TraceFileSize"
#define ClsTraceMonitor		"TraceMonitor"
#define ClsTypeahead		"Typeahead"
#define ClsUnlockDelay		"UnlockDelay"
#define ClsUnlockDelayMs	"UnlockDelayMs"
#define ClsUseCursorColor	"UseCursorColor"
#define ClsUser			"User"
#define ClsVerifyHostCert	"VerifyHostCert"
#define ClsVisibleControl	"VisibleControl"
#define ClsVisualBell		"VisualBell"
#define ClsVisualSelect		"VisualSelect"
#define ClsVisualSelectColor	"VisualSelectColor"
#define ClsWaitCursor		"WaitCursor"
#define ClsWerase		"Werase"

/* Options. */
#define OptAcceptHostname	"-accepthostname"
#define OptActiveIcon		"-activeicon"
#define OptAllBold		"-allbold"
#define OptAltScreen		"-altscreen"
#define OptAplMode		"-apl"
#define OptCaDir		"-cadir"
#define OptCaFile		"-cafile"
#define OptCbreak		"-cbreak"
#define OptCertFile		"-certfile"
#define OptCertFileType		"-certfiletype"
#define OptChainFile		"-chainfile"
#define OptCharClass		"-cc"
#define OptCharset		"-charset"
#define OptClear		"-clear"
#define OptColorScheme		"-scheme"
#define OptDefaultFgBg		"-defaultfgbg"
#define OptDefScreen		"-defscreen"
#define OptDevName		"-devname"
#define OptTrace		"-trace"
#define OptEmulatorFont		"-efont"
#define OptExtended		"-extended"
#define OptHostsFile		"-hostsfile"
#define OptHttpd		"-httpd"
#define OptIconName		"-iconname"
#define OptIconX		"-iconx"
#define OptIconY		"-icony"
#define OptInputMethod		"-im"
#define OptKeyFile		"-keyfile"
#define OptKeyFileType		"-keyfiletype"
#define OptKeymap		"-keymap"
#define OptKeypadOn		"-keypad"
#define OptKeyPasswd		"-keypasswd"
#define OptLocalCp		"-localcp"
#define OptLocalProcess		"-e"
#define OptLoginMacro		"-loginmacro"
#define OptM3279		"-color"
#define OptModel		"-model"
#define OptMono			"-mono"
#define OptNoPrompt		"-noprompt"
#define OptNoScrollBar		"+sb"
#define OptNvtMode		"-nvt"
#define OptOnce			"-once"
#define OptOversize		"-oversize"
#define OptPort			"-port"
#define OptPreeditType		"-pt"
#define OptPrinterLu		"-printerlu"
#define OptProxy		"-proxy"
#define OptReconnect		"-reconnect"
#define OptReverseVideo		"-rv"
#define OptSaveLines		"-sl"
#define OptSecure		"-secure"
#define OptSelfSignedOk		"-selfsignedok"
#define OptScripted		"-script"
#define OptScriptPort		"-scriptport"
#define OptScrollBar		"-sb"
#define OptSet			"-set"
#define OptSocket		"-socket"
#define OptSyncPort		"-syncport"
#define OptAutoShortcut		"-S"
#define OptNoAutoShortcut	"+S"
#define OptTermName		"-tn"
#define OptTitle		"-title"
#define OptTraceFile		"-tracefile"
#define OptTraceFileSize	"-tracefilesize"
#define OptUser			"-user"
#define OptUtf8			"-utf8"
#define OptV			"-v"
#define OptVerifyHostCert	"-verifycert"
#define OptVersion		"--version"

/* Miscellaneous values. */
#define ResTrue			"true"
#define ResFalse		"false"
#define KpLeft			"left"
#define KpRight			"right"
#define KpBottom		"bottom"
#define KpIntegral		"integral"
#define KpInsideRight		"insideRight"
#define Apl			"apl"

/* Resources that are gotten explicitly. */
#define ResComposeMap		"composeMap"
#define ResEmulatorFontList	"emulatorFontList"
#define ResKeyHeight		"keyHeight"
#define ResKeyWidth		"keyWidth"
#define ResLargeKeyWidth	"largeKeyWidth"
#define ResMessage		"message"
#define ResNvt			"nvt"
#define ResPaWidth		"paWidth"
#define ResPfWidth		"pfWidth"
#define ResPrintTextCommand	"printTextCommand"
#define ResPrintTextFont	"printTextFont"
#define ResPrintTextHorizontalMargin "printTextHorizontalMargin"
#define ResPrintTextOrientation	"printTextOrientation"
#define ResPrintTextScreensPerPage "printTextScreensPerPage"
#define ResPrintTextSize	"printTextSize"
#define ResPrintTextVerticalMargin "printTextVerticalMargin"
#define ResPrintWindowCommand	"printWindowCommand"
#define ResTraceCommand		"traceCommand"
#define ResUser			"user"
