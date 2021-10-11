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

/*************************************************************************************
* this function is menu selection forfurther
*/
int main()
	{
	char stringInput[64];
	int count = 0;
	int select = 0;
	int i = 0;
	info_Data *info = NULL;
	
	printf("\n\n<<------------------------------------------------>>\n");
	printf("\t\tADDRESS BOOK DATABAES\n");
	printf("<<------------------------------------------------>>\n");
	while(1)
		{
		info = readFile(&count);
		printf("\n----> Menu Contacts Book <-----\n");
		printf("   > 1 : Display a data\n");
		printf("   > 2 : Add a data\n");	
		printf("   > 3 : Search for a data\n");
		printf("   > 4 : Edit a data\n");
		printf("   > 5 : Exit the program\n");
		printf("   > What do you want to use? : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%d", &select);
		
		if(select == 1)
			{
			for(i = 0; i < count; i++)
				{
				printf("\n   >> Info No.%d", i+1);
				display(info[i]);
				}
			}
		else if(select == 2)
			{
			addStoreData();
			}
		else if(select == 3)
			{
			search();
			}
		else if(select == 4)
			{
			edit();
			}
		else if(select == 5)
			{
			printf("\n----------> GoodBye! see you next time. <-----------\n\n");
			break;
			}
		else
			{
			printf("\n----> Error, don't have this manu <-----\n");
			}
		}
	}
