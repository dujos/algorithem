#include "Functor.h"

Functor::Functor(int x) : 
  x(x) {
}

Functor::Functor(const Functor& func) {
	x = func.x;
}

Functor::~Functor() {}

void Functor::operator() () {
	std::cout << "Functor A" << std::endl;
}

void Functor::operator() (std::string& str) {
	str = "functor a " + str;
	std::cout << str << std::endl;
}

void Functor::operator() (int k) {
	std::cout << k + x << std::endl;
}

void Functor::add(int a) {
	x = x + a;
}

void Line::operator() (int x) const {
	std::cout << x << " ";
}

void Line::operator() (int x, int y) const {
	std::cout << x << " " << y;
}

void Card::set_deck(Card* deck, char* face[], char* suit[]) {
	for(int i = 0; i < 52; i++) {
		deck[i].face = face[i % 13];
		deck[i].suit = suit[i % 4];
	}
}

void  Card::shuffle_deal(Card* deck) {
	for(int i = 0; i < 52; i++) {
		int ii = rand() % 52;
		Card card = deck[i];
		deck[i] = deck[ii];
		deck[ii] = card;
	}

	for (int i = 0; i < 52; i++)
		std::cout << i << ": " << deck[i].face << " of " << deck[i].suit << std::endl;
}


