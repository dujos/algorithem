#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <string>
#include <iostream>

class Functor {

public:
	Functor(int);
	~Functor();
	Functor(const Functor& func);

	void operator() (std::string& str);
	void operator() ();
	void operator() (int k);

	void add(int a);

private:
	int x;
};

class Line {

public:
	void operator() (int x) const;
	void operator() (int x, int y) const;
};

class Card {

public:
	char* face;
	char* suit;

	void static set_deck(Card* card, char* face[], char* suit[]);
	void static shuffle_deal(Card* card);
};





#endif