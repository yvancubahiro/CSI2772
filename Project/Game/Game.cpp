// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


#include <iostream>
#include "Card.h"
#include "Chain.h"
#include "Coins.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "Player.h"
#include "Table.h"
#include "TradeArea.h"
#include "Black.h"
#include "Blue.h"
#include "Chili.h"
#include "Garden.h"
#include "Green.h"
#include "Red.h"
#include "Soy.h"
#include "Stink.h"
#include "CardFactoryAndDeck.h"


Table *table;
char answer;
CardFactory* cardFactory;
ifstream inputData("data.txt");
ofstream outputData("data.txt");
int player = 0;
Card* topCard;
Card* pickedCard;
vector<Card*> pickedCards;
 

void newGame();
void saveGame();
void resumeGame();
void  runGame();

int main()
{
    cardFactory = new CardFactory();

    // ask user if wants to resume a game or start a new one

    cout << "Start a new game (n) or resume a paused game (r) : ";
    cin >> answer;
    while (answer != 'n' && answer != 'r') {
        cout << "Invalid answer, please try again : new game (n), resume game (r) : ";
        cin >> answer;
    }

    if (answer == 'r') {
        cout << "Resuming paused game ...." << endl;
        resumeGame();
    }
    else {
        cout << "Starting a new game..." << endl;
        newGame();
    }


};

void newGame() {

    string name1, name2;
    cout << "Enter Player 1 name : ";
    cin >> name1;
    cout << "Enter Player 2 name : ";
    cin >> name2;
    table = new Table(name1, name2);
    
    runGame();

}

void resumeGame() {
    
    if (inputData.is_open()) {
        table = new Table(inputData, cardFactory);
    }
    else {
        cout << "Unable to resume game...starting a new one :" << endl;
        newGame();
    }

    runGame();
}

void saveGame() {
    if (outputData.is_open()) {
        outputData << table;
    }
}



void runGame() { // IMPLEMENTATION DU PSEUDO CODE
    

    while (!table->deck->empty()) { // While there are still cards on the Deck

        cout << "Pause game (p) or continue (c) : ";
        cin >> answer;
        while (answer != 'p' && answer != 'c') {
            cout << "Invalid answer please try again : pause (p), continue (c) :";
            cin >> answer;
        }

        if (answer == 'p') { // save game to file and exit
            saveGame();
            exit(0);
        }

        table->display(); // Display Table

        topCard = table->deck->draw(); // DRAWS TOP CARD
        cout << "The picked card is " << topCard->getName() << endl;;

        if (!table->tradeArea->cards.empty()) { // If tradeArea is not empty

            cout << "Add cards to chains (c) or discard them (d) : ";
            cin >> answer;

            while (answer != 'c' && answer != 'd') {
                cout << "Invalid answer, try again : add to chains (c), discard cards (d) : ";
            }

            if (answer == 'c') { // Place trade area cards into chains
                cout << "Placing tradearea cards in " << table->players[player]->getName() << "'s chains ..." << endl;
                for (Card* card : table->tradeArea->cards) {
                    if (!table->players[player]->addCard(card)) { // if a card does not match to any chain....place it into discard pile
                        table->discardPile->cards.push_back(card); 
                    }
                    
                }
                cout << "------------------------------------------------------" << endl;
                table->players[player]->display();
                cout << "------------------------------------------------------" << endl;
            }
            else { // place trade area cards into discard pile
                cout << "Placing trade area cards into discard cards" << endl;
                for (Card* card : table->tradeArea->cards) {
                    table->discardPile->cards.push_back(card);
                }
            }

            cout << table->players[player] << " plays topmost card from hand";
            table->players[player]->play(); // Play the now topmost card from Hand. 

            cout << "Show " << table->players[player] << " full hand ? yes (y) or no (n) : ";
            cin >> answer;

            while (answer != 'y' && answer != 'n') {
                cout << "Invalid answer, please try again : yes (y) or no (n) ";
                cin >> answer;
            }

            if (answer == 'y') { //player decides to
                cout << table->players[player]->name << " ";
                table->players[player]->hand->display(); //Show the player's full hand 
                pickedCard = table->players[player]->hand->pickACard(cardFactory); //player selects an arbitrary card
                table->discardPile->cards.push_back(pickedCard); // place it on the discard pile.
            }

            cout << "Drawing 3 cards from the deck ..." << endl;
            for (int i = 0; i < 3; i++) { //Draw three cards from the deck and place cards in the trade area
                table->tradeArea->cards.push_back( table->deck->pick());
            }

            while (table->tradeArea->contains(table->discardPile->top())) { //while top card of discard pile matches an existing card in the trade area
                pickedCard = table->discardPile->pickUp();
                table->tradeArea->cards.push_back( pickedCard);
            }

            
            table->tradeArea->display();
            for (Card* card: table->tradeArea->cards) {
                cout << "Do you want to remove " << card->getName() << ". y for yes or any char for no.";
                cin >> answer;
                if (answer == 'y') {
                    if (table->players[player]->addCard(card)) {
                        pickedCards.push_back(card);
                    }
                    else {
                        cout << "Cannot add " << card->getName() << " to " << table->players[player]->name << " chains " << endl;
                    }
                }
            }

            for (Card* card : pickedCards) {
                table->tradeArea->remove(card);
            }

            cout << "Drawing 2 cards from the deck to " << table->players[player]->name << " cards" << endl;
            table->players[player]->addCard(table->deck->pick());
            table->players[player]->addCard(table->deck->pick());
        }




    }

}

