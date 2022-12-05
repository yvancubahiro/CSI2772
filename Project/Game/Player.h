#pragma once
#include "Chain.h"
#include "Hand.h"
#include "CardFactory.h"
#include <iostream>
#include <vector>

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
	Player(istream&, const CardFactory*);
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

/*
Le ficchier contiendra :

	Dave 3 RB
	Red RRRR
	Blue B

*/

ostream& operator << (ostream& output, Player player) {
	output << player.name << " " << player.getNumCoins() << " " << player.chain1->type.at(0) << player.chain2->type.at(0) << player.chain3->type.at(0) << endl;
	output << player.chain1 << endl;
	output << player.chain2 << endl;
	output << player.chain3 << endl;

	return output;
};

Player :: Player(istream& input, const CardFactory* cardFactory) {
	char line[1026];
	int index = 0;
	input.getline(line, 1026);

	while (line[index] != ' ') {
		this->name += line[index++];
	}
	index++;


	switch (line[index++])
	{
	case 'B': this->chain1 = new Chain<Black>(input, cardFactory);
		break;
	case 'b':this->chain1 = new Chain<Blue>(input, cardFactory);
		break;
	case 'C':this->chain1 = new Chain<Chili>(input, cardFactory);
		break;
	case 'G':this->chain1 = new Chain<Garden>(input, cardFactory);
		break;
	case 'g':this->chain1 = new Chain<Green>(input, cardFactory);
		break;
	case 'R':this->chain1 = new Chain<Red>(input, cardFactory);
		break;
	case 'S':this->chain1 = new Chain<Soy>(input, cardFactory);
		break;
	case 's':this->chain1 = new Chain<Stink>(input, cardFactory);
		break;
	}

	switch (line[index++])
	{
	case 'B': this->chain2 = new Chain<Black>(input, cardFactory);
		break;
	case 'b':this->chain2 = new Chain<Blue>(input, cardFactory);
		break;
	case 'C':this->chain2 = new Chain<Chili>(input, cardFactory);
		break;
	case 'G':this->chain2 = new Chain<Garden>(input, cardFactory);
		break;
	case 'g':this->chain2 = new Chain<Green>(input, cardFactory);
		break;
	case 'R':this->chain2 = new Chain<Red>(input, cardFactory);
		break;
	case 'S':this->chain2 = new Chain<Soy>(input, cardFactory);
		break;
	case 's':this->chain2 = new Chain<Stink>(input, cardFactory);
		break;
	}

	switch (line[index++])
	{
	case 'B': this->chain3 = new Chain<Black>(input, cardFactory);
		break;
	case 'b':this->chain3 = new Chain<Blue>(input, cardFactory);
		break;
	case 'C':this->chain3 = new Chain<Chili>(input, cardFactory);
		break;
	case 'G':this->chain3 = new Chain<Garden>(input, cardFactory);
		break;
	case 'g':this->chain3 = new Chain<Green>(input, cardFactory);
		break;
	case 'R':this->chain3 = new Chain<Red>(input, cardFactory);
		break;
	case 'S':this->chain3 = new Chain<Soy>(input, cardFactory);
		break;
	case 's':this->chain3 = new Chain<Stink>(input, cardFactory);
		break;
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



