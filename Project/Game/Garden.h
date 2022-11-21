#pragma once
class Garden : public Card
{
public:
	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);

};