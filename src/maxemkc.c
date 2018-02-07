/* $Id:$ */

/*
 * Copyright 2009 ZOHO Corp. All Rights Reserved.
 * This software is the property of ZOHO Corp. Distribution
 * or deployment of the source or derived binaries of this
 * software are not permitted without a OEM or distribution
 * license from ZOHO Corp.
 */

/**************************************************************************
 *  File	: maxemkc.c.
 *
 *  Purpose	: File contains init functions of the generated
 * 			  Max-Emkc module.
 *
 *  Author	: WebNMS Agent Toolkit C Edition 6
 *
 *  Date	: Fri Jan 26 16:41:04 MSK 2018
 *
 *  Docs	: Yes. 
 ***************************************************************************/

#ifdef  __cplusplus
extern "C" {
#endif /* #ifdef  __cplusplus */

/* User code starts here */
/* User code ends here */

/*
 * If the user wants to add their code, then the code has to be
 * added in between the above mentioned comments. Otherwise, on
 * regeneration, the user added code will be overwritten.
 * The above mentioned comments can be used at any place in this file.
 */

//новые изменения

#include "config.h"
#include "genincludes.h"

#include "maxemkcmeterinfo.h"
#include "maxemkcsnmpagentinfo.h"
#include "maxemkcrefclocks.h"
#include "maxemkcmeasethportsettings.h"
#include "maxemkcmeasuringethportstate.h"
#include "maxemkcsnmpethportsettings.h"
#include "maxemkclocalconfigportsettings.h"
#include "maxemkctime.h"
#include "maxemkcstatusmeasuringresults.h"
#include "maxemkcstatus.h"
#include "maxemkccfgmeasuringethport.h"
#include "maxemkccfgrfc2544table.h"
#include "maxemkccfgtestrfc2544.h"
#include "maxemkccfgy1564table.h"
#include "maxemkccfgtesty1564.h"
#include "maxemkccfgtraffictable.h"
#include "maxemkccfgtraffictest.h"
#include "maxemkccfgloopertable.h"
#include "maxemkccfglooper.h"
#include "maxemkccfgstreamstable.h"
#include "maxemkccfgmeasurednetworktable.h"
#include "maxemkccfgmeasuringtests.h"
#include "maxemkccfgloginaccess.h"
#include "maxemkccfgfirmwaresource.h"
#include "maxemkccfgsyslog.h"
#include "maxemkccfgsnmptraprectable.h"
#include "maxemkccfgsnmp.h"
#include "maxemkccommands.h"

/***************************************************************************
 *	Function Name	: InitMaxemkc()
 *
 *	Args			: None.
 *
 *	Returns			: Nothing
 *
 *	Task			: This function will call the init functions
 * 					  of all the generated handler files of the 
 * 					  "Max-Emkc" MIB.
 *
 *	Docs            : Yes.
 *
 *	Bugs			:
 ***************************************************************************/
void InitMaxemkc()
{
	DEBUGMSG1("\n\t@@@@@ Inside InitMaxemkc() @@@@@\n");

	/*
	 * All the modules of the mib "Maxemkc" are initialized here.
	 */

	InitMaxEmkcMeterInfo();
	InitMaxEmkcSnmpAgentInfo();
	InitMaxEmkcRefclocks();
	InitMaxEmkcMeasEthPortSettings();
	InitMaxEmkcMeasuringEthPortState();
	InitMaxEmkcSnmpEthPortSettings();
	InitMaxEmkcLocalConfigPortSettings();
	InitMaxEmkcTime();
	InitMaxEmkcStatusMeasuringResults();
	InitMaxEmkcStatus();
	InitMaxEmkcCfgMeasuringEthPort();
	InitMaxEmkcCfgRfc2544Table();
	InitMaxEmkcCfgTestRfc2544();
	InitMaxEmkcCfgY1564Table();
	InitMaxEmkcCfgTestY1564();
	InitMaxEmkcCfgTrafficTable();
	InitMaxEmkcCfgTrafficTest();
	InitMaxEmkcCfgLooperTable();
	InitMaxEmkcCfgLooper();
	InitMaxEmkcCfgStreamsTable();
	InitMaxEmkcCfgMeasuredNetworkTable();
	InitMaxEmkcCfgMeasuringTests();
	InitMaxEmkcCfgLoginAccess();
	InitMaxEmkcCfgFirmwareSource();
	InitMaxEmkcCfgSyslog();
	InitMaxEmkcCfgSnmpTrapRecTable();
	InitMaxEmkcCfgSnmp();
	InitMaxEmkcCommands();
}

/***************************************************************************
 *  Function Name   : FreeMaxemkcResources()
 *
 *  Args            : Nothing.
 *
 *  Returns         : Nothing.
 *
 *  Task            : It will free the resources reserved by the instrumented
 *                    "Max-Emkc" MIB.
 *
 *  Docs            : Yes.
 *
 *  Bugs            :
 ***************************************************************************/
void FreeMaxemkcResources()
{
	DEBUGMSG1("\n\t@@@@@ Inside FreeMaxemkcResources() @@@@@\n");

	/* Free maxEmkcMeterInfo module Memory. */
	__Free(gv_maxEmkcMeterCpuSoftwareVersion);
	__Free(gv_maxEmkcMeterFpgaBinImageVersion);
	__Free(gv_maxEmkcMeterFirmwareReleaseVersion);
	__Free(gv_maxEmkcMeterHardwareVersion);
	__Free(gv_maxEmkcMeterSerialNumber);

	/* Free maxEmkcSnmpAgentInfo module Memory. */
	__Free(gv_maxEmkcSnmpAgentOsVersion);
	__Free(gv_maxEmkcSnmpAgentSoftwareVersion);
	__Free(gv_maxEmkcSnmpAgentHardwareVersion);
	__Free(gv_maxEmkcSnmpAgentSerialNumber);

	/* Free maxEmkcMeasEthPortSettings module Memory. */
	__Free(gv_maxEmkcMeasEthPortMacAddress);
	__Free(gv_maxEmkcMeasEthPortIpAddress);
	__Free(gv_maxEmkcMeasEthPortGw);

	/* Free maxEmkcSnmpEthPortSettings module Memory. */
	__Free(gv_maxEmkcSnmpEthPortMacAddress);
	__Free(gv_maxEmkcSnmpEthPortIpAddress);
	__Free(gv_maxEmkcSnmpEthPortGw);

	/* Free maxEmkcLocalConfigPortSettings module Memory. */
	__Free(gv_maxEmkcLocalConfigEthPortMacAddress);
	__Free(gv_maxEmkcLocalConfigEthPortIpAddress);

	/* Free maxEmkcTime module Memory. */
	__Free(gv_maxEmkcSystemClockTime);

	/* Free maxEmkcCfgMeasuringEthPort module Memory. */
	__Free(gv_maxEmkcCfgMeasEthPortMacAddress);
	__Free(gv_maxEmkcCfgMeasEthPortIpAddress);
	__Free(gv_maxEmkcCfgMeasEthPortGw);
	__Free(gv_maxEmkcCfgMeasEthPortRate);
	__Free(gv_maxEmkcCfgMeasEthPortDuplex);

	/* Free maxEmkcCfgRfc2544Table Memory. */
	FreeTableMemory(&gv_maxEmkcCfgRfc2544TableVector, FreeMaxEmkcCfgRfc2544TableEntryMemory);

	/* Free maxEmkcCfgY1564Table Memory. */
	FreeTableMemory(&gv_maxEmkcCfgY1564TableVector, FreeMaxEmkcCfgY1564TableEntryMemory);

	/* Free maxEmkcCfgTrafficTable Memory. */
	FreeTableMemory(&gv_maxEmkcCfgTrafficTableVector, FreeMaxEmkcCfgTrafficTableEntryMemory);

	/* Free maxEmkcCfgLooperTable Memory. */
	FreeTableMemory(&gv_maxEmkcCfgLooperTableVector, FreeMaxEmkcCfgLooperTableEntryMemory);

	/* Free maxEmkcCfgStreamsTable Memory. */
	FreeTableMemory(&gv_maxEmkcCfgStreamsTableVector, FreeMaxEmkcCfgStreamsTableEntryMemory);

	/* Free maxEmkcCfgMeasuredNetworkTable Memory. */
	FreeTableMemory(&gv_maxEmkcCfgMeasuredNetworkTableVector, FreeMaxEmkcCfgMeasuredNetworkTableEntryMemory);

	/* Free maxEmkcCfgMeasuringTests module Memory. */
	__Free(gv_maxEmkcCfgTestNtpTimeOfStart);
	/* Free maxEmkcCfgFirmwareSource module Memory. */
	__Free(gv_maxEmkcCfgFirmwareSourceIpAddr);
	__Free(gv_maxEmkcCfgFirmwareSourceLogin);
	__Free(gv_maxEmkcCfgFirmwareSourcePassw);
	__Free(gv_maxEmkcCfgFirmwareSourceDirectory);
	__Free(gv_maxEmkcCfgFirmwareSourceFilename);

	/* Free maxEmkcCfgSyslog module Memory. */
	__Free(gv_maxEmkcCfgSyslogServerAddress);

	/* Free maxEmkcCfgSnmpTrapRecTable Memory. */
	FreeTableMemory(&gv_maxEmkcCfgSnmpTrapRecTableVector, FreeMaxEmkcCfgSnmpTrapRecTableEntryMemory);

	/* Free maxEmkcCfgSnmp module Memory. */
	__Free(gv_maxEmkcCfgSnmpReadCommunity);
	__Free(gv_maxEmkcCfgSnmpWriteCommunity);
	__Free(gv_maxEmkcCfgSnmpContact);
	__Free(gv_maxEmkcCfgSnmpLocation);
	__Free(gv_maxEmkcCfgSnmpV3UserName);
	__Free(gv_maxEmkcCfgSnmpV3Context);
	__Free(gv_maxEmkcCfgSnmpV3AuthPassphrase);
	__Free(gv_maxEmkcCfgSnmpV3PrivPassphrase);
	/* Free maxEmkcCommands module Memory. */
	__Free(gv_maxEmkcCmdSetTime);

}

#ifdef  __cplusplus
}
#endif /* #ifdef  __cplusplus */

/*****************************************************************************
 *						 End of maxemkc.c
 *****************************************************************************/
