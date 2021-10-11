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

/****************************************************************************************
* this function show data on terminal.
*/
void display(info_Data user)
	{
	printf("\n   >> Name  : %s\n", user.name);
	printf("   >> Birthday  : %s\n", user.date);
	printf("   >> Email address  : %s\n", user.email);
	printf("   >> International phone  : %s\n", user.phone);
	printf("   >> Address  : %s\n", user.address);
	printf("   >> Gender  : %s\n", user.gender);		
	}

