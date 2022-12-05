#pragma once
#include "Chain.h"
#include "Hand.h"
#include "CardFactory.h"

using namespace std;

class Player {
public :
	string name;
	int numCoins;
	int numChains = 2;
	Chain_Base* chain1;
	Chain_Base* chain2;
	Chain_Base* chain3;
	Player(std::string&);
    string getName();
	int getNumCoins();
	Player& operator+=(int);
	int getMaxNumChains();
	int getNumChains();
	Chain_Base* operator[](int i);
	void buyThirdChain();
	Hand* hand;
	void printHand(std::ostream&, bool);
	friend ostream& operator << (ostream&, Player);
	Player(istream&, CardFactory*);
};

void Player::printHand(ostream& output, bool showAll) {
	if (!showAll) {
		hand->top()->print(output);
	}
	else {
		for (Card* card : *hand) {
			card->print(output);
		}
	}
}

ostream& operator << (ostream& output, Player player) {
	output << player.name << " " << player.getNumCoins() << " coins" << endl;
	output << player.chain1 << endl;
	output << player.chain2 << endl;
	output << player.chain3 << endl;

	return output;
};

Player :: Player(istream& input, CardFactory* cardFactory) {
	string name = "";
	char line[1026];
	char card;
	int index = 0;
	input.getline(line, 1026);
	card = line[index];

	while (line[index] != ' ') {
		this->name += line[index];
	}

	index = 0;
	input.getline(line, 1026);

	while (line[index] != ' ') {
		this->chain1->type += line[index];
	}
	index++;
	while (line[index] != NULL) {
		//this->chain1 += cardFactory->getCard(line[index]);
	}
	

};

Player :: Player(string& name) {
	this->name = name;
	hand = new Hand();
};

string Player :: getName() {
	return name;
};

int Player :: getNumCoins() {
	return numCoins;
};

Player& Player :: operator+=(int coins) {
	this->numCoins += coins;
	return *this;
};

int Player :: getMaxNumChains() {
	return numChains;
};

int Player :: getNumChains() {
	int emptyChains = 0;
	if (chain1->numOfCards == 0) {
		emptyChains++;
	}
	else if (chain2->numOfCards == 0) {
		emptyChains++;
	}
	else if (numChains == 3 && chain3->numOfCards == 0) {
		emptyChains++;
	}
	return emptyChains;
};

Chain_Base* Player :: operator[](int i) {
	Chain_Base* chain;

	if (i == 0) {
		chain = chain1;
	}
	else if (i == 1) {
		chain = chain2;
	}
	else if (i == 2) {
		chain = chain3;
	}
	else {
		cout << "Index invalid !";
		chain = nullptr;
	}
	return chain;
};

void Player :: buyThirdChain() {
	if (numChains == 2) {
		numChains++;
	}
	else if (numChains == 3) {
		cout << "already have 3 chains !";
	}
};



