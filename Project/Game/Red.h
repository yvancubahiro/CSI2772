#pragma once
#include "Card.h"
class Red : public Card {
public:
	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);
};

int Red::getCardsPerCoin(int coins) {
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
};

string Red::getName() {
    return "Red";

};

void Red::print(ostream& output) { output << 'R'; }

