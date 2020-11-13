#include <iostream>
#include <string>
#include <vector>
#include "Blackjack.h"
using namespace std;

void Blackjack::displayIntro()
{
    cout << "********************************" << endl;
    cout << "**    Welcome to Blackjack!   **" << endl;
    cout << "********************************" << endl;
    cout << "**          Winnings          **" << endl;
    cout << "** -------------------------- **" << endl;
    cout << "**       Push        - 0:0    **" << endl;
    cout << "**    High Count     - 1:1    **" << endl;
    cout << "** Natural Blackjack - 3:2    **" << endl;
    cout << "********************************" << endl;
}

void Blackjack::displayPlayerHand(Blackjack game)
{
    cout << "*****************************" << endl;
    cout << "         Player hand         " << endl;
    cout << "*****************************" << endl;

    game.printHand(0);
    cout << "Your hand total: " << game.updateHandtoPrint() << endl;
}

void Blackjack::displayBustOutro(Blackjack game) 
{
    cout << endl;
    cout << "*****************************" << endl;
    cout << "**          Bust           **" << endl; 
    cout << "*****************************" << endl;
    cout << "Losing hand:                 " << endl;
    game.printHand(0);
    cout << "Your hand total: " << game.updateHandValue(0) << endl << endl;
}

void Blackjack::displayDealerBlackjack(Blackjack game)
{
    cout << "*****************************" << endl;
    cout << "**   Winning Dealer Hand   **" << endl;
    cout << "*****************************" << endl;
    for (int i = 0; i < game.dealerDeck.size(); i++) {
        game.dealerDeck.at(i).printCard();
    }
    cout << endl;
}

void Blackjack::displayOutro(int difference)
{
    if (difference > 0) { cout << "You won $" << difference << ". Congratulations!" << endl; }
    else if (difference < 0) { cout << "You lost $" << difference << ". Better luck next time!" << endl; }
    else { cout << "You broke even. Come play again soon to see if you can win!" << endl; }
}

int Blackjack::updateHandValue(int choice)
{
    int handValue = 0;
    int ace;
    int acepath;
    int bigAce = 0;
    int smallAce = 0;
    Card current;
    vector<Card> deck;
    if (choice == 0) { deck = userHand; }
    else if (choice == 1) { deck = dealerDeck; }
    for (int i = 0; i < deck.size(); i++) 
    {
        current = deck.at(i);
        if (current.getName() == "Ace") {
            ace = 1; 
            acepath = 0;
        }

        int hypo = handValue + 11;
        if (handValue <= 21 && hypo <= 21 && ace == 1 && acepath == 0) {
            handValue += 11; 
            acepath = 1;
            bigAce += 1;
        } 
        else if (handValue <= 21 && hypo >= 21 && ace == 1 && acepath == 0) {
            handValue += 1; 
            acepath = 1;
            smallAce += 1;
        }
        else { 
            handValue += current.getValue(); 
        }

        if (handValue > 21 && bigAce == 1) {
             handValue -= 10;
             bigAce -= 1;
        }
    }
    return handValue;
}

string Blackjack::updateHandtoPrint() 
{
    int handValue = 0;
    int smallValue = 0;
    int ace;
    int acepath;
    int bigAce = 0;
    int smallAce = 0;
    string biggerValue;
    string lesserValue;
    Card current;
    for (int i = 0; i < userHand.size(); i++) 
    {
        current = userHand.at(i);
        if (current.getName() == "Ace") {
            ace = 1; 
            acepath = 0;
        }

        int hypo = handValue + 11;
        if (handValue <= 21 && hypo <= 21 && ace == 1 && acepath == 0) {
            handValue += 11; 
            acepath = 1;
            bigAce += 1;
        } 
        else if (handValue <= 21 && hypo >= 21 && ace == 1 && acepath == 0) {
            handValue += 1; 
            acepath = 1;
            smallAce += 1;
        }
        else { 
            handValue += current.getValue(); 
        }

        if (handValue > 21 && bigAce == 1) {
             handValue -= 10;
             bigAce -= 1;
        }
    }
    
    if (bigAce == 1 && handValue != 21) {
        smallValue = handValue - 10;
        lesserValue = to_string(smallValue);
        biggerValue = to_string(handValue);
        return biggerValue + " or " + lesserValue;
    }
    else {
        biggerValue = to_string(handValue);
        return biggerValue;
    }
}

void Blackjack::printHand(int choice)
{
    vector<Card> deck;
    Card currentCard;
    if (choice == 0) { deck = userHand; }
    else if (choice == 1 || choice == 2) { deck = dealerDeck; }
    if (choice == 0 || choice == 1) {
        for (int i = 0; i < deck.size(); i++) {
            currentCard = deck.at(i);
            currentCard.printCard();
        }
    }
    else if (choice == 2) {
        Card firstCard = dealerDeck.at(0);
        firstCard.printCard();
        if (firstCard.getName() == "Ace") { 
            string ifAce = "1 or 11"; 
            cout << "Dealer hand value: " << ifAce << endl;
        }
        else {
            int value = firstCard.getValue();
            cout << "Dealer hand value: " << value << endl;
        }
    }
}

void Blackjack::addUserHand(Card card) 
{
    userHand.push_back(card);
}

void Blackjack::addDealerHand(Card card) 
{
    dealerDeck.push_back(card);
}

void Blackjack::clearHands() 
{
    userHand.clear();
    dealerDeck.clear();
}

int Blackjack::checkNaturalBlackjack(int choice) 
{
    vector<Card> deck;
    if (choice == 0) { deck = userHand; }
    else if (choice == 1) { deck = dealerDeck; }

    int ace;
    int acepath;
    int bigAce = 0;
    int smallAce = 0;
    int handValue = 0;
    int naturalBlackjack;
    for (int i = 0; i < deck.size(); i++) 
    {
        Card current = deck.at(i);
        if (current.getName() == "Ace") {
            acepath = 0;
            ace = 1; 
        }

        int hypo = handValue + 11;
        if (handValue <= 21 && hypo <= 21 && ace == 1 && acepath == 0) {
            handValue += 11; 
            acepath = 1;
            bigAce += 1;
        } 
        else if (handValue <= 21 && hypo >= 21 && ace == 1 && acepath == 0) {
            handValue += 1; 
            smallAce += 1;
            acepath = 1;
        }
        else { 
            handValue += current.getValue(); 
        }

        if (handValue == 21 && bigAce == 1) {
             naturalBlackjack = 1;
        }
        else { naturalBlackjack = 0; }
    }
    return naturalBlackjack;
}




