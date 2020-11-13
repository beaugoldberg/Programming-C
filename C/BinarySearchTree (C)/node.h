#ifndef NODE_H
#define NODE_H

typedef struct node_struct {
   int value;
   struct node_struct* left;
   struct node_struct* right;
} node;
                                    
//
// Using these functions in addition to functions in binarytree.c to solve recursively given the root node of the binary tree
//

void InOrder(node* n);         //Used to print binary tree in order
void PreOrder(node* n);        //Used to print binary tree in pre-order
void PostOrder(node* n);       //Used to print binary tree in post-order
int depth(node* n);            //Used to recursivly find the height of the tree

#endif
