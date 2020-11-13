#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

Card::Card() {
    name = " ";
    suit = " ";
    value = 0;
}

Card::Card(string cardName, string cardSuit, int cardValue) {
    name = cardName;
    suit = cardSuit;
    value = cardValue;
}

void Card::setName(string cardName) {
    name = cardName;
}

void Card::setSuit(string cardSuit) {
    suit = cardSuit;
}

void Card::setValue(int cardValue) {
    value = cardValue;
}

string Card::getName() {
    return name;
}

string Card::getSuit() {
    return suit;
}

int Card::getValue() {
    return value;
}

void Card::printCard() {
    cout << name << " of " << suit << endl;
}