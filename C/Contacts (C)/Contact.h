#ifndef CONTACTNODE_H
#define CONTACTNODE_H

typedef struct ContactNode_struct {
   char contactName[50];
   char contactPhoneNum[50];
   struct ContactNode_struct* nextNodePtr;
} ContactNode;

#endif
