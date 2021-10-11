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
* this function save data edited in the text file 
*/
void save(info_Data info[], int count)
	{
	int i =0;
	FILE*pInput = NULL;
	
	pInput = fopen("AddressBookDatabase.txt", "w");
	while(i < count)
		{	
		sscanf(info[i].gender, "%s", info[i].gender);
		fprintf(pInput, "%s,", info[i].name);
		fprintf(pInput, "%s,", info[i].date);
		fprintf(pInput, "%s,", info[i].email);
		fprintf(pInput, "%s,", info[i].phone);
		fprintf(pInput, "%s,", info[i].address);
		fprintf(pInput, "%s\n", info[i].gender);
		i++;
		}
	fclose(pInput);
	}

/**************************************************************************
* this function edit name
*/
void editName()
	{
	char stringInput[64];
	char nameSearch[64];
	int count = 0;
	int*line = NULL;
	info_Data*info = NULL;
	int i = 0;
 	int find = 0;	
	char temp[64];
	int search = 0;
	char emailSearch[64];

	printf("\n   >>> Option search by");
	printf("\n   >>> 1 : Name");
	printf("\n   >>> 2 : Email address");
	printf("\n   >>> What do you want search by : ");
	fgets(stringInput, sizeof(stringInput), stdin);
	sscanf(stringInput, "%d", &search);	
	line = calloc(count, sizeof(count));
	info = readFile(&count);
	if(search == 1)
		{
		printf("\n   >>>> Search Name\n");
		printf("   >>> Enter Name : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", nameSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].name, nameSearch, strlen(nameSearch)) == 0)
				{
				display(info[i]);
				printf("   >>>> From : %s To : ", info[i].name);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if(inputName(temp) == 1)
					{
					sscanf(stringInput, "%[^\n]", info[i].name);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else if(search == 2)
		{
		printf("\n   >>>> Search Email address\n");
		printf("   >>>> Enter Email address : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", emailSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].email, emailSearch, strlen(emailSearch)) == 0)
				{
				display(info[i]);
				printf("   >>>> From : %s To : ", info[i].name);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if(inputName(temp) == 1)
					{
					sscanf(stringInput, "%[^\n]", info[i].name);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <----\n");
			}
		}
	else
  		{
		printf(" ----> Error, don't have this option <----\n");
		}
	}

/**************************************************************************
* this function edit birthday
*/
void editDate()
	{
	char stringInput[64];
	char nameSearch[64];
	int count = 0;
	int*line = NULL;
	info_Data*info = NULL;
	int i = 0;
 	int find = 0;	
	char temp[64];
	int search = 0;
	char emailSearch[64];

	printf("\n   >>> Option search by");
	printf("\n   >>> 1 : Name");
	printf("\n   >>> 2 : Email address");
	printf("\n   >>> What do you want search by : ");
	fgets(stringInput, sizeof(stringInput), stdin);
	sscanf(stringInput, "%d", &search);	
	line = calloc(count, sizeof(count));
	info = readFile(&count);
	if(search == 1)
		{
		printf("\n   >>>> Search Name\n");
		printf("   >>>> Enter Name : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", nameSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].name, nameSearch, strlen(nameSearch)) == 0)
				{
				display(info[i]);
				printf("   >>>> From : %s To : ", info[i].date);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if(inputDate(temp) == 1)
					{
					sscanf(stringInput, "%s", info[i].date);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else if(search == 2)
		{
		printf("\n   >>>> Search Email address\n");
		printf("   >>>> Enter Email address : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", emailSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].email, emailSearch, strlen(emailSearch)) == 0)
				{
				display(info[i]);
				printf("   >>>> From : %s To : ", info[i].date);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if(inputDate(temp) == 1)
					{
					sscanf(stringInput, "%s", info[i].date);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else
  		{
		printf(" ----> Error, don't have this option <----\n");
		}
	}

/**************************************************************************
* this function edit email address
*/
void editEmail()
	{
	char stringInput[64];
	char nameSearch[64];
	int count = 0;
	int*line = NULL;
	info_Data*info = NULL;
	int i = 0;
 	int find = 0;	
	char temp[64];
	int search = 0;
	char emailSearch[64];

	printf("\n   >>> Option search by");
	printf("\n   >>> 1 : Name");
	printf("\n   >>> 2 : Email address");
	printf("\n   >>> What do you want search by : ");
	fgets(stringInput, sizeof(stringInput), stdin);
	sscanf(stringInput, "%d", &search);	
	line = calloc(count, sizeof(count));
	info = readFile(&count);
	if(search == 1)
		{
		printf("\n   >>>> Search Name\n");
		printf("   >>>> Enter Name : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", nameSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].name, nameSearch, strlen(nameSearch)) == 0)
				{
				display(info[i]);
				printf("   >>> From : %s To : ", info[i].email);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if(inputEmail(temp) == 1)
					{
					sscanf(stringInput, "%s", info[i].email);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else if(search == 2)
		{
		printf("\n   >>>> Search Email address\n");
		printf("   >>>> Enter Email address : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", emailSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].email, emailSearch, strlen(emailSearch)) == 0)
				{
				display(info[i]);
				printf("   >>>> From : %s To : ", info[i].email);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if(inputEmail(temp) == 1)
					{
					sscanf(stringInput, "%s", info[i].email);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else
  		{
		printf(" ----> Error, don't have this option <----\n");
		}
	}

/**************************************************************************
* this function edit international phone
*/
void editPhone()
	{
	char stringInput[64];
	char nameSearch[64];
	int count = 0;
	int*line = NULL;
	info_Data*info = NULL;
	int i = 0;
 	int find = 0;	
	char temp[64];
	int search = 0;
	char emailSearch[64];

	printf("\n   >>> Option search by");
	printf("\n   >>> 1 : Name");
	printf("\n   >>> 2 : Email");
	printf("\n   >>> What do you want search by : ");
	fgets(stringInput, sizeof(stringInput), stdin);
	sscanf(stringInput, "%d", &search);	
	line = calloc(count, sizeof(count));
	info = readFile(&count);
	if(search == 1)
		{
		printf("\n   >>>> Search Name\n");
		printf("   >>>> Enter Name : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", nameSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].name, nameSearch, strlen(nameSearch)) == 0)
				{
				display(info[i]);
				printf("   >>>> From : %s To : ", info[i].phone);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if(inputPhone(temp) == 1)
					{
					sscanf(stringInput, "%s", info[i].phone);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else if(search == 2)
		{
		printf("\n   >>>> Search Email address\n");
		printf("   >>>> Enter Email address : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", emailSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].email, emailSearch, strlen(emailSearch)) == 0)
				{
				display(info[i]);
				printf("   >>> From : %s To : ", info[i].phone);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if(inputDate(temp) == 1)
					{
					sscanf(stringInput, "%[^\n]", info[i].phone);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else
  		{
		printf(" ----> Error, don't have this option <----\n");
		}
	}

/**************************************************************************
* this function edit address
*/
void editAddress()
	{
	char stringInput[64];
	char nameSearch[64];
	int count = 0;
	int*line = NULL;
	info_Data*info = NULL;
	int i = 0;
 	int find = 0;	
	char temp[64];
	int search = 0;
	char emailSearch[64];

	printf("\n   >>> Option search by");
	printf("\n   >>> 1 : Name");
	printf("\n   >>> 2 : Email adress");
	printf("\n   >>> What do you want search by : ");
	fgets(stringInput, sizeof(stringInput), stdin);
	sscanf(stringInput, "%d", &search);	
	line = calloc(count, sizeof(count));
	info = readFile(&count);
	if(search == 1)
		{
		printf("\n   >>>> Search Name\n");
		printf("   >>>> Enter Name : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", nameSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].name, nameSearch, strlen(nameSearch)) == 0)
				{
				display(info[i]);
				printf("   >>>> From : %s To : ", info[i].address);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if(checkAddress(temp) == 1)
					{
					sscanf(stringInput, "%[^\n]", info[i].address);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else if(search == 2)
		{
		printf("\n   >>>> Search Email address\n");
		printf("   >>>> Enter Email address : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", emailSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].email, emailSearch, strlen(emailSearch)) == 0)
				{
				display(info[i]);
				printf("   >>>> From : %s To : ", info[i].address);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if(checkAddress(temp) == 1)
					{
					sscanf(stringInput, "%[^\n]", info[i].address);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else
  		{
		printf(" ----> Error, don't have this option <----\n");
		}
	}

/**************************************************************************
* this function edit gender
*/
void editGender()
	{
	char stringInput[64];
	char nameSearch[64];
	int count = 0;
	int*line = NULL;
	info_Data*info = NULL;
	int i = 0;
 	int find = 0;	
	char temp[64];
	int search = 0;
	char emailSearch[64];
	char genderS[64];

	printf("\n   >>> Option search by");
	printf("\n   >>> 1 : Name");
	printf("\n   >>> 2 : Email adress");
	printf("\n   >>> What do you want search by : ");
	fgets(stringInput, sizeof(stringInput), stdin);
	sscanf(stringInput, "%d", &search);	
	line = calloc(count, sizeof(count));
	info = readFile(&count);
	if(search == 1)
		{
		printf("\n   >>>> Search Name\n");
		printf("   >>>> Enter Name : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", nameSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].name, nameSearch, strlen(nameSearch)) == 0)
				{
				display(info[i]);
				sscanf(info[i].gender , "%s", genderS);
				trimWhitespace(genderS);
				printf("   >>>> From : %s To : ", genderS);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if((strcmp(temp, "M") == 0) || (strcmp(temp, "F") == 0) || (strcmp(temp, "O") == 0))
					{
					sscanf(stringInput, "%s", info[i].gender);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else if(search == 2)
		{
		printf("\n   >>>> Search Email address\n");
		printf("   >>>> Enter Email address : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%s", emailSearch);
		for(i = 0; i < count; i++)
			{
			if(strncasecmp(info[i].email, emailSearch, strlen(emailSearch)) == 0)
				{
				display(info[i]);
				sscanf(info[i].gender , "%s", genderS);
				trimWhitespace(genderS);
				printf("   >>>> From : %s To : ", genderS);
				fgets(stringInput, sizeof(stringInput), stdin);
				sscanf(stringInput, "%s", temp);
				if((strcmp(temp, "M") == 0) || (strcmp(temp, "F") == 0) || (strcmp(temp, "O") == 0))
					{
					sscanf(stringInput, "%s", info[i].gender);
					save(info, count);
					}
				else
					{
					printf("----> Invalid form <----\n");
					}
				find++;
				}
			}
		if(find == 0)
			{
			printf(" ----> Don't found <---- \n");
			}
		}
	else
  		{
		printf(" ----> Error, don't have this option <----\n");
		}
	}

/**************************************************************************
* this function ask user want edit data.
*/
void edit()
	{
	char stringInput[64];
	int select = 0;
	
	while(1)
		{
		printf("\n   >> Option of edit a data.\n");
		printf("   >> 1 : Edit Name\n");
		printf("   >> 2 : Edit Birthday \n");
		printf("   >> 3 : Edit Email address\n");
       	 	printf("   >> 4 : Edit International phone\n");
        	printf("   >> 5 : Edit Address\n");
       		printf("   >> 6 : Edit Gender\n");
		printf("   >> 7 : End this menu\n");
		printf("   >> What do you want edit? : ");
		fgets(stringInput, sizeof(stringInput), stdin);
		sscanf(stringInput, "%d", &select);
		if(select == 1)
			{
			editName();
			}
		else if(select == 2)
			{
			editDate();
			}
		else if(select == 3)
			{
			editEmail();
			}
       		else if(select == 4)
			{
			editPhone();
			}
        	else if(select == 5)
			{
			editAddress();
			}
        	else if(select == 6)
			{
			editGender();
			}
		else if(select == 7)
			{
			break;
			}
		}
	}
