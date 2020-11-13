#include "LinkedList.h"
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int main()
{
    clock_t begin,end;
    double timespent;
    LL contacts;
    vector<ContactNode> vector_contact;
    vector<ContactNode*> vector_pointer;

    begin = clock();
    for (int i = 0; i < 50000; i++)
    {
        ContactNode* person = new ContactNode();
        contacts.InsertFront(person);
    }
    end = clock();
    timespent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << "Time creating linked list: " << timespent << endl;

    begin = clock();
    for (int i = 0; i < 50000; i++)
    {
        ContactNode* person = new ContactNode();
        auto pos = vector_contact.begin();
        vector_contact.insert(pos, *person);
    }
    end = clock();
    timespent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << "Time creating vector: " << timespent << endl;

    begin = clock();
    for (int i = 0; i < 50000; i++)
    {
        ContactNode* person = new ContactNode();
        auto pos = vector_pointer.begin();
        vector_pointer.insert(pos, person);
    }
    end = clock();
    timespent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << "Time creating vector of pointers to contact nodes: " << timespent << endl;

    




}