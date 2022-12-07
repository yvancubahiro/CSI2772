#pragma once
#include "Card.h"
#include "CardFactoryAndDeck.h"

class Hand: public vector<Card*>{
public :
	Hand& operator+=(Card*);
	Card* play();
	Card* top();
	Card* operator[](int);
	string printCards();
	friend ostream& operator << (ostream&, Hand);
	Hand(istream&,const CardFactory*);
	Hand() {};
	void display();
	Card* pickACard(CardFactory * cardFactory);
	void remove(int);
};

Hand& Hand :: operator+=(Card* card) {
	this->push_back(card);
	return *this;
};

Card* Hand :: play() {
	if (this->empty()) {
		cout << "Hand is empty" << endl;;
		return nullptr;
	}
	else {
		Card* firstCard = this->front();
		this->erase(this->begin());
		return firstCard;
	}
};

Card* Hand :: top() {
	if (this->empty()) {
		cout << "Hand is empty" << endl;
		return nullptr;
	}
	else {
		return this->front();
	}
};

Card* Hand :: operator[](int index) {
	if (this->size() == 0) {
		cout << "Hand is empty" << endl;
		return nullptr;
	}
	Card* card = this->at(index);
	this->erase(begin() + index);
	return card;
};

string Hand::printCards() {
	string result = " ";
	for (Card* card : *this) {
		result += card->getName();
	}
	return result;
};

ostream& operator << (ostream& output, Hand hand) {
	for (Card* card : hand) {
		card->print(output);
	}
	return output;
};

Hand :: Hand(istream& input,const CardFactory* cardFactory) {
	char line[1026];
	char card;
	int index = 0;
	input.getline(line, 1026);
	card = line[index];

	while (card != NULL) {
		this->push_back(cardFactory->getCard(card));
		card = line[++index];
	}
};

void Hand::display() {
	cout << "Hand : ";
	for (Card* card : *this) {
		cout << card->getName() << " ";
	}
	cout << endl;
}

Card* Hand::pickACard(CardFactory * cardFactory) {
	string answer;
	bool matched = false;
	Card* result = nullptr;
	int index;

	cout << "Choose a card between: ";
	for (Card* card : *this) {
		cout << card->getName() << " , ";
	}
	cout << " : ";
	cin >> answer;

	do {
		index = 0;
		for (Card* card : *this) {
			index++;
			if (card->getName() == answer) {
				result = cardFactory->getCard(card->getName().at(0));
				remove(index);
				matched = true;
				break;
			}
		}

		if (!matched) {
			cout << "The picked card is not in hand try another card : ";
			cin >> answer;
		}

	} while (!matched);

	return result;
}


void Hand::remove(int index) {
	auto iterator = this->begin();
	advance(iterator, index-1);
	this->erase(iterator);
}
