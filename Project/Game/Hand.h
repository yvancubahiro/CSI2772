#pragma once
#include "Card.h"

class Hand: public vector<Card*>{
public :
	Hand& operator+=(Card*);
	Card* play();
	Card* top();
	Card* operator[](int);
	string printCards();
	friend ostream& operator << (ostream&, Hand);
	Hand(istream&, CardFactory*);
	Hand() {};
	void display();
	Card* pickACard(CardFactory * cardFacctory);
};

Hand& Hand :: operator+=(Card* card) {
	this->push_back(card);
	return *this;
};

Card* Hand :: play() {
	if (this->empty()) {
		cout << "Hand is empty";
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
		cout << "Hand is empty";
		return nullptr;
	}
	else {
		return this->front();
	}
};

Card* Hand :: operator[](int index) {
	if (this->size() == 0) {
		cout << "Hand is empty";
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

Hand :: Hand(istream& input, CardFactory* cardFactory) {
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
	char answer;
	bool matched = false;
	Card* card = nullptr;
	int index = 0;

	cout << "Choose a card between: ";
	for (Card* card : *this) {
		cout << card->getName() << " " << (card->getName().at(0)) << " , ";
	}
	cout << " : ";
	cin >> answer;

	do {
		for (Card* card : *this) {
			index++;
			if (card->getName().at(0) == answer) {
				
				this->erase(std::next(this->begin(), index - 1), std::next(this->begin(), index + 1));

				card = cardFactory->getCard(answer);
				matched = true;
				break;
			}
		}

		cout << "The picked card is not in hand try another card : ";
		cin >> answer;

	} while (!matched);

	return card;
}

