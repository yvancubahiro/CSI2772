#pragma once
class Soy : public Card {
public:

	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);
};