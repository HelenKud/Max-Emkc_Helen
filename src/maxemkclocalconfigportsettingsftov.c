/* $Id:$ */

/*
 * Copyright 2009 ZOHO Corp. All Rights Reserved.
 * This software is the property of ZOHO Corp. Distribution
 * or deployment of the source or derived binaries of this
 * software are not permitted without a OEM or distribution
 * license from ZOHO Corp.
 */

/**************************************************************************
 *  File	: maxemkclocalconfigportsettingsftov.c.
 *
 *  Purpose	: This file is used only when text file storage is used.The 
 * 			  file contains methods to read from & write to the 
 * 			  maxemkclocalconfigportsettings.txt file in the <bin>/ftov/max-emkc 
 * 			  directory.
 *
 *  Author	: WebNMS Agent Toolkit C Edition 6
 *
 *  Date	: Fri Jan 26 16:40:29 MSK 2018
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

#include "config.h"
#ifdef FILE_TO_VECTOR
#include "genincludes.h"
#include "maxemkclocalconfigportsettings.h" 

/******************************************************************************
 *	Function Name	: ReadFromMaxEmkcLocalConfigPortSettingsFile()
 *
 *	Args			: Nothing.
 *
 *	Returns			: SUCCESS or FAILURE.
 *
 *	Task			: It will read the values from the file and assign it to 
 *					  the corresponding variables. After successfully reading
 *					  from the file it returns SUCCESS else FAILURE.
 *
 *	See Also		: WriteToMaxEmkcLocalConfigPortSettingsFile().
 *
 *	Docs			: Yes.
 *
 *	Bugs			: 
 *****************************************************************************/
CHAR ReadFromMaxEmkcLocalConfigPortSettingsFile()
{
	FILE	*fptr;
	INT32	len;
	CHAR	*fileName;

	DEBUGMSG1("\n\t@@@@@ Inside ReadFromMaxEmkcLocalConfigPortSettingsFile() @@@@@\n");

	fileName = (CHAR *)__Calloc(1, (__Strlen(gptr_agentRootDir) + __Strlen(MAXEMKCLOCALCONFIGPORTSETTINGS_FILE) + 1 ));

	CHECK_NULL_RETURN_ERROR(fileName);

	__Strcpy(fileName, gptr_agentRootDir);

	__Strcat(fileName, MAXEMKCLOCALCONFIGPORTSETTINGS_FILE);

	fptr = fopen(fileName, "r");

	__Free(fileName);

	if( fptr == NULL)
	{
		DEBUGMSG1("Cannot Open file for reading\n");
		return FAILURE;
	}

	while (!feof(fptr))
	{
		IGNORE_COMMENTED_LINES();
		/* Reading from the file for the scalar gv_maxEmkcLocalConfigEthPortMacAddress. */
		if(fscanf(fptr,"%d ",&len) == EOF)
		{
			break;
		}

		gv_maxEmkcLocalConfigEthPortMacAddress = (U_CHAR *) __Calloc(1, len+1);

		CHECK_NULL_RETURN_FAILURE(gv_maxEmkcLocalConfigEthPortMacAddress);

		

		gv_maxEmkcLocalConfigEthPortMacAddressLen = len;

		if(ReadStringFromFile(fptr, gv_maxEmkcLocalConfigEthPortMacAddress, len) == FAILURE)
		{
			break;
		}

		/* Reading from the file for the scalar gv_maxEmkcLocalConfigEthPortIpAddress. */
		if(fscanf(fptr,"%d ",&gv_maxEmkcLocalConfigEthPortIpAddressLen) == EOF)
		{
			break;
		}
		gv_maxEmkcLocalConfigEthPortIpAddress = (U_CHAR *) __Calloc(1, MAX_IPADDRESS_LEN+1);

		CHECK_NULL_RETURN_FAILURE(gv_maxEmkcLocalConfigEthPortIpAddress);

		if(ReadStringFromFile(fptr, gv_maxEmkcLocalConfigEthPortIpAddress, gv_maxEmkcLocalConfigEthPortIpAddressLen) == FAILURE)
		{
			break;
		}

		/* Reading from the file for the scalar gv_maxEmkcLocalConfigEthPortMask. */
		if(fscanf(fptr,"%u ", &gv_maxEmkcLocalConfigEthPortMask) == EOF)
		{
			break;
		}
	}

	fclose(fptr);

	return SUCCESS;
}
/******************************************************************************
 *	Function Name	: WriteToMaxEmkcLocalConfigPortSettingsFile()
 *
 *	Args			: Nothing.
 *
 *	Returns			: SUCCESS or FAILURE.
 *
 *	Task			: It will write the scalar object values into the file.
 * 					  After successfully writing into the file it returns
 * 					  SUCCESS else FAILURE.
 *
 *	See Also		: ReadFromMaxEmkcLocalConfigPortSettingsFile().
 *
 *	Docs			: Yes.
 *
 *	Bugs			: 
 *****************************************************************************/
CHAR WriteToMaxEmkcLocalConfigPortSettingsFile()
{
	FILE	*fptr;
	CHAR	*fileName;
	CHAR	str[STRING_MAX_LEN];
	CHAR	finalStr[FTOV_MAX_COMMENT_LINE];

	DEBUGMSG1("\n\t@@@@@ Inside WriteToMaxEmkcLocalConfigPortSettingsFile() @@@@@\n");

	fileName = (CHAR *)__Calloc(1, (__Strlen(gptr_agentRootDir) + __Strlen(MAXEMKCLOCALCONFIGPORTSETTINGS_FILE) + 1 ));

	CHECK_NULL_RETURN_ERROR(fileName);

	__Strcpy(fileName, gptr_agentRootDir);

	__Strcat(fileName, MAXEMKCLOCALCONFIGPORTSETTINGS_FILE);

	READ_AND_STORE_COMMENTED_LINES();

	fptr = fopen(fileName, "w");

	__Free(fileName);

	if (fptr == NULL)
	{
		DEBUGMSG1("Cannot Open file for writing\n");
		return FAILURE;
	}

	fprintf(fptr, "%s", finalStr);
	
	/* Writing to the file for the scalar gv_maxEmkcLocalConfigEthPortMacAddress. */
	fprintf(fptr,"%d ",gv_maxEmkcLocalConfigEthPortMacAddressLen);

	WriteStringToFile(fptr, gv_maxEmkcLocalConfigEthPortMacAddress, gv_maxEmkcLocalConfigEthPortMacAddressLen);
	fprintf(fptr, "%c", ' ');


	
	/* Writing to the file for the scalar gv_maxEmkcLocalConfigEthPortIpAddress. */
	fprintf(fptr,"%d ",gv_maxEmkcLocalConfigEthPortIpAddressLen);

	WriteStringToFile(fptr, gv_maxEmkcLocalConfigEthPortIpAddress, gv_maxEmkcLocalConfigEthPortIpAddressLen);
	fprintf(fptr, "%c", ' ');


	/* Writing to the file for the scalar gv_maxEmkcLocalConfigEthPortMask. */
	fprintf(fptr,"%u \n",
				gv_maxEmkcLocalConfigEthPortMask);


	fclose(fptr);

	return SUCCESS;
}
#endif /* #ifdef FILE_TO_VECTOR */

#ifdef  __cplusplus
}
#endif /* #ifdef  __cplusplus */

/*****************************************************************************
 *						 End of maxemkclocalconfigportsettingsftov.c
 *****************************************************************************/
