#include <iostream>
#include <string>
#include <vector>
#include "Blackjack.h"
using namespace std;

int main() {
    
    Blackjack game;
    Deck d1;
    int bet;                  // Keeps track oof bet to be added/taken to/from balance 
    int balance;              // Keeps track of balance throughout the program
    int startbalance;         // Holds inital balance in order to compute win/loss values later
    int validBalance = 0;     // Loop varaible
    char keepPlaying = 'y';   // Loop variable

    d1.newDeck();

    game.displayIntro();               
    //------------------------------------------------------------------------------------------------------------------
    // Loop for continuing until the user enters a proper value for the balance
    //------------------------------------------------------------------------------------------------------------------
    while (validBalance == 0) {      
        if (cin.fail()) {            // 
            cin.clear();             // Error checking
            cin.ignore(20,'\n');     //
        }
        cout << "How many chips would you like? (max $100,000 -- No comma neccessary): " << endl;
        cin >> balance;
        startbalance = balance;
        if (balance <= 100000 && balance > 0) { validBalance = 1; }                // Error Checking
        else { cout << "You entered an invalid balance, try again." << endl; }     //
    }
    cout << endl;
    //------------------------------------------------------------------------------------------------------------------
    // Loop for staying in the game until the player decides to quit
    //------------------------------------------------------------------------------------------------------------------
    while (keepPlaying == 'y' || keepPlaying == 'Y') {
        //--------------------------------------------------------------------------------------------------------------
        // Loop that continues until user enters a valid bet value
        //--------------------------------------------------------------------------------------------------------------
        int validBet = 0;
        cout << "Your balance: $" << balance << endl;
        while (validBet == 0) {
            if (cin.fail()) {          //
                cin.clear();           // Error checking
                cin.ignore(20,'\n');   //
            }
            cout << "How much would you like to bet? (Enter a number value, no comma): " << endl;
            cin >> bet;
            if (bet <= balance && bet > 0) { validBet = 1; }
            else { cout << "You entered an invalid bet, please try again." << endl; }
        }
        //--------------------------------------------------------------------------------------------------------------
        cout << endl;

        game.addUserHand(d1.dealCard());
        game.addUserHand(d1.dealCard());
        game.addDealerHand(d1.dealCard());
        game.addDealerHand(d1.dealCard());


        game.displayPlayerHand(game);

        cout << "*****************************" << endl;
        cout << "         Dealer hand         " << endl;
        cout << "*****************************" << endl;

        game.printHand(2);
        cout << endl;
        //--------------------------------------------------------------------------------------------------------------
        // Checking if the user had a natural blackjack but if dealer has natural blackjack the players 
        // will be ignored and the dealer will win
        //--------------------------------------------------------------------------------------------------------------
        if (game.checkNaturalBlackjack(0) == 1 && game.checkNaturalBlackjack(1) != 1) {
            cout << "You have a Natural Blackjack! You will recieve 1.5 times your bet in winnings." << endl << endl;
            balance += (int)(1.5 * bet);                        // Updates balance with 1.5 times winnings
            cout << "Current balance: $" << balance << endl;
            //----------------------------------------------------------------------------------------------------------
            // All loops of this sort are to iterate until the player decides to continue or quit. Has built in error
            // checking. If balance is equal to zero it will automatically end the game.
            //----------------------------------------------------------------------------------------------------------
            if (balance <= 0) {
                cout << "Unfortunately you have run out of money and can no longer play." << endl;
                keepPlaying = 'n';
            }
            else {
                int validRepeat = 0;
                while (validRepeat == 0) {
                    cout << "Would you like to keep playing? (y/n)" << endl;
                    cin >> keepPlaying;
                    if (keepPlaying != 'y' && keepPlaying != 'n') { 
                        cout << "You entered and invalid choice, please try again." << endl;
                    }
                    else { validRepeat = 1; }
                }
            }
            //----------------------------------------------------------------------------------------------------------
            cout << endl;                    // (Formatting)
            game.clearHands();               // All calls of this sort are to clear the decks for a new deal
        }
        else if (game.checkNaturalBlackjack(1) == 1 && game.checkNaturalBlackjack(0) != 1) {
            cout << "The dealer has a Natural Blackjack. You lose your bettings." << endl << endl;
            game.displayDealerBlackjack(game);
            balance -= bet;

            cout << "Current balance: $" << balance << endl;
            if (balance <= 0) {
                cout << "Unfortunately you have run out of money and can no longer play." << endl;
                keepPlaying = 'n';
            }
            else {
                int validRepeat = 0;
                while (validRepeat == 0) {
                    cout << "Would you like to keep playing? (y/n)" << endl;
                    cin >> keepPlaying;
                    if (keepPlaying != 'y' && keepPlaying != 'n') { 
                        cout << "You entered and invalid choice, please try again." << endl;
                    }
                    else { validRepeat = 1; }
                }
            }
            cout << endl;
            game.clearHands();
        }
        else if (game.checkNaturalBlackjack(0) == 1 && game.checkNaturalBlackjack(1) == 1) {
            cout << "Both you and the dealer have a Natural Blackjack resulting in a push. No one wins." << endl << endl;
            game.displayDealerBlackjack(game);

            cout << "Current balance: $" << balance << endl;
            if (balance <= 0) {
                cout << "Unfortunately you have run out of money and can no longer play." << endl;
                keepPlaying = 'n';
            }
            else {
                int validRepeat = 0;
                while (validRepeat == 0) {
                    cout << "Would you like to keep playing? (y/n)" << endl;
                    cin >> keepPlaying;
                    if (keepPlaying != 'y' && keepPlaying != 'n') { 
                        cout << "You entered and invalid choice, please try again." << endl;
                    }
                    else { validRepeat = 1; }
                }
            }
            cout << endl;
            game.clearHands();
        }
        //--------------------------------------------------------------------------------------------------------------
        else {
            char hitORstand = 'h';   // Loop varaibles
            int bust = 0;            //
            //----------------------------------------------------------------------------------------------------------
            // Loop that continues to as the player if they would like to hit or stand until the player busts or stands
            //----------------------------------------------------------------------------------------------------------
            while (hitORstand == 'h' && bust == 0) {
                //------------------------------------------------------------------------------------------------------
                // Loop that continues until the user enters a valid option
                //------------------------------------------------------------------------------------------------------
                int twentyone = 0;
                if (game.updateHandValue(0) == 21) { twentyone = 1;}
                if (twentyone == 1) {
                    hitORstand = 's';
                }
                else {
                    int validChoice = 0;
                    while (validChoice == 0) {
                        cout << "Would you like to hit (h) or stand (s)?" << endl;
                        cin >> hitORstand;
                        if (hitORstand == 's' || hitORstand == 'h') { validChoice = 1; }
                        else { cout << "You entered and invalid choice, please try again." << endl; }
                    }
                }
                //------------------------------------------------------------------------------------------------------
                // Statement that performs 'hit' action dealing another card to the players hand             
                //------------------------------------------------------------------------------------------------------
                if (hitORstand == 'h') {
                    game.addUserHand(d1.dealCard());
                    game.displayPlayerHand(game);

                    cout << "*****************************" << endl;
                    cout << "         Dealer hand         " << endl;
                    cout << "*****************************" << endl;

                    game.printHand(2);
                    cout << endl;
                }
                //------------------------------------------------------------------------------------------------------
                // Statement that calculates if the player busts from taking the extra card and handles the outcome
                //------------------------------------------------------------------------------------------------------
                if (game.updateHandValue(0) > 21) {
                    bust = 1;
                    game.displayBustOutro(game);
                    balance -= bet;
                    cout << "Current balance: $" << balance << endl;

                    if (balance <= 0) {
                            cout << "Unfortunately you have run out of money and can no longer play." << endl;
                            keepPlaying = 'n';
                        }
                        else {
                            int validRepeat = 0;
                            while (validRepeat == 0) {
                                cout << "Would you like to keep playing? (y/n)" << endl;
                                cin >> keepPlaying;
                                if (keepPlaying != 'y' && keepPlaying != 'n') { 
                                    cout << "You entered and invalid choice, please try again." << endl;
                                }
                                else { validRepeat = 1; }
                            }
                        }
                    game.clearHands();
                    cout << endl;
                }
                //------------------------------------------------------------------------------------------------------
            }
            //----------------------------------------------------------------------------------------------------------
            // Once the player stands and hasnt busted yet, this sequence will be entered to determine dealers hand
            //----------------------------------------------------------------------------------------------------------
            if (hitORstand == 's' && bust == 0) {
                game.displayPlayerHand(game);

                cout << "*****************************" << endl;
                cout << "         Dealer hand         " << endl;
                cout << "*****************************" << endl;

                //------------------------------------------------------------------------------------------------------
                // Loop to add card to the dealers hand until it is caused to stand or bust
                //------------------------------------------------------------------------------------------------------
                while (game.updateHandValue(1) < 17) { game.addDealerHand(d1.dealCard()); }
                //------------------------------------------------------------------------------------------------------
                // Following statements handle the different cases for the outcomes of the dealers hand
                // 1. Player hand > Dealers hand --- Win
                // 2. Player hand < Dealers hand --- Loss
                // 3. Player hand = Dealers hand --- Push
                // 4. Dealer had  > 21           --- Bust (Player Wins)
                // and handles the determined case correctly and applys a loop to get a valid input from the user 
                // to either continue or quit the game
                //------------------------------------------------------------------------------------------------------
                if (game.updateHandValue(1) <= 21) {
                    game.printHand(1);
                    cout << "Dealer's hand total: " << game.updateHandValue(1) << endl << endl;

                    if (game.updateHandValue(0) > game.updateHandValue(1)) {
                        cout << "Congratulations, You Win!" << endl << endl;
                        balance += bet;
                        cout << "Current balance: $" << balance << endl;

                        if (balance <= 0) {
                            cout << "Unfortunately you have run out of money and can no longer play." << endl;
                            keepPlaying = 'n';
                        }
                        else {
                            int validRepeat = 0;
                            while (validRepeat == 0) {
                                cout << "Would you like to keep playing? (y/n)" << endl;
                                cin >> keepPlaying;
                                if (keepPlaying != 'y' && keepPlaying != 'n') { 
                                    cout << "You entered and invalid choice, please try again." << endl;
                                }
                                else { validRepeat = 1; }
                            }
                        }
                        game.clearHands();
                    }
                    else if (game.updateHandValue(0) < game.updateHandValue(1)) {
                        cout << "The dealer wins. Better luck next time!" << endl << endl;
                        balance -= bet;
                        cout << "Current balance: $" << balance << endl;

                        if (balance <= 0) {
                            cout << "Unfortunately you have run out of money and can no longer play." << endl;
                            keepPlaying = 'n';
                        }
                        else {
                            int validRepeat = 0;
                            while (validRepeat == 0) {
                                cout << "Would you like to keep playing? (y/n)" << endl;
                                cin >> keepPlaying;
                                if (keepPlaying != 'y' && keepPlaying != 'n') { 
                                    cout << "You entered and invalid choice, please try again." << endl;
                                }
                                else { validRepeat = 1; }
                            }
                        }
                        game.clearHands();
                    }
                    else if (game.updateHandValue(0) == game.updateHandValue(1)) {
                        cout << "Push. You and the dealer have the same value total. No one wins!" << endl << endl;
                        cout << "Current balance: $" << balance << endl;

                        if (balance <= 0) {
                            cout << "Unfortunately you have run out of money and can no longer play." << endl;
                            keepPlaying = 'n';
                        }
                        else {
                            int validRepeat = 0;
                            while (validRepeat == 0) {
                                cout << "Would you like to keep playing? (y/n)" << endl;
                                cin >> keepPlaying;
                                if (keepPlaying != 'y' && keepPlaying != 'n') { 
                                    cout << "You entered and invalid choice, please try again." << endl;
                                }
                                else { validRepeat = 1; }
                            }
                        }
                        game.clearHands();
                    }
                    cout << endl;
                }
                else if (game.updateHandValue(1) > 21) {
                    game.printHand(1);
                    cout << "Dealer's hand total: " << game.updateHandValue(1) << endl << endl;
                    cout << "The dealer has busted! You win." << endl << endl;
                    balance += bet;
                    cout << "Current balance: $" << balance << endl;

                    if (balance <= 0) {
                        cout << "Unfortunately you have run out of money and can no longer play." << endl;
                        keepPlaying = 'n';
                    }
                    else {
                        int validRepeat = 0;
                        while (validRepeat == 0) {
                            cout << "Would you like to keep playing? (y/n)" << endl;
                            cin >> keepPlaying;
                            if (keepPlaying != 'y' && keepPlaying != 'n') { 
                                cout << "You entered and invalid choice, please try again." << endl;
                            }
                            else { validRepeat = 1; }
                        }
                    }
                    game.clearHands();
                    cout << endl;
                }
            }
        //--------------------------------------------------------------------------------------------------------------
        // Statement to check if the deck has less than 20 cards remaining and if so will reshuffle (make a new deck)
        //--------------------------------------------------------------------------------------------------------------
        if (d1.deckSize() < 20) {
            cout << "****************************" << endl;
            cout << "The deck has been reshuffled" << endl;
            cout << "****************************" << endl;
            d1.newDeck();
        }
        //--------------------------------------------------------------------------------------------------------------
        }
    }
    //------------------------------------------------------------------------------------------------------------------
    // Calculates profit/loss and presents it to the player once the game is over
    //------------------------------------------------------------------------------------------------------------------
    int difference = balance - startbalance;
    game.displayOutro(difference);
    return 0;
    //------------------------------------------------------------------------------------------------------------------
}