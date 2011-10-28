#pragma once

#include <ostream>
#include <stack>

namespace sol {

struct Card;
struct Deck;

struct Stock {
	void feed(Deck &);
	void feed(std::stack<Card const*> &);
	void move_to(std::stack<Card const*> &);
private:
	std::stack<Card const*> pile;
	friend std::ostream & operator << (std::ostream &, Stock const&);
};

}
