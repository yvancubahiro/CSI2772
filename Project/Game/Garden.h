#pragma once
#include "Card.h"
class Garden : public Card
{
public:
	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);

};

int Garden::getCardsPerCoin(int coins) {
    int cards = 0;

    if (coins == 2) {
        cards = 2;
    }
    else if (coins == 3) {
        cards = 3;
    }

    return cards;
};

string Garden::getName() {
    return "Garden";

}

void Garden::print(ostream& output) { output << 'G'; }