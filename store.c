/***************************************************************************************
*	
*	Created by Prakasit Issanapong (Tar) 
*   	ID 62070503431
*   	Date 12/12/2019
*
****************************************************************************************
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "struct.h"

/**************************************************************************************
* this function use for storing the data and add the data to the text file
*/
void addStoreData()
	{
	FILE* pInput = NULL;
	char stringInput[128];
	info_Data info;
	int i = 0;

	pInput = fopen("AddressBookDatabase.txt", "a+");
	if(pInput == NULL)
		{
		printf("Error, we can't add the data you requested\n");
           	exit(0);
		}
	printf("\n   >> Add Data by user");
	while(1)	
		{
		int valid = 0;
		
	 	printf("\n   >> Enter Name : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		strcpy(info.name,stringInput);				
		valid = inputName(info.name);
		if(valid == 1)
			{
			sscanf(stringInput, "%[^\n]", info.name);
			fprintf(pInput, "%s,", info.name);
			break;
			}
		else
			{
			printf("----> Invalid form <----\n");
			}
		}
 	while(1)
		{
		int valid = 0;
		memset(info.date, 0, sizeof(info.date));
		printf("   >> Enter Birthday :");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", info.date);
		valid = inputDate(info.date);	
		if(valid == 1)
			{
			sscanf(stringInput, "%s", info.date);
			fprintf(pInput, "%s,", info.date);
			break;
			}
		else
			{
			printf("----> Invalid form <----\n");
			}
		}
	while(1)
		{
		int valid = 0;
		memset(info.email, 0, sizeof(info.email));
		printf("   >> Enter Email address: ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", info.email);
		valid = inputEmail(info.email);
		if(valid == 1)
			{
			sscanf(stringInput, "%s", info.email);
			fprintf(pInput, "%s,", info.email);
			break;
			}
		else
			{
			printf("----> Invalid form <----\n");
			}
		}
	while(1)
		{
		int valid = 0;
		memset(info.phone, 0, sizeof(info.phone));
		printf("   >> Enter International phone number : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", info.phone);		
		valid = inputPhone(info.phone);
		if(valid == 1)
			{
			sscanf(stringInput, "%s", info.phone);
			fprintf(pInput, "%s,", info.phone);
			break;
			}
		else
			{
			printf("----> Invalid form <----\n");
			}
		}
	while(1)
		{
		printf("   >> Enter Address : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", info.address);				
		if(checkAddress(info.address) == 1)
			{
			sscanf(stringInput, "%[^\n]", info.address);
			fprintf(pInput, "%s,", info.address);
			break;
			}
		else
			{
			printf("----> Invalid form <----\n");		
			}
		}
	while(1)
		{
		printf("   >> Enter Gender : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", info.gender);	
		if((strcmp(info.gender, "M") == 0) || (strcmp(info.gender, "F") == 0) || (strcmp(info.gender, "O") == 0))
			{
			fprintf(pInput, "%s\n", info.gender);
			break;
			}	
		else
			{
			printf("----> Invalid form <----\n");
			}
		}
	fclose(pInput);
	}

