#include "LLContacts.h"
#include "Contact.h"
#include <stdio.h>

int main(void) {
	char c = 'y';
	char buffer; // Used to clear input buffer
	llc l;
	InitContactList(&l);
	
	while (c == 'y') {

		char fullNameArr[50];
		char phoneNumArr[50];

		printf("Enter name:\n");
		scanf("%[^\n]s,", fullNameArr);
		buffer = getchar();
		//while ((getchar()) != '\n'); 
		
		printf("Enter phone number:\n");
		scanf("%[^\n]s,", phoneNumArr);
		buffer = getchar();

		char* fullName = &fullNameArr[0];
	        char* phoneNum = &phoneNumArr[0];
				
		InsertContact(&l, fullName, phoneNum);
		
		printf("Enter another contact? (y/n):\n");
		scanf("%c", &c);
		buffer = getchar(); 
		printf("\n");
	}

	DisplayContactList(&l);

	return 0;
}
