#pragma once
#include "Card.h"
class Black : public Card {
	
public :
	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);
};

int Black::getCardsPerCoin(int coins) {
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
};


string Black::getName() {
    return "Black";

};

void Black::print(ostream& output) { output << 'B'; }

