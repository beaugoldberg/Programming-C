#include <iostream>
#include <string>
using namespace std;

class Card {
    public :
     void setName(string cardName);                             
     void setSuit(string cardSuit);                             
     void setValue(int cardValue);                           
     string getName();
     string getSuit();
     int getValue();
     void printCard();
     Card();
     Card(string cardName, string cardSuit, int cardValue);     

    private:
     string name;
     string suit;
     int value;
};
