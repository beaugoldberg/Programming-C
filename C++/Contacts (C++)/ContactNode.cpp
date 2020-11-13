#include "ContactNode.h"
#include <iostream>
using namespace std;

ContactNode::ContactNode()
{
    contactName = " ";
    phoneNumber = " ";
    //nextNodePtr = new ContactNode;
    nextNodePtr = NULL;
}

ContactNode::ContactNode(const ContactNode& origNode) {
    contactName = origNode.contactName;
    phoneNumber = origNode.phoneNumber;
    nextNodePtr = origNode.nextNodePtr;
}

ContactNode::ContactNode(string name, string number)
{
    contactName = name;
    phoneNumber = number;
    //nextNodePtr = new ContactNode;
    nextNodePtr = NULL;
}

void ContactNode::InsertAfter(ContactNode* node)
{
    ContactNode* temp = nextNodePtr;
    nextNodePtr = node;
    node->nextNodePtr = temp;
}

string ContactNode::GetName()
{
    return contactName;
}

string ContactNode::GetPhoneNumber()
{
    return phoneNumber;
}

ContactNode* ContactNode::GetNext()
{
    return nextNodePtr;
}

void ContactNode::setNext(ContactNode* cn)
{
    nextNodePtr = cn;
}

void ContactNode::PrintContactNode()
{
    cout << "Name: " << contactName << endl;
    cout << "Phone Number: " << phoneNumber << endl;
}

ContactNode& ContactNode::operator=(const ContactNode& node)
{
    if (this != &node) {            
        *nextNodePtr = *(node.nextNodePtr);           
    }
    return *this;
}