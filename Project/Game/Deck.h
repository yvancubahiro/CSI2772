#pragma once
using namespace std;
#include <vector>
class Deck {
	vector<Card>* cards;

public :
	Deck() {
		cards = new vector<Card>(104);

		for (int i = 0; i < 20; i++) {
			cards->push_back(Blue());
		}
		for (int i = 0; i < 18; i++) {
			cards->push_back(Chili());
		}
		for (int i = 0; i < 16; i++) {
			cards->push_back(Stink());
		}
		for (int i = 0; i < 14; i++) {
			cards->push_back(Green());
		}
		for (int i = 0; i < 12; i++) {
			cards->push_back(Soy());
		}
		for (int i = 0; i < 10; i++) {
			cards->push_back(Black());
		}
		for (int i = 0; i < 8; i++) {
			cards->push_back(Red());
		}
		for (int i = 0; i < 6; i++) {
			cards->push_back(Garden());
		}

	}

};