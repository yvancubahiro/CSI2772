#pragma once
class Red : public Card {
public:
	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);
};