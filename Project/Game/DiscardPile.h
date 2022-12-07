#pragma once
#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactoryAndDeck.h"
using namespace std;

class DiscardPile {
public:
	DiscardPile(){};
	DiscardPile(istream&, const CardFactory*);
	vector <Card*> cards;
	DiscardPile& operator+=(Card*);
	Card* pickUp();
	Card* top();
	void print(std::ostream&);
	friend ostream& operator << (ostream&, DiscardPile&);
	void display();
};


DiscardPile& DiscardPile :: operator+=(Card* card) {
	cards.push_back(card);
	return *this;
};

/*
* Returns card at the top of the discard pile
*/
Card* DiscardPile::pickUp() {
	Card* card;
	if (cards.empty()) {
		card = nullptr;
	}
	else {
		card = cards.back();
		cards.pop_back();
	}

	return card;
}

Card* DiscardPile::top() {
	if (cards.empty()) {
		return nullptr;
	}
	else {
		return cards.back();
	}
};

ostream& operator << (ostream& output, DiscardPile& discardPile) {
	if (!discardPile.cards.empty()) {
		for (Card* card : discardPile.cards) {
			card->print(output);
		}
		output << '\n';
	}
	else {
		output << '\n';
	}
	return output;
};

DiscardPile :: DiscardPile(istream& input,  const CardFactory* cardFactory) {
	char line[1026];
	char card;
	int index = 0;
	input.getline(line, 1026);
	card = line[index];
	
	while (card != NULL) {
		this->cards.push_back(cardFactory->getCard(card));
		card = line[++index];
	}
};


void DiscardPile::print(std::ostream& output) {
	for (Card* card : cards) {
		card->print(output);
	}
};

void DiscardPile ::display() {
	for (Card* card : cards) {
		cout << card->getName() << " ";
	}
	cout << endl;
}


