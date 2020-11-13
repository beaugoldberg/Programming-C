#include "node.h"
#include <stdio.h>
#include <stdlib.h>

void InOrder(node* n) {
	if (n == NULL) {
		return;
	}
	InOrder(n->left);
	printf("%d ", n->value);
	InOrder(n->right);
}

void PreOrder(node* n) {
	if (n == NULL) {
		return;
	}
	printf("%d ", n->value);
	PreOrder(n->left);
	PreOrder(n->right);
}

void PostOrder(node* n) {
	if (n == NULL) {
		return;
	}
	PostOrder(n->left);
	PostOrder(n->right);
	printf("%d ", n->value);
}

int depth(node* n) {
	if (n == NULL) {
		return 0;
	}
	int left = depth(n->left);  
	int right = depth(n->right);  
	      
	if (left > right) return(left + 1);  
	else return(right + 1);  
}	
