#pragma once


class Card {
	
public :
	const int oneCoinWorth;
	const int twoCoinWorth;
	const int threeCoinWorth;
	const int fourCoinWorth;
	
	Card(int one, int two, int three, int four): 
		oneCoinWorth(one),
		twoCoinWorth(two),
		threeCoinWorth(three),
		fourCoinWorth(four)
	{

	}

	virtual int getCardsPerCoin(int coins) = 0;
	virtual string getName() = 0;
	virtual void print(ostream& out) = 0;

};