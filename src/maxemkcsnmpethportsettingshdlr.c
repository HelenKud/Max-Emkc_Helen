/* $Id:$ */

/*
 * Copyright 2009 ZOHO Corp. All Rights Reserved.
 * This software is the property of ZOHO Corp. Distribution
 * or deployment of the source or derived binaries of this
 * software are not permitted without a OEM or distribution
 * license from ZOHO Corp.
 */

/**************************************************************************
 *  File		: maxemkcsnmpethportsettingshdlr.c.
 *
 *  Purpose		: To handle the requests from the manager for the 
 * 				  module maxemkcsnmpethportsettings.
 *
 *  Author		: WebNMS Agent Toolkit C Edition 6
 *
 *  Date		: Fri Jan 26 16:40:26 MSK 2018
 *
 *  See Also	: maxemkcsnmpethportsettingsftov.c,
 *				  maxemkcsnmpethportsettingsinstru.c,
 *				  maxemkcsnmpethportsettings.h,
 *				  maxemkctraps.c.
 *
 *  Docs		: Yes. 
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

#include "config.h"
#include "snmpincludes.h"
#define MAXEMKCSNMPETHPORTSETTINGS_PUBLIC
#include "maxemkcsnmpethportsettings.h" 

/* This tree cell is used to register with agent.*/
TreeCell gv_maxEmkcSnmpEthPortSettingsCell=
	{
		"MAX-EMKC:MaxEmkcSnmpEthPortSettings",
		SNMP_VERSION_2c, gv_maxEmkcSnmpEthPortSettingsOid,
		MAXEMKCSNMPETHPORTSETTINGS_OID_LEN, NOT_TABLE,
		gv_maxEmkcSnmpEthPortSettingsSubIdList,
		MAXEMKCSNMPETHPORTSETTINGS_SUBID_LEN,
		gv_maxEmkcSnmpEthPortSettingsSubIdListAccess,
		gv_maxEmkcSnmpEthPortSettingsSubIdListDataTypes,
		0, MaxEmkcSnmpEthPortSettingsProcessRequests,
		MaxEmkcSnmpEthPortSettingsProcessReadReq,
		MaxEmkcSnmpEthPortSettingsProcessWriteReq,
		UpdateMaxEmkcSnmpEthPortSettings,
		NULL, NULL
	};

/*****************************************************************************
 *	Function Name	: InitMaxEmkcSnmpEthPortSettings()
 *
 *	Args			: Nothing.
 *
 *	Returns			: Nothing.
 *
 *	Task			: It will register the treeCell with agent and initialize
 * 					  all data structures related to the module
 * 					  "maxEmkcSnmpEthPortSettings".
 *
 *	Docs			: Yes.
 *
 *	Bugs			: 
 *****************************************************************************/
void InitMaxEmkcSnmpEthPortSettings(void)
{
	CHAR ftovFlag;

	DEBUGMSG1("\n\t@@@@@ Inside InitMaxEmkcSnmpEthPortSettings() @@@@@\n");

	ftovFlag = FAILURE;

	/* Register the oid as a listener to the agent. */
	if (RegisterOID(&gv_maxEmkcSnmpEthPortSettingsCell) == FAILURE)
	{
		DEBUGMSG1("Unable to register for the module maxEmkcSnmpEthPortSettings\n");
		return;
	}

#ifdef FILE_TO_VECTOR
	/* Read all the values of "maxEmkcSnmpEthPortSettings" from the file */
	ftovFlag = ReadFromMaxEmkcSnmpEthPortSettingsFile();
#endif

	if(ftovFlag == FAILURE)
	{

		/* Assigning the default value for scalar object "gv_maxEmkcSnmpEthPortMacAddress" */
		gv_maxEmkcSnmpEthPortMacAddressLen = 0;
		AllocateAndDoMemcpy(
				&gv_maxEmkcSnmpEthPortMacAddress,
				(U_CHAR *)"",
				gv_maxEmkcSnmpEthPortMacAddressLen);
		
		/* Assigning the default value for scalar object "gv_maxEmkcSnmpEthPortIpAddress" */
		
		gv_maxEmkcSnmpEthPortIpAddressLen = 13;
		AllocateAndDoMemcpy(
				&gv_maxEmkcSnmpEthPortIpAddress,(U_CHAR *) 
				"255.255.255.0", gv_maxEmkcSnmpEthPortIpAddressLen);
		
		/* Assigning the default value for scalar object "gv_maxEmkcSnmpEthPortMask" */
		gv_maxEmkcSnmpEthPortMask = 1;

		/* Assigning the default value for scalar object "gv_maxEmkcSnmpEthPortGw" */
		
		gv_maxEmkcSnmpEthPortGwLen = 13;
		AllocateAndDoMemcpy(
				&gv_maxEmkcSnmpEthPortGw,(U_CHAR *) 
				"255.255.255.0", gv_maxEmkcSnmpEthPortGwLen);
		
#ifdef FILE_TO_VECTOR
	/* Write the values of "maxEmkcSnmpEthPortSettings" into the file */
	WriteToMaxEmkcSnmpEthPortSettingsFile();
#endif
	}

}

/*****************************************************************************
 *	Function Name	: MaxEmkcSnmpEthPortSettingsProcessRequests()
 *
 *	Args			: 1. PduType (GET/GET-NEXT) (IN/OUT).
 *					  2. VarBinds vector (IN/OUT).
 *					  3. Future Use.
 *					  4. Future Use.
 *
 *	Returns			: SUCCESS or FAILURE. 
 *
 *	Task			: This method will be called from the agent api for
 *					  all the requests (GET/GET-NEXT/SET) with received
 *					  pduType and  varBind vector before processing the
 *					  received varbinds. The purpose of this method call
 *					  is, the user can know the set of varBinds (OIDs')
 *					  received for a listener. Using these inputs user
 *					  may do some validation or call his application
 *					  method and update the local data structure. User
 *					  has to specify the error status and error index.
 *
 *	Docs			: Yes.
 *
 *	Bugs			: Return value of method is not handled in AgentAPI.
 *****************************************************************************/
CHAR MaxEmkcSnmpEthPortSettingsProcessRequests(INT32 pduVersion, U_CHAR pduType, Vector *varBinds, LONG *errStatus, LONG *errIndex)
{
	/*
	 * Varbinds			: Varbinds have all the received varbinds(oid and
	 *					  value)from the manager.
	 *
	 * Errstatus		: Single "Long" storage pointer variable.
	 * 					  User can update this incase of any error.
	 * 					  No nead to allocate. Memory should not be freed.
	 *
	 * ErrIndex			: Single "Long" storage pointer variable.
	 * 					  User can update this incase of any error.
	 * 					  No nead to allocate. Memory should not be freed.
	 */

	INT16	i;
	Node	*nodePtr;
	VarBind	*varBindPtr;

	DEBUGMSG1("\n\t@@@@@ Inside MaxEmkcSnmpEthPortSettingsProcessRequests() @@@@@\n");

	/*
	 * The varBind vector have a set of varBinds requested
	 * for this listener. User can do the validation or extra
	 * processing over the received varBinds.
	 */


	for(i=0; i<varBinds->size; i++)
	{
		nodePtr = (Node *)ElementAt(varBinds, i);
		varBindPtr = (VarBind *)nodePtr->refPtr;

#ifdef DEBUG
		DEBUGMSG2("The varBind index is %d\n", i+1);
		DEBUGMSG1("The received oid is \n");
		PRINTOID(varBindPtr->oid, varBindPtr->oidLen);
#endif

	}

	return SUCCESS;
}

/*****************************************************************************
 *	Function Name	: MaxEmkcSnmpEthPortSettingsProcessReadReq()
 *
 *	Args			: 1. PduType (GET/GET-NEXT) (IN).
 *					  2. Requested Oid (IN).
 *					  3. Requested Oid Length (IN).
 *					  4. Variable value length (IN).
 *					  5. It is used to return snmp error or exception(IN/OUT).
 *
 *	Returns			: Pointer to the return variable value.
 *
 *	Task			: This method is called from agent api (pdureqhdlr.c) when a 
 *					  get/get-next request is made from the manager. This method 
 *					  will identify the exact scalar/table column for which the 
 *					  request is made and call the corresponding get method which 
 *					  is available  in the instrument file. output from this 
 *					  function will be the value of the requested variable, 
 *					  length of the variable,  the error status if any.
 *
  *	Docs			: Yes.
 *
 *	Bugs			: 
 *****************************************************************************/
U_CHAR *MaxEmkcSnmpEthPortSettingsProcessReadReq(U_CHAR pduType, OID *reqOid, INT32 *reqOidLen, INT32 *varValLen, U_CHAR *status)
{

	/*
	 * reqOid			: Requested OID, User can neither change the value,
	 *					  free the memory, reallocate memory.
	 *
	 * reqOidLen		: length of reqOid. User can neither change the value,
	 *					  free the memory, reallocate memory.
	 *
	 * varValLen		: Updated inside the method. No nead to allocate the
	 *					  memory.
	 *
	 * Status			: Updated incase of error. No nead to allocate the
	 *					  memory.
	 */

	OID		column;
	U_CHAR	*retPtr;

	DEBUGMSG1("\n\t@@@@@ Inside MaxEmkcSnmpEthPortSettingsProcessReadReq() @@@@@\n");

	retPtr = NULL;
	column = reqOid[MAXEMKCSNMPETHPORTSETTINGS_OID_LEN-1];

	DEBUGMSG2("The column value is %ld\n", column);

	*status = SNMP_ERR_NOERROR;

	switch(column)
	{
		case	MAXEMKCSNMPETHPORTSETTINGS_MAXEMKCSNMPETHPORTMACADDRESS:
				retPtr = GetMaxEmkcSnmpEthPortMacAddress( varValLen, status);
				break;

		case	MAXEMKCSNMPETHPORTSETTINGS_MAXEMKCSNMPETHPORTIPADDRESS:
				retPtr = GetMaxEmkcSnmpEthPortIpAddress( varValLen, status);
				break;

		case	MAXEMKCSNMPETHPORTSETTINGS_MAXEMKCSNMPETHPORTMASK:
				retPtr = GetMaxEmkcSnmpEthPortMask( varValLen, status);
				break;

		case	MAXEMKCSNMPETHPORTSETTINGS_MAXEMKCSNMPETHPORTGW:
				retPtr = GetMaxEmkcSnmpEthPortGw( varValLen, status);
				break;

		default:
				/* Invalid column number */
				*status = SNMP_NOSUCHOBJECT;
				retPtr = NULL;
	}
	return retPtr;
}

/*****************************************************************************
 *	Function Name	: MaxEmkcSnmpEthPortSettingsProcessWriteReq()
 *
 *	Args			: 1. Requested Oid (IN).
 *					  2. Requested Oid Length (IN).
 *					  3. Variable value (IN).
 *					  4. Variable value length (IN).
 *					  5. It is used for atomic set implementation and
 * 						 to return snmp error or exception(IN/OUT).
 *
 *	Returns			: Pointer to the return variable value.
 *
 *	Task			: This method is called from the agent api (pdureqhdlr.c) 
 *					  when a set  request is made from the manager. This method 
 *					  will identify the exact scalar/table column for which 
 *					  the request is made and call the corresponding  set method 
 *					  which is available in the instrument file.
 *
 *	Docs			: Yes.
 *
 *	Bugs			: 
 *****************************************************************************/
U_CHAR *MaxEmkcSnmpEthPortSettingsProcessWriteReq(INT32 pduVersion, OID *reqOid, INT32 reqOidLen, U_CHAR *varVal, INT32 *varValLen, U_CHAR *status)
{

	/*
	 * reqOid			: Requested OID, User can neither change the value,
	 *					  free the memory, reallocate memory.
	 *
	 * reqOidLen		: length of reqOid. User can neither change the value,
	 *					  free the memory, reallocate memory.
	 *
	 * varVal			: It has the value. No nead to allocate the memory.
	 *
	 * varValLen		: It has the value and updated inside the method.
	 *					  No nead to allocate the memory.
	 *
	 * Status			: It has the value and updated incase of error.
	 *					  No nead to allocate the memory.
	 */

	OID		column;
	U_CHAR	*retPtr;

	DEBUGMSG1("\n\t@@@@@ Inside MaxEmkcSnmpEthPortSettingsProcessWriteReq() @@@@@\n");

	retPtr = NULL;

	column = reqOid[MAXEMKCSNMPETHPORTSETTINGS_OID_LEN-1];

	DEBUGMSG2("The column value is %ld\n", column);

	switch(column)
	{
		case	MAXEMKCSNMPETHPORTSETTINGS_MAXEMKCSNMPETHPORTMACADDRESS:
				*status = SNMP_ERR_READONLY;
				retPtr = NULL;
				break;

		case	MAXEMKCSNMPETHPORTSETTINGS_MAXEMKCSNMPETHPORTIPADDRESS:
				*status = SNMP_ERR_READONLY;
				retPtr = NULL;
				break;

		case	MAXEMKCSNMPETHPORTSETTINGS_MAXEMKCSNMPETHPORTMASK:
				*status = SNMP_ERR_READONLY;
				retPtr = NULL;
				break;

		case	MAXEMKCSNMPETHPORTSETTINGS_MAXEMKCSNMPETHPORTGW:
				*status = SNMP_ERR_READONLY;
				retPtr = NULL;
				break;

		default:
				/* Invalid column number */
				*status = SNMP_NOSUCHOBJECT;
				retPtr = NULL;
	}


	return retPtr;
}

/*****************************************************************************
 *	Function Name	: UpdateMaxEmkcSnmpEthPortSettings()
 *
 *	Args			: command type.
 *
 *	Returns			: SUCCESS or FAILURE.
 *
 *	Task			: This method will be called from the agent api after
 *					  successful SET/GET/GET-NEXT operation, in order to
 *					  update the original or user application's data
 *					  structrue with the changes made to MaxEmkcSnmpEthPortSettings.
 *					  If FILE_TO_VECTOR is enabled then the corresponding
 *					  text file will be updated here. If the storagetype
 *					  is NoStorage then the user should call this method
 *					  to update the changes done by the management.The
 *					  user can also free the resources in this function
 *					  if required.
 *
 *	Docs			: Yes.
 *
 *	Bugs			: 
 *****************************************************************************/
CHAR UpdateMaxEmkcSnmpEthPortSettings(U_CHAR command)
{
	CHAR retVal;

	DEBUGMSG1("\n\t@@@@@ Inside UpdateMaxEmkcSnmpEthPortSettings() @@@@@\n");

	retVal = SUCCESS;

	if(command == SNMP_MSG_SET) 
	{
#ifdef FILE_TO_VECTOR
		/* Write the values of "maxEmkcSnmpEthPortSettings" into the file */
		WriteToMaxEmkcSnmpEthPortSettingsFile();
#endif
	}

	return retVal;
}

#ifdef  __cplusplus
}
#endif /* #ifdef  __cplusplus */

/*****************************************************************************
 *						 End of maxemkcsnmpethportsettingshdlr.c
 *****************************************************************************/
