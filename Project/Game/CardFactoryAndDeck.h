#pragma once
#include <vector>
#include "Deck.h"
#include "Black.h"
#include "Blue.h"
#include "Chili.h"
#include "Garden.h"
#include "Green.h"
#include "Red.h"
#include "Soy.h"
#include "Stink.h"
#include <random>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <istream>
#include <vector>
#include "Card.h"

// The 2 classes are in the same folder (CardFactoryAndDeck) to resolve the circular dependency problem


// DECK DEFINITION ------------------------------------------------------------------------

#pragma once
class CardFactory;

class Deck : public vector<Card*> {

public:
	Card* draw();
	Deck() {};
	friend ostream& operator << (ostream&, const Deck&);
	Deck(istream&, CardFactory*);
	void display();
	Card* pick();
};

Card* Deck :: pick() {
	if (this != nullptr) {
		Card* card;
		if (!this->empty()) {
			card = this->back();
			this->pop_back();
		}
		else {
			cout << "Deck is empty !";
			card = nullptr;
		}
		return card;
	}
	else {
		return nullptr;
	}
}

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

ostream& operator << (ostream& output, const  Deck& deck) {
	for (Card* card : deck) {
		card->print(output);
	}
	output << '\n';
	return output;
};

void Deck::display() {
	for (Card* card : *this) {
		cout << card->getName() << " ";
	}
	cout << endl;
}


// CARD FACTORY  DEFINITION ---------------------------------------------------------------------------------


class CardFactory{
public :
	Deck *cards;
	CardFactory();
	static CardFactory* getFactory();
	Deck getDeck();
	Card* getCard(char) const;
};

CardFactory::CardFactory() {
	
	cards = new Deck();
	
	//creation de cartes
	for (int i = 0; i < 20; i++) {
		cards->push_back(new Blue());
	}
	for (int i = 0; i < 18; i++) {
		cards->push_back(new Chili());
	}
	for (int i = 0; i < 16; i++) {
		cards->push_back(new Stink());
	}
	for (int i = 0; i < 14; i++) {
		cards->push_back(new Green());
	}
	for (int i = 0; i < 12; i++) {
		cards->push_back(new Soy());
	}
	for (int i = 0; i < 10; i++) {
		cards->push_back(new Black());
	}
	for (int i = 0; i < 8; i++) {
		cards->push_back(new Red());
	}
	for (int i = 0; i < 6; i++) {
		cards->push_back(new Garden());
	}

	//melange de cartes
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cards->begin(), cards->end(), g);
	
}

CardFactory* CardFactory::getFactory()
{
	static CardFactory singleton;
	return &singleton;
}


Deck CardFactory :: getDeck() {
	return *cards;
}

 Card* CardFactory::getCard(char c) const{
	for (Card* card : *cards) {
		if (card->getName().at(0) == c) {
			return card;
		}
	}
	return nullptr;
}

 // DECK CONSTRUCTOR --------------------------------------------------------------------------------

 Deck::Deck(istream& input, CardFactory* cardFactory) {
	 char line[1026];
	 int index = 0;
	 input.getline(line, 1026);

	 while (line[index] != NULL) {
		 this->push_back(cardFactory->getCard(line[index++]));
	 }
 };











