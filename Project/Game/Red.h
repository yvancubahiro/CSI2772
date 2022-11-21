#pragma once
class Red : Card {
public:
	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);
};