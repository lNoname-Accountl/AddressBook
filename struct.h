/***************************************************************************************
*	
*	Created by Prakasit Issanapong (Tar) 
*   	ID 62070503431
*   	Date 12/12/2019
*
****************************************************************************************
*/

typedef struct	
	{
	char name[64];
	char date[32];
	char email[64];
	char phone[32];
	char address[128];
	char gender[32];
	}info_Data;

void addStoreData();

int checkDigitD(char mm[]);

int checkForm(char date[]);
	
int checkBeAdd(char beAdd[]);

int checkEmailFinal(char afAdd[]);
	
int checkAfAdd(char *afAdd);
	
int checkFormEmail(char email[]);
	 
int checkDigitPI(char number[]);
	 	
int checkCountryCode(char phoneNumber[]);
	
int checkAddress(char address[]);
	
int inputName(char name[]);

int inputDate(char name[]);

int inputEmail(char email[]);

int inputPhone(char phone[]);

info_Data*readFile(int*counter);

void display(info_Data user);

void searchName();

void searchEmail();

void search();

void edit();

void editName();

void editDate();

void editEmail();

void editPhone();

void editAddress();

void editGender();

void save(info_Data info[], int count);

void trimWhitespace(char string[]);
