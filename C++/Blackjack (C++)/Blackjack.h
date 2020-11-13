#include <iostream>
#include <string>
#include <vector>
#include "Deck.h"
using namespace std;

class Blackjack {
    public:
     void displayIntro();
     void displayPlayerHand(Blackjack game);       // Prints the players hand
     void displayBustOutro(Blackjack game);        // Prints out sequence for if the player busts
     void displayDealerBlackjack(Blackjack game);  // Prints out sequence for if the dealer gets a natural blackjack
     void displayOutro(int balance);               // Prints out final profit/loss statement for the player
     int updateHandValue(int choice);              // Calculates the hand value for either dealer or player
     string updateHandtoPrint();                   // Used for printing player hand if Aces are in player hand
     void printHand(int choice);                   // Prints the hand of either the dealer or the player
     void addUserHand(Card card);                  // Used to add cards to player deck
     void addDealerHand(Card card);                // Used to add cards to dealer deck
     void clearHands();                            // Clears both the dealer and player hands for new hands
     int checkNaturalBlackjack(int choice);        // Used to check if either dealer or player has a natural blackjack

    private:
     vector<Card> userHand;                        // Users' hand
     vector<Card> dealerDeck;                      // Dealers' hand
};