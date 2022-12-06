#pragma once
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"
#include <iostream>
using namespace std;

class Table {
public :
	Player * player1 , * player2;
	Deck* deck;
	DiscardPile* discardPile;
	TradeArea* tradeArea;
	CardFactory* cardFactory;
	bool win(std::string&);
	void printHand(bool);
	Table(string, string);
	Table(istream&, const CardFactory*);
	friend ostream& operator << (ostream&, Table);
	void display();
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

Table :: Table(istream& input, const CardFactory* cardFactory) {
	this->player1 = new Player(input, cardFactory);
	this->player2 = new Player(input, cardFactory);
	this->discardPile = new DiscardPile(input, cardFactory);
	this->tradeArea = new TradeArea(input, cardFactory);
};

ostream& operator << (ostream& output, Table table) {
	output << table.player1 << endl;
	output << table.player2 << endl;
	output << table.discardPile << endl;
	output << table.tradeArea << endl;
	return output;
};

void Table::display() {

	cout << "-------------- PLAYERS -------------" << endl;
	player1->display();
	player2->display();
	cout << "--------------- DECK ---------------" << endl;
	deck->display();
	cout << "------------ TRADE AREA ------------" << endl;
	tradeArea->display();
	cout << "----------- DISCARD PILE -----------" << endl;
	discardPile->display();
	cout << "------------------------------------" << endl << endl;

}