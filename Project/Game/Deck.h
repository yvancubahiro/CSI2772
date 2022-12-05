#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <istream>
#include "Card.h"
#include "CardFactory.h"
using namespace std;

class CardFactory;

class Deck : public vector<Card*> {
	
public :
	Card* draw();
	Deck(){};
	friend ostream & operator << (ostream&, const Deck*);
	Deck(istream&, CardFactory*);
};

Deck::Deck(istream& input, CardFactory* cardFactory) {
	/*
	string linestr;
	string name;
	char* line;
	char token;
	input.getline(linestr, 1026);
	line = linestr.c_str();

	token = strtok(line, " ");

	while (token != NULL) {
		this += cardFactory->getCard(token);
		token = strtok(line, " ");
	}*/
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
		output  << " ";
	}
	return output;
};



