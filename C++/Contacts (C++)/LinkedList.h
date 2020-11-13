#include <iostream>
#include <string>
#include "ContactNode.h"
using namespace std;

class LL {
    public:
     LL();
     void InsertFront(ContactNode* cn);
     void InsertBack(ContactNode* cn);
     void PrintList();

    private:
     ContactNode* head;
     ContactNode* tail;
     int size;
};