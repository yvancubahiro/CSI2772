#pragma once

class DiscardPile {
public:
	vector <Card*> cards;
	DiscardPile& operator+=(Card*);
	Card* pickUp();
	Card* top();
	void print(std::ostream&);
};


DiscardPile& DiscardPile :: operator+=(Card* card) {
	cards.push_back(card);
	return *this;
};

Card* DiscardPile::pickUp() {
	Card* card;
	if (cards.empty()) {
		cout << "the stack is empty";
		card = nullptr;
	}
	else {
		card = cards.back();
		cards.pop_back();
	}

	return card;
}

Card* DiscardPile :: top() {
	if (cards.empty()) {
		cout << "the stack is empty";
		return nullptr;
	}
	else {
		return cards.back();
	}
}

