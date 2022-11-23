#pragma once
class Chili : public Card
{
public:


	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);

};



int Chili::getCardsPerCoin(int coins) {
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

string Chili::getName() {
    return "Chilli";
}

void Chili::print(ostream& out) {}