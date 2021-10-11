/***************************************************************************************
*	
*	Created by Prakasit Issanapong (Tar) 
*   	ID 62070503431
*   	Date 12/12/2019
*
****************************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/***************************************************************************************
*  This funtion check month must be numbers only.
*  'mm' is month 
*/
int checkDigitD(char mm[])
	{
	int i = 0; 		/* loop counter*/
	int check = 0; 		/* hold return value */
	
	for(i = 0; i < strlen(mm); i++)
		{
	    if((isdigit(mm[i]) != 0)) 
			{
			check = 1;
			break;
			}
		else 
			{
			check = 0;
			break;
			}
		}
	return(check);
	}

/***************************************************************************************
*  This funtion check form date which user input must be dd/mm/yyyy and 
*  month must have 30 day, month must have 31 day and month must have 28 or 29 day.
*  'date' is data which user input.
*/
int checkForm(char date[])
	{
	const char slash [2] = "-";	/*set constant is " - " */
	char dd[3]; 			/* day in form string */
	char mm[3]; 			/* month in form string */
	char yyyy[5];			/* year in form string */
	int ddD, mmD, yyyyD, checkM, checkF = 0; /* day, month, year in form digit and hold return value */
	 
	strcpy(dd,(strtok(date,slash)));
	strcpy(mm,(strtok(NULL,slash)));
	strcpy(yyyy,(strtok(NULL,slash)));
	sscanf(dd, "%d", &ddD);
	sscanf(mm, "%d", &mmD);
	sscanf(yyyy, "%d", &yyyyD);
	
	if((strlen(dd) == 2) && (strlen(mm) == 2) && (strlen(yyyy) == 4))
		{
		checkM = checkDigitD(mm);
		if((checkM == 1) && (yyyyD <= 2119) && (yyyyD >= 1919) && (mmD != 2))
			{
			if((ddD >= 1 && ddD <= 30) && ((mmD == 4) || (mmD == 6) || (mmD == 9) || (mmD == 11)))
				{
				checkF = 1;	
				}
			else if((ddD >= 1 && ddD <= 31) && ((mmD == 1) || (mmD == 3) || (mmD == 5) || (mmD == 7) || (mmD == 8) || (mmD == 10) || (mmD == 12)))
				{
				checkF = 1;
				}			
			else 
				{
				checkF = 0;
				}
			}
		else if((checkM == 1) && (yyyyD % 4 == 0) && (mmD == 2))
			{
			if((ddD >= 1) && (ddD <= 29))
				{
				checkF = 1;
				}
			}
		else if((checkM == 1) && (yyyyD % 4 != 0) && (mmD == 2))
			{
			if((ddD >= 1) && (ddD <= 28))
				{
				checkF = 1;
				}
			}
		else
			{
			checkF = 0;
			}
		}
		return(checkF);
	}

/*****************************************************************************************
*  This funtion check data before at-sign must be a-b, numbers, "-", "_", "." only
*  'beAdd' is data before at-sign.
*/
int checkBeAdd(char beAdd[])
	{
	int i = 0;	/* loop counter*/
	int check = 0;	/* hold return value */
	if(isalnum(beAdd[0])==0)
	{
		return 0;
	}
	for(i = 0; i < strlen(beAdd); i++)
		{
		if(isalnum(beAdd[i]) != 0 || beAdd[i] == 95 || beAdd[i] == 46 || beAdd[i] == 45) 
			{
			check = 1;
			}
		else 
			{
			return(0);
			}
		}
	return(check);
	}

/***************************************************************************************
*  This funtion check data after at-sign but before top­level domains 
*  must be a-b, "-", "." only
*  'afAdd' is data after at-sign.
*/
int checkEmailFinal(char afAdd[])
	{
	int i = 0;			/* loop counter*/
	int checkPoint = 0;	/* count dot */
	for(i = 0; i < strlen(afAdd); i++)
		{
		if(!((afAdd[i] >= 65 && afAdd[i] <= 90) || (afAdd[i] >= 97 && afAdd[i] <= 122) || afAdd[i] == 46 || afAdd[i] == '-'))	
			{
			return(0);
			}
		else if(afAdd[i] == '.')
			{
			if(checkPoint == 0)
				{
				checkPoint = 1;
				}
			else
				{
				return 0;
				}
			}
		else
			{
			checkPoint = 0;
			}
		} 
		if(afAdd[strlen(afAdd)-1] == '.')
			return 0;
		return 1;
	}

/***************************************************************************************
*  This funtion check top­level domains 
*  'afAdd' is data after at-sing.
*/
int checkAfAdd(char *afAdd)
	{
	int len = strlen(afAdd);	/* number of characters after at-sign */
	int check = 0;			/* hold return value */

	if (len >= 4 && (strcmp(&afAdd[len-4],".com") == 0 || strcmp(&afAdd[len-4],".net") == 0 ))
		{
		afAdd[len-4]='\0';
		check = checkEmailFinal(afAdd);
		}
	else if (len >= 6 && (strcmp(&afAdd[len-6],".co.th") == 0 || strcmp(&afAdd[len-6],".ac.th") == 0))
		{
		afAdd[len-6]='\0';
		check = checkEmailFinal(afAdd);
		}
	else
		{
		check = 0;
		}
		
	return(check);	
	}

/***************************************************************************************
*  This funtion separate data email into 2 parts.
*  'email' is email which user input.
*/
int checkFormEmail(char email[])
	{
	const char add[2] = "@";	/*set constant is " @ " */
	char beAdd[32];			/* 'beAdd' is data before at-sing. */
	char afAdd[32];			/* 'afAdd' is data after at-sing. */
	int check = 0;			/* hold return value */
	
	strcpy(beAdd, strtok(email, add));
	
	if(checkBeAdd(beAdd) == 1)
		{
		check = checkAfAdd(strtok(NULL,add));
		}
	return(check);
	}

/***************************************************************************************
*  This function check international phone number must be numbers only.
*  'number' is last data part international phone number which user input. 
*/
int checkDigitPI(char number[])
	{
	int i = 0;	/* loop counter*/
	int checkA = 0;	/* hold return value */
	
	for(i = 0; i < strlen(number); i++)
		{
	    if(isdigit(number[i]) != 0) 
			{
			return(1);
			}
		else 
			{
			return(0);
			}
		}
	}

/***************************************************************************************
*  This function separate international phone number into 3 parts and
*  checks each parts form.
*  'phoneNumber' is data international phone number which user input. 
*/
int checkCountryCode(char phoneNumber[])
	{
	int checkD = 0;
	const char dashes[2] = "-";
	char country[32];
	char area[32];
	char number[32];
	int i = 0;
	int count = 0;
	
	for(i = 0; i < strlen(phoneNumber);i++)
		{
		if(phoneNumber[i] == '-')
			{
			count++;
			}
		}
	if(count == 2)
		{
		strcpy(country,strtok(phoneNumber, dashes));
		strcpy(area,strtok(NULL, dashes));
		strcpy(number,strtok(NULL, dashes));		
		}
	else
		{
		checkD = 0;
 		}
	
	if((strlen(country)) >= 2 && (strlen(country)) <= 4)
		{
		if((strlen(area)) >= 1 && (strlen(area)) <= 3)
			{
			if((strlen(number)) >= 6 && (strlen(number)) <= 10)
				{
				checkD = checkDigitPI(number);
				}
			else 
				{
				checkD = 0;
				}
			}
		else 
			{
			checkD = 0;
			}
		}
	else
		{
		checkD = 0;
		}
	return(checkD);
	}

/********************************************************************************************
*  This function check form address if valid return 1 
*/
int checkAddress(char address[])
	{
	int i = 0;
	int check = 0;  

	for(i = 0; i < strlen(address); i++)
		{
		if((address[i] == '/') || (address[i] == ' ') || (address[i] >= 65 && address[i] <= 90) || (address[i] >= 97 && address[i] <= 122) || (address[i] >= 48 && address[i] <= 57))
			{
			check = 1;
			}
		else
			{
			check = 0;
			break;
			}
		}
	return(check);
	}

/********************************************************************************************
*  This function check form name if valid return 1 
*/
int inputName(char name[])	
	{
	int i = 0;
	int valid =0;
	valid = 1;
	if(name[0] == '\n')
		{
		return(0);	
		}
	for(i = 0; i < strlen(name) && (name[i] != '\n') && (valid); i++)
		{
		if((!isalpha(name[i])) && (!isspace(name[i])))
			{
			valid = 0;
			}
		}
	if(valid)
		{
		return(1);
		}
	else
		{
		return(0);		
		}
	}

/********************************************************************************************
*  This function check form Date if valid return 1 
*/
int inputDate(char date[])
	{
	if((date[2] == '-') && (date[5] == '-'))
		{
		if(checkForm(date) == 1)
			{
			return(1);
			}
		else 
			{
			return(0);	
			} 
		}
	else 
		{
		return(0);
		}
	}

/********************************************************************************************
*  This function check form email if valid return 1 
*/
int inputEmail(char email[])
	{
	int adsing;
	int i = 0;
	adsing = 0;
	for(i = 0; i < strlen(email); i++)
		{
		if(email[i] == '@')
			{
			adsing++;
			}
		}
	if(adsing == 1)
		{
		if(checkFormEmail(email) == 1)
			{
			return(1);
			}
		else
			{
			return(0);
			}
		}
	else
		{
		return(0);
		}
	}

/********************************************************************************************
*  This function check form international phone if valid return 1 
*/
int inputPhone(char phone[])
	{
	int plus;
	int i = 0;
	plus = 0;

	for(i = 0; i < strlen(phone); i++)
		{
		if(phone[i] == '+')
			{
			plus++;
			}
		}
	if((phone[0] == '+') && (plus == 1))
		{
		if(checkCountryCode(phone) == 1)
			{
			return(1);
			}
		else if(checkCountryCode(phone) == 0)
			{
			return(0);
			}
		}
	else
		{
		return(0);
		}	
	}
/********************************************************************************************
*  This function delete whitespace in string
*/
void trimWhitespace(char string[])
	{
	int i;
	for(i = strlen(string)-1; i >= 0; i--)
		{
		if(isspace(string[i]))
			{
			string[i] = '\0';
			}
		}
	}
