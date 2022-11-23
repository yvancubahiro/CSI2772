#pragma once
#include <list>

class TradeArea {
public:
	list<Card*> cards;
	TradeArea& operator+=(Card*);
	bool legal(Card*);
	Card* trade(string);
	int numCards();
};

TradeArea& TradeArea :: operator+=(Card* card) {
	cards.push_back(card);
	return *this;
};

bool TradeArea::legal(Card* card) {
	if (cards.size() == 0) {
		return true;
	}

	for (Card* card2 : cards) {
		if (card2->getName() == card->getName()) {
			return true;
		}
	}

	return false;

};

Card* TradeArea::trade(string cardName) {
	Card* response = nullptr;

	if (cards.empty()) {
		cout << "trade area is empty !";
	}
	for (Card* card : cards) {
		if (card->getName() == cardName) {
			cards.remove(card);
			response = card;
		}
	}
	return response;
};

int TradeArea::numCards() {
	return cards.size();
};