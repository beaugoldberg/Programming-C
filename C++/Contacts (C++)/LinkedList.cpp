#include "LinkedList.h"
#include <iostream>
using namespace std;

LL::LL()
{
    head = new ContactNode;
    tail = new ContactNode;
    size = 0;
}

void LL::InsertFront(ContactNode* cn)
{
    cn->setNext(head);
    size += 1;
}

void LL::InsertBack(ContactNode* cn)
{
    tail->setNext(cn);
    cn = tail;
    size += 1;
}

void LL::PrintList()
{
    ContactNode* start = head;
    for (int i = 0; i < size; i++)
    {
        start->PrintContactNode();
        start = start->GetNext();
    }
}