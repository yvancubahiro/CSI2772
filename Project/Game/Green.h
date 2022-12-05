#pragma once
#include "Card.h"
class Green : public Card {
public :
	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);
};

int Green::getCardsPerCoin(int coins) {
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

string Green::getName() {
    return "green";

};

void Green::print(ostream& output) { output << 'g'; }