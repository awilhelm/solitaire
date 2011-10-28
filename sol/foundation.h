#pragma once

#include <list>
#include <stack>

#include "suit.h"

namespace sol {

struct Card;
struct Rulebook;
struct Tableau;
struct Waste;

struct Foundation {
	Foundation(Rulebook const& rules): rules(rules) {}
	void move_from(Waste &);
	void move_from(Waste &, Suit);
	void move_from(Tableau &, size_t);
	void move_from(Tableau &, size_t, Suit);
	void move_to(std::list<Card const*> &, Suit);
private:
	const Rulebook &rules;
	std::stack<Card const*> piles[SUIT_MAX];
	friend std::ostream & operator << (std::ostream &, Foundation const&);
};

}
