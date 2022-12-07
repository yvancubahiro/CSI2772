#pragma once
#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactoryAndDeck.h"
using namespace std;

class Chain_Base : public vector<Card*>{
public :
	virtual int sell() = 0;
	int numOfCards = 0;
	string type = "Empty";
	void display();
	Chain_Base& operator+=(Card*);
};

template <class T> class Chain: public Chain_Base{
public :
	Chain<T>& operator+=(Card*);
	friend ostream& operator << (ostream&,Chain&);
	int sell();
	Chain(istream&,const CardFactory*);
	Chain();
};

class IllegalType : public exception {
	virtual const char* what() const throw() {
		return " Card does not match chain type";
	}
};

template <class T> Chain<T>& Chain<T>:: operator +=(Card* card) {
	T card2;
	if (card2.getName() != card->getName()) {
		throw IllegalType();
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

	this->clear();
	numOfCards = 0;
	return response;
}



template <class T>ostream&  operator << (ostream& output, Chain<T>& chain) {
	output << chain.type << " ";

	for (auto card : chain) {
		card.print(output);
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
	int no = line[++index];

	for (int i = 0; i < no; i++) {
		this->push_back(cardFactory->getCard(this->type.at(0)));
	}
};

void Chain_Base :: display() {
	cout << numOfCards << " " << type << endl;
}





