#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <istream>
#include <vector>
#include "Card.h"

using namespace std;

class CardFactory;

class Deck : public vector<Card*> {

public:
	Card* draw();
	Deck() {};
	friend ostream& operator << (ostream&, const Deck*);
	Deck(istream&, CardFactory*);
	void display();
};

Deck::Deck(istream& input, CardFactory* cardFactory) {
	char line[1026];
	int index = 0;
	input.getline(line, 1026);

	while (line[index] != NULL) {
		this->push_back(cardFactory->getCard(line[index++]));
	}
};



	

Card* Deck::draw() {
	Card* topCard;

	if (this->empty()) {
		cout << "Cannot draw from deck, because deck is empty";
		return nullptr;
	}
	else {
		topCard = this->back();
		this->pop_back();
		return topCard;
	}
};

ostream& operator << (ostream& output,const  Deck *deck) {
	for (Card* card : *deck) {
		card->print(output);
	}
	return output;
};

void Deck::display() {
	for (Card* card : *this) {
		cout << card->getName() << " ";
	}
	cout << endl;
}



