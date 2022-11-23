#pragma once
#include <vector>

class Chain_Base{
public :
	virtual int sell() = 0;

};

template <class T> class Chain: public Chain_Base, public vector<Card*>{
public :
	Chain<T>& operator+=(Card*);
	int sell();
};

template <class T> Chain<T>& Chain<T>:: operator +=(Card* card) {
	T card2;
	if (card2.getName() != card->getName()) {
		cout << "cannot add because cards type does not match";
	}
	else {
		this->push_back(card);
	}
	return *this;
};

template <class T> int Chain<T> :: sell() {
	T card;

	if (this->size() >= card.getCardsPerCoin(4)) {
		return 4;
	}
	else if (this->size() >= card.getCardsPerCoin(3)) {
		return 3;
	}
	else if (this->size() >= card.getCardsPerCoin(2)) {
		return 2;
	}
	else if (this->size() >= card.getCardsPerCoin(1)) {
		return 1;
	}
	else {
		return 0;
	}
}