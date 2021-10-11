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
* this function read file from text file.
*/
info_Data*readFile(int*counter)
	{
	FILE* pInput = NULL;
	info_Data* user = NULL;
	int i = 0;
  	int count = 0;
	char info[512];
	
	pInput = fopen("AddressBookDatabase.txt", "r");
	if(pInput == NULL)
		{
		printf("\n ----> Error, don't have datas.<----");
		} 
	while(fgets(info, sizeof(info), pInput) != NULL)
		{
		count+=1;
		}
	if(count == 0)
		{
		printf("\n-------> Now this program don't have datas. <-------\n");
		}
	fclose(pInput);
	
	pInput = fopen("AddressBookDatabase.txt", "r");
	if(pInput == NULL)
		{
		printf("\n ----> Error, don't have datas. <----");
		} 
	user = (info_Data*)calloc(count, sizeof(info_Data));
	if(user == NULL)
		{
		printf("\n ----> Error, strorage full.<----");
		}
	for(i = 0; i < count; i++)
		{
		if(fgets(info, sizeof(info), pInput) != NULL)
			{
			strcpy(user[i].name, strtok(info, ","));
			strcpy(user[i].date, strtok(NULL, ","));
			strcpy(user[i].email, strtok(NULL, ","));
			strcpy(user[i].phone, strtok(NULL, ","));
			strcpy(user[i].address, strtok(NULL, ","));
			strcpy(user[i].gender, strtok(NULL, ","));			
			}
		else
			{
			printf("\n-------> Now this program don't have datas. <-------\n");
			break;		
			}	
		}
	*counter = count;
	return user;
	free(user);
	fclose(pInput);
	}
