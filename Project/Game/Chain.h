#pragma once
#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"
using namespace std;

class Chain_Base : public vector<Card*>{
public :
	virtual int sell() = 0;
	int numOfCards = 0;
	string type;
};

template <class T> class Chain: public Chain_Base{
public :
	Chain<T>& operator+=(Card*);
	ostream& operator << (ostream&);
	int sell();
	Chain(istream&,const CardFactory*);
	Chain();

};

template <class T> Chain<T>& Chain<T>:: operator +=(Card* card) {
	T card2;
	if (card2.getName() != card->getName()) {
		cout << "cannot add because cards type does not match";
	}
	else {
		this->push_back(card);
		numOfCards++;
	}
	return *this;
};

template <class T> int Chain<T> :: sell() {
	T card;
	int response;
	if (this->size() >= card.getCardsPerCoin(4)) {
		response = 4;
	}
	else if (this->size() >= card.getCardsPerCoin(3)) {
		response = 3;
	}
	else if (this->size() >= card.getCardsPerCoin(2)) {
		response = 2;
	}
	else if (this->size() >= card.getCardsPerCoin(1)) {
		response = 1;
	}
	else {
		response = 0;
	}

	numOfCards = 0;
	return response;
}



template <class T> ostream& Chain<T> :: operator << (ostream& output) {
	output << this.type << " ";

	for (auto card : this) {
		card.print(output);
		output << " ";
	}
	return output;
};


template <class T> Chain<T> ::Chain() {
	T card;
	type = card.getName();
};


template <class T>  Chain<T> ::Chain(istream& input,const CardFactory* cardFactory) {
	char line[1026];
	input.getline(line, 1026);
	int index = 0;

	while (line[index] != ' ') {
		this->type += line[index++];
	}
	index++;

	while (line[index] != NULL) {
		this->push_back(cardFactory->getCard(line[index++]));
	}


};



