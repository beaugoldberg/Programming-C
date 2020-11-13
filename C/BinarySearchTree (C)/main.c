#include "node.h"
#include "binarytree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv []) {
	int value = 0;
	_Bool found;

	binary_tree bt;
	initialize(&bt);
	
	FILE* inFile = NULL; // File pointer

	if (argc == 1) {
		printf("Needs a file argument.\n");
		return -1; // -1 indicates error
	}

    	inFile = fopen(argv[1], "r");

    	if (inFile == NULL) {
       		printf("File does not exist.\n");
       		return -1; // -1 indicates error
    	}
	
	fscanf(inFile,"%d",&value);
    	while (!feof(inFile)) { 
		insert(&bt, value);
		fscanf(inFile,"%d",&value);
	}
		 
	printf("Print in order\n");
	printinorder(&bt);
	printf("\nPrint pre order\n");
	printpreorder(&bt);
	printf("\nPrint post order\n");
	printpostorder(&bt);
	printf("\n");
	found = search(&bt,33);
	if (found){
	printf("FOUND 33\n");
	}
	found = search(&bt,38);
	if (found){
	printf("FOUND 38\n");
	}
	printf("Number of elements in tree: %d\n", btsize(&bt));
	printf("Tree height: %d\n", treeheight(&bt));

	return 0;
}
