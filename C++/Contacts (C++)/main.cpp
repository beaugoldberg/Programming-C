#include "ContactNode.h"
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string name;
    string number;

    cout << "Person 1" << endl;
    cout << "Enter name:" << endl;
    getline(cin, name);

    cout << "Enter phone number:" << endl;
    getline(cin, number);

    cout << "You entered: " << name << ", " << number << endl;

    ContactNode person1 = ContactNode(name, number);

    cout << "Person 2" << endl;
    cout << "Enter name:" << endl;
    getline(cin, name);

    cout << "Enter phone number:" << endl;
    getline(cin, number);

    cout << "You entered: " << name << ", " << number << endl;

    ContactNode person2 = ContactNode(name, number);
    person1.InsertAfter(&person2);

    cout << "Person 3" << endl;
    cout << "Enter name:" << endl;
    getline(cin, name);

    cout << "Enter phone number:" << endl;
    getline(cin, number);

    cout << "You entered: " << name << ", " << number << endl;

    ContactNode person3 = ContactNode(name, number);
    person2.InsertAfter(&person3);

    cout << "CONTACT LIST" << endl;
    ContactNode* start = &person1;
    for(int i = 0; i < 3; i++)
    {
        start->PrintContactNode();
        start = start->GetNext();
    }

}