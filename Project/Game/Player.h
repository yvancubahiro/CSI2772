#pragma once
#include "Chain.h"
#include "Hand.h"
#include "CardFactoryAndDeck.h"
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
	void display();
	bool addCard(Card* card);
	void play();
	Chain_Base* createChain( char);
	int getNumOfCards();
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
	output << player.name <<  " " << player.numCoins << " " << player.numChains << '\n';
	if (player.chain1 != nullptr) {
		output << player.chain1->type << '\n' << player.chain1->type << " " << player.chain1->size() << '\n';
	}
	else {
		output << "E" << '\n';
	}
	if (player.chain2 != nullptr) {
		output << player.chain2->type << '\n' << player.chain2->type << " " << player.chain2->size() << '\n';
	}
	else {
		output << "E" << '\n';
	}
	if (player.chain3 != nullptr) {
		output << player.chain3->type << '\n' << player.chain3->type << " " << player.chain3->size() << '\n';
	}
	else {
		output << "E" << '\n';
	}

	if (player.hand != nullptr) {
		output << *player.hand << '\n';
	}
	else {
		output << 'E' << '\n';
	}
	

	return output;
};

Player :: Player(istream& input, const CardFactory* cardFactory) {
	char line[30];
	
	string str = "";
	int index = 0;
	input.getline(line, 30, '\n');
	cout << line;
	while (line[index] != ' ') {
		this->name += line[index++];
	}

	index++;
	while (line[index] != ' ') {
		str += line[index++];
	}
	this->numCoins = atoi(str.c_str());

	index++;
	str = "";

	while (line[index] != ' ') {
		str += line[index++];
	}
	this->numChains = atoi(str.c_str());

	


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
	case 'E':this->chain1 = nullptr;
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
	case 'E':this->chain2 = nullptr;
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
	case 'E':this->chain3 = nullptr;
	}

	this->hand = new Hand(input,cardFactory);
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
	else if (i == 2 && numChains == 3) {
		chain = chain3;
	}
	else {
		cout << "Index invalid !";
		chain = nullptr;
	}
	return chain;
};

class NotEnoughCoins : public exception {
	virtual const char* what() const throw() {
		return " Not enough coins for 3th chain";
	}
};

void Player :: buyThirdChain() {
	if (numChains == 2 && numCoins >=3) {
		numChains++;
		numCoins -= 3;
		cout << "Chain bought !" << endl;
	}
	else if (numChains == 2 && numCoins < 3) {
		throw NotEnoughCoins();
	}
	else if (numChains == 3) {
		cout << "already have 3 chains ! ";
	}
};

void Player :: display() {

	cout << "Player's name : " << name << endl;
	cout << "Number of coins : " << getNumCoins() << endl;
	if (hand != nullptr) {
		hand->display();
	}
	if (chain1 != nullptr) {
		cout << " Chain 1 : ";
		chain1->display();
	}
	if (chain2 != nullptr) {
		cout << "Chain 2 : ";
		chain2->display();
	}
	if (chain3 != nullptr && getNumChains() == 3) {
		cout << "Chain 3 :";
		chain3->display();
	}
}

bool Player::addCard(Card * card) {


	if (chain1 != nullptr && (chain1->type == card->getName() || chain1->empty())) {
		chain1->push_back(card);
		chain1->numOfCards++;
		return true;
	}
	else if (chain2 != nullptr && (chain2->type == card->getName() || chain2->empty())) {
		chain2->push_back(card);
		chain2->numOfCards++;
		return true;
	}
	else if (chain3 != nullptr && (this->getNumChains() == 3 && (chain3->type == card->getName() || chain3->empty()))) {
		chain3->push_back(card);
		chain3->numOfCards++;
		return true;
	}else if (chain1 == nullptr) {
		chain1 = createChain(card->getName().at(0));
		chain1->push_back(card);
		chain1->numOfCards++;
		return true;
	}else if (chain2 == nullptr) {
		chain2 = createChain(card->getName().at(0));
		chain2->push_back(card);
		chain2->numOfCards++;
		return true;
	}if (chain3 == nullptr && numChains == 3) {
		chain3 = createChain(card->getName().at(0));
		chain3->push_back(card);
		chain3->numOfCards++;
		return true;
	}

	return false;
}


Chain_Base* Player::createChain(char cardFirstChar) {
	switch (cardFirstChar)
	{
	case 'B': return new Chain<Black>();
	case 'b':return new Chain<Blue>();
	case 'C':return new Chain<Chili>();
	case 'G':return new Chain<Garden>();
	case 'g':return new Chain<Green>();
	case 'R':return new Chain<Red>();
	case 'S':return new Chain<Soy>();
	case 's':return new Chain<Stink>();
	}
}


void Player::play() {
	Card* card = hand->play();
	cout << name << " is playing : " << card->getName() << endl;
	if (card != nullptr) {
		bool cardAdded = addCard(card);
		char answer;
		int gain = 0;

		if (!cardAdded) {

			if (numChains == 3) {
				cout << "Choose a chain to sell between chain 1 (1), chain 2 (2) or chain 3 (3) : ";
				cin >> answer;
				while (answer != '1' && answer != '2' && answer != '3') {
					cout << "Invalid choice chain 1 (1), chain 2 (2) or chain 3 (3) : ";
					cin >> answer;
				}

				if (answer == '1') {
					gain = chain1->sell();
					chain1->push_back(card);
					cout << " Chain 1 sold and put " << card->getName() << " in it." << endl;
				}
				else if (answer == '2') {
					gain = chain2->sell();
					chain2->push_back(card);
					cout << " Chain 2 sold and put " << card->getName() << " in it." << endl;
				}
				else if (answer == '3') {
					gain = chain3->sell();
					chain3->push_back(card);
					cout << " Chain 3 sold and put " << card->getName() << " in it. " <<endl;
				}
			}
			else {
				cout << "Choose a chain to sell between chain 1 (1) or chain 2 (2) : ";
				cin >> answer;
				while (answer != '1' && answer != '2') {
					cout << "Invalid choice chain 1 (1) or chain 2 (2) : ";
					cin >> answer;
				}

				if (answer == '1') {
					gain = chain1->sell();
					chain1->push_back(card);
					cout << " Chain 1 sold and put " << card->getName() << " in it. " << endl;
				}
				else if (answer == '2') {
					gain = chain2->sell();
					chain2->push_back(card);
					cout << " Chain 2 sold and put " << card->getName() << " in it. " << endl;
				}
			}
			this->numCoins += gain;
			cout << this->name << " has " << this->getNumCoins() << " coins" << endl;;
		}
	}
}

int Player::getNumOfCards() {
	int num = 0;
	if (chain1 != nullptr) {
		num += chain1->size();
	}

	if (chain2 != nullptr) {
		num += chain2->size();
	}

	if (numChains == 3 && chain3 != nullptr) {
		num += chain3->size();
	}

	if (hand != nullptr) {
		num += hand->size();
	}

	return num;
}


