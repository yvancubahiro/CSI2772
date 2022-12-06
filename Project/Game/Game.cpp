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
#include "CardFactory.h"


Table *table;
char answer;
CardFactory* cardFactory;
ifstream inputData("data.txt");
ofstream outputData("data.txt");

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

Card* topCard;

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



    }

}

