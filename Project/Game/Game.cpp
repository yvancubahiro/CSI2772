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

Black::getCardsPerCoin(int coins) {
    int cards = 0;
    if (coins == 1) {
        cards = 2;
    }
    else if (coins == 2) {
        cards = 4;
    }
    else if (coins == 3) {
        cards = 5;
    }
    else if (coins == 4) {
        cards = 6;
    }

    return cards;
}

Blue::getCardsPerCoin(int coins) {
    int cards = 0;
    if (coins == 1) {
        cards = 4;
    }
    else if (coins == 2) {
        cards = 6;
    }
    else if (coins == 3) {
        cards = 8;
    }
    else if (coins == 4) {
        cards = 10;
    }

    return cards;
}

Chili::getCardsPerCoin(int coins) {
    int cards = 0;
    if (coins == 1) {
        cards = 3;
    }
    else if (coins == 2) {
        cards = 6;
    }
    else if (coins == 3) {
        cards = 8;
    }
    else if (coins == 4) {
        cards = 9;
    }

    return cards;

}

Garden::getCardsPerCoin(int coins) {
    int cards = 0;
   
    if (coins == 2) {
        cards = 2;
    }
    else if (coins == 3) {
        cards = 3;
    }
   
    return cards;
}

Green::getCardsPerCoin(int coins) {
    int cards = 0;
    if (coins == 1) {
        cards = 3;
    }
    else if (coins == 2) {
        cards = 5;
    }
    else if (coins == 3) {
        cards = 6;
    }
    else if (coins == 4) {
        cards = 7;
    }

    return cards;
}

Red::getCardsPerCoin(int coins) {
    int cards = 0;
    if (coins == 1) {
        cards = 2;
    }
    else if (coins == 2) {
        cards = 3;
    }
    else if (coins == 3) {
        cards = 4;
    }
    else if (coins == 4) {
        cards = 5;
    }

    return cards;
}

Soy::getCardsPerCoin(int coins) {
    int cards = 0;
    if (coins == 1) {
        cards = 2;
    }
    else if (coins == 2) {
        cards = 4;
    }
    else if (coins == 3) {
        cards = 6;
    }
    else if (coins == 4) {
        cards = 7;
    }

    return cards;
}

Stink::getCardsPerCoin(int coins) {
    int cards = 0;
    if (coins == 1) {
        cards = 3;
    }
    else if (coins == 2) {
        cards = 5;
    }
    else if (coins == 3) {
        cards = 7;
    }
    else if (coins == 4) {
        cards = 8;
    }

    return cards;
}

Black::getName() {
    return "Black"

}

Blue::getName() {
    return "Blue"

}

Chili::getName(){
    return "Chilli"
}

Garden::getName() {
    return "Garden"

}

Green::getName() {
    return "Green"

}

Red::getName() {
    return "Red"

}

Soy::getName() {
    return "Soy"

}

Stink::getName() {
    return "Stink"

}



int main()
{
    cout << "Hello World!\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
