#pragma once
using namespace std;
#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

class Deck : public vector<Card*> {
	
public :
	// NEED CONSTRUCTORS
	Card* draw();
	ostream& operator << (Deck);
};
	



Card* Deck::draw() {
	Card* backCard;

	if (this->empty()) {
		cout << "Cannot draw from deck, because deck is empty";
		return nullptr;
	}
	else {
		backCard = this->back();
		this->pop_back();
		return backCard;
	}
}

