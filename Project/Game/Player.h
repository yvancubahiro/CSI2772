#pragma once

class Player {
private :
	string name;
	int numCoins;
	int numChains = 2;
	Chain_Base* chain1;
	Chain_Base* chain2;
	Chain_Base* chain3;
public:
	Player(std::string&);
    string getName();
	int getNumCoins();
	Player& operator+=(int);
	int getMaxNumChains();
	int getNumChains();
	Chain_Base* operator[](int i);
	void buyThirdChain();
};

Player :: Player(string& name) {
	this->name = name;
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


