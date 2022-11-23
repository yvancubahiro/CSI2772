#pragma once
class Soy : public Card {
public:

	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);
};

int Soy::getCardsPerCoin(int coins) {
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
};


string Soy::getName() {
    return "Soy";

};

void Soy::print(ostream& out) {}