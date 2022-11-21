#pragma once
class Garden : Card
{
public:
	int getCardsPerCoin(int coins);
	string getName();
	void print(ostream& out);

};