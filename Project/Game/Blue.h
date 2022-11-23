#pragma once
class Blue : public Card
{
public:

	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out) ;

};


int Blue::getCardsPerCoin(int coins) {
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
};

string Blue::getName() {
    return "Blue";

}

void Blue::print(ostream& out){}