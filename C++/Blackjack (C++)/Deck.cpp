#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Deck.h"
using namespace std;

int Deck::deckSize() {
    return mydeck.size();
}

void Deck::newDeck() {
    if (mydeck.size() > 0) mydeck.clear();
    string name;
    int value;
    string suit;
    
    for (int i = 1; i < 53; i++) {
        if (i <= 13) suit = "Hearts";
        if (i > 13) suit = "Diamonds";
        if (i > 26) suit = "Clubs";
        if (i > 39) suit = "Spades";

        if (i % 13 == 1) {
            name = "Ace";
            value = 1;
        }
        else if (i % 13 == 2) {
            name = "2";
            value = 2;
        }
        else if (i % 13 == 3) {
            name = "3";
            value = 3;
        }
        else if (i % 13 == 4) {
            name = "4";
            value = 4;
        }
        else if (i % 13 == 5) {
            name = "5";
            value = 5;
        }
        else if (i % 13 == 6) {
            name = "6";
            value = 6;
        }
        else if (i % 13 == 7) {
            name = "7";
            value = 7;
        }
        else if (i % 13 == 8) { 
            name = "8";
            value = 8;
        }
        else if (i % 13 == 9) {
            name = "9";
            value = 9;
        }
        else if (i % 13 == 10) {
            name = "10";
            value = 10;
        }
        else if (i % 13 == 11) {
            name = "Jack";
            value = 10;
        }
        else if (i % 13 == 12) {
            name = "Queen";
            value = 10;
        }
        else if (i % 13 == 0) {
            name = "King";
            value = 10;
        }
        Card newCard = Card(name, suit, value);
        mydeck.push_back(newCard);
    }
}

Card Deck::dealCard() {
    srand((int)time(0));
    int index = rand() % mydeck.size();
    Card card1 = mydeck.at(index);
    auto it = mydeck.begin();
    if (index == 0) { mydeck.erase(it); }
    else { mydeck.erase(it + index); }
    return card1;
}