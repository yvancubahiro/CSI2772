#pragma once

class Hand: public vector<Card*>{
public :
	Hand& operator+=(Card*);
	Card* play();
	Card* top();
	Card* operator[](int);
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