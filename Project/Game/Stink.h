#pragma once
class Stink : public Card {
public:

    int getCardsPerCoin(int coins);
    string getName();
    void print(ostream& out);

};

int Stink::getCardsPerCoin(int coins) {
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
};


string Stink::getName() {
    return "Stink";

};

void Stink::print(ostream& out) {}