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

/************************************************************************************
* this function search by name 
*/
void searchName()
	{
	info_Data*info = NULL;
	int count = 0;
	int*line = NULL;
	char stringInput[64];
	char nameSearch[64];
	int i = 0;
	int find = 0;
	
	printf("\n   >>> Name (Enter show all data) : ");
	fgets(stringInput, sizeof(stringInput), stdin);
	sscanf(stringInput, "%s", nameSearch);
	line = calloc(count, sizeof(count));
	info = readFile(&count);
	for(i = 0; i < count; i++)
		{	
		if(strncasecmp(info[i].name, nameSearch, strlen(nameSearch)) == 0)
			{
			display(info[i]);
			find++;
			}
		}
	if(find == 0)
		{
		printf("----> Don't found this name <----\n");
		}
	}

/************************************************************************************
* this function search by email
*/
void searchEmail()
	{
	info_Data*info = NULL;
	int count = 0;
	int*line = NULL;
	char stringInput[64];
	char emailSearch[64];
	int i = 0;
	int find = 0;
	
	printf("\n   >>> Email address (Enter show all data) : ");
	fgets(stringInput, sizeof(stringInput), stdin);
	sscanf(stringInput, "%s", emailSearch);
	line = calloc(count, sizeof(count));
	info = readFile(&count);
	for(i = 0; i < count; i++)
		{	
		if(strncasecmp(info[i].email, emailSearch, strlen(emailSearch)) == 0)
			{
			display(info[i]);
			find++;
			}
		}
	if(find == 0)
		{
		printf("----> Don't found this email address <----\n");
		}
	}

/************************************************************************************
* this function ask user want search by name or email address.
*/
void search()
	{
	char stringInput[64];
	int select = 0;

	while(1)
		{
		printf("\n   >> Option of search for a data.\n");
		printf("   >> 1 : Search by name\n");
		printf("   >> 2 : Search by email\n");
		printf("   >> 3 : End this menu\n");
		printf("   >> Do you want search by name or email? : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%d", &select);
		if(select == 1)
			{
			searchName();
			}
		else if(select == 2)
			{
			searchEmail();
			}
		else if(select == 3)
			{
			break;
			}
		else
			{
			printf("\n----> Error, select option <----\n");
			}
		}
	}
