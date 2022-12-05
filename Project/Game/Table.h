#pragma once
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"

class Table {
private :
	Player * player1 , * player2;
	Deck* deck;
	DiscardPile* discardPile;
	TradeArea* tradeArea;
	CardFactory* cardFactory;
	
public :
	bool win(std::string&);
	void printHand(bool);
	Table(string, string);
};

bool Table::win(string & name) {
	if (deck->empty()) {
		if (player1->getNumCoins() > player2->getNumCoins()) {
			name = player1->getName();
		}
		else {
			name = player2->getName();
		}
		return 1;
	}
	else {
		return 0;
	}
}

void Table::printHand(bool showHand) {
	if (!showHand) { // show only first card
		cout << player1->getName() << "'s first card is " << player1->hand->top() << endl;
		cout << player2->getName() << "'s first card is " << player2->hand->top() << endl;
	}
	else { // show all hand
		cout << player1->getName() << "'s first card is " << player1->hand->printCards() << endl;
		cout << player2->getName() << "'s first card is " << player2->hand->printCards() << endl;
	}
}

Table::Table(string name1, string name2) {
	player1 = new Player(name1);
	player2 = new Player(name2);
	cardFactory = new CardFactory();
	deck = new Deck(cardFactory->getDeck());
	discardPile = new DiscardPile();
}