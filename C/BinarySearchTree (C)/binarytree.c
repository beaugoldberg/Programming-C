#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void initialize(binary_tree* bt) {
	bt->root = (node*)malloc(sizeof(node));
	bt->root->left = NULL;
	bt->root->right = NULL;
	bt->size = 0;
}

int checkInitialize(binary_tree* bt) {
	node* headNode = bt->root;
	if (headNode->left == NULL && headNode->left == NULL && bt->size == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

_Bool search(binary_tree* bt, int key) {
	node* currentNode = bt->root;
	while (currentNode != NULL) {                           //Will continue through tree looking for key until hits a pointer to NULL 
		if (currentNode->value == key) { 
			return true;
		}
		else {
			if (key < currentNode->value) {
				currentNode = currentNode->left;
			}
			else if (key > currentNode->value) {
				currentNode = currentNode->right;
			}
		}
	}
	return false;
}

void insert(binary_tree* bt, int item) {
	if (bt->size == 0) {
		bt->root->value = item;
		bt->size += 1;
	}
	else {	
		node* newNode = NULL;                          //
		newNode = (node*)malloc(sizeof(node));         //
		newNode->value = item;                         // Creates and initializes the new node with proper value
		newNode->left = NULL;                          //
		newNode->right = NULL;                         //
		node* currentNode = bt->root;
		int found = 0;                  //Used to stay in loop until a Null placeholder is found where we will insert the node
		while (found == 0) {
			if (item < currentNode->value && currentNode->left == NULL) { 
				currentNode->left = newNode; 
				found = 1;
			}
			else if (item < currentNode->value && currentNode->left != NULL) { 
				currentNode = currentNode->left; 
			}
			else if (item > currentNode->value && currentNode->right == NULL) {
				currentNode->right = newNode;
				found = 1;
			}
			else if (item > currentNode->value && currentNode->right != NULL) { 
				currentNode = currentNode->right; 
			}
		}
		bt->size += 1;
	}
}

int checkinsert(binary_tree* bt, int item) {
	if (bt->root->value == item) {
		return 0;
	}
	else {
		return -1;
	}
}

void printinorder(binary_tree* bt) {
	InOrder(bt->root);
}

void printpreorder(binary_tree* bt) {
	PreOrder(bt->root);
}

void printpostorder(binary_tree* bt) {
	PostOrder(bt->root);
}

int btsize(binary_tree* bt) {
	return bt->size;
}

int treeheight(binary_tree* bt) {
	return depth(bt->root) - 1;
}
