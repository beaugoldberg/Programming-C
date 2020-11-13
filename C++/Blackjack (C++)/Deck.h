#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
using namespace std;

class Deck {
    public:
     int deckSize();     // Returns the current size of the deck
     void newDeck();     // Clears the current deck and creates a new deck (reshuffle)
     Card dealCard();    // Chooses a random card out of the deck

    private:
     vector<Card> mydeck;
};