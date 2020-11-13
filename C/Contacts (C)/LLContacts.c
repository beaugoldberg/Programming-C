#include "LLContacts.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void InitContactList(llc* l) {
	
	l->head = (ContactNode*)malloc(sizeof(ContactNode));
	l->head->nextNodePtr = NULL;
	l->size = 0;
}

void InsertContact(llc* l, char* name, char* phone) {
	if (l->size == 0) {
		strcpy(l->head->contactName, name);
		for(int i = 0; i < strlen(l->head->contactName); i++) {
			l->head->contactName[i] = toupper(l->head->contactName[i]);
		}
		strcpy(l->head->contactPhoneNum, phone);
		l->head->nextNodePtr = NULL;
		l->size += 1;
	}
	else {
		ContactNode* start = l->head;
		ContactNode* temp = NULL;
		ContactNode* newNode = NULL;
		temp = (ContactNode*)malloc(sizeof(ContactNode));
		newNode = (ContactNode*)malloc(sizeof(ContactNode));
		strcpy(newNode->contactName, name);
		for(int i = 0; i < strlen(newNode->contactName); i++) {
			newNode->contactName[i] = toupper(newNode->contactName[i]);
		}
		strcpy(newNode->contactPhoneNum, phone);
		int loop = 0;
		while (loop == 0) {
			if (strcmp(start->contactName,newNode->contactName) > 0) {
				newNode->nextNodePtr = start;
				l->head = newNode;
				loop = 1;
			}
			else if (strcmp(start->contactName,newNode->contactName) < 0 && start->nextNodePtr == NULL) {
				start->nextNodePtr = newNode;
				newNode->nextNodePtr = NULL;
				loop = 1;
			}
			else if (strcmp(start->contactName,newNode->contactName) < 0 && strcmp(newNode->contactName,start->nextNodePtr->contactName) < 0){
				temp = start->nextNodePtr;
				start->nextNodePtr = newNode;
				newNode->nextNodePtr = temp;
				loop = 1;
			}
			start = start->nextNodePtr;
		}
		l->size += 1;
	}
}

void DisplayContactList(llc* l) {
	printf("CONTACT LIST\n");
	ContactNode* start = l->head;
	for (int i = 0; i < l->size; i++) {
		printf("%-20s %s\n", start->contactName, start->contactPhoneNum);
		start = start->nextNodePtr;
	}
}	
