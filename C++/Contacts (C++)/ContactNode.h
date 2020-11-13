#include <iostream>
#include <string>
using namespace std;

class ContactNode
{
    public:
     ContactNode();
     ContactNode(const ContactNode& origNode);
     ContactNode(string name, string number);
     void InsertAfter(ContactNode* node);
     string GetName();
     string GetPhoneNumber();
     ContactNode* GetNext();
     void setNext(ContactNode* cn);
     void PrintContactNode();
     ContactNode& operator=(const ContactNode& node);

    private:
     string contactName;
     string phoneNumber;
     ContactNode* nextNodePtr;
};

