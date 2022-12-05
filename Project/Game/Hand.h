#pragma once
#include "Card.h"

class Hand: public vector<Card*>{
public :
	Hand& operator+=(Card*);
	Card* play();
	Card* top();
	Card* operator[](int);
	string printCards();
	friend ostream& operator << (ostream&, Hand);
	Hand(istream&, CardFactory*);
	Hand() {};
};

Hand& Hand :: operator+=(Card* card) {
	this->push_back(card);
	return *this;
};

Card* Hand :: play() {
	if (this->empty()) {
		cout << "Hand is empty";
		return nullptr;
	}
	else {
		Card* firstCard = this->front();
		this->erase(this->begin());
		return firstCard;
	}
};

Card* Hand :: top() {
	if (this->empty()) {
		cout << "Hand is empty";
		return nullptr;
	}
	else {
		return this->front();
	}
};

Card* Hand :: operator[](int index) {
	if (this->size() == 0) {
		cout << "Hand is empty";
		return nullptr;
	}
	Card* card = this->at(index);
	this->erase(begin() + index);
	return card;
};

string Hand::printCards() {
	string result = " ";
	for (Card* card : *this) {
		result += card->getName();
	}
	return result;
};

ostream& operator << (ostream& output, Hand hand) {
	for (Card* card : hand) {
		card->print(output);
	}
	return output;
};

Hand :: Hand(istream& input, CardFactory* cardFactory) {
	char line[1026];
	char card;
	int index = 0;
	input.getline(line, 1026);
	card = line[index];

	while (card != NULL) {
		this->push_back(cardFactory->getCard(card));
		card = line[++index];
	}
};

