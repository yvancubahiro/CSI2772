#pragma once
#include <vector>

class CardFactory{
public :
	Deck cards;
	CardFactory();
	static CardFactory* getFactory();
	Deck getDeck();
};

CardFactory::CardFactory() {
	
	//creation de cartes
	for (int i = 0; i < 20; i++) {
		cards.push_back(new Blue());
	}
	for (int i = 0; i < 18; i++) {
		cards.push_back(new Chili());
	}
	for (int i = 0; i < 16; i++) {
		cards.push_back(new Stink());
	}
	for (int i = 0; i < 14; i++) {
		cards.push_back(new Green());
	}
	for (int i = 0; i < 12; i++) {
		cards.push_back(new Soy());
	}
	for (int i = 0; i < 10; i++) {
		cards.push_back(new Black());
	}
	for (int i = 0; i < 8; i++) {
		cards.push_back(new Red());
	}
	for (int i = 0; i < 6; i++) {
		cards.push_back(new Garden());
	}

	//melange de cartes
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g);
	
}

CardFactory* CardFactory::getFactory()
{
	static CardFactory singleton;
	return &singleton;
}


Deck CardFactory :: getDeck() {
	return cards;
}







