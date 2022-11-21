#pragma once
class Green : public Card {
public :
	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);
};