#pragma once

#include <list>
#include <stack>

#include "suit.h"

namespace sol {

struct Card;
struct Deck;
struct Foundation;
struct Rulebook;
struct Waste;

struct Tableau {
	Tableau(Rulebook const& rules): rules(rules) {}
	void feed(Deck &);
	bool validate_index(size_t) const;
	void move(size_t, size_t);
	void move_from(Waste &, size_t);
	void move_from(Foundation &, Suit, size_t);
	void move_to(Foundation &, size_t);
	void move_to(std::stack<Card const*> &, size_t);
private:
	void flip(size_t);
	Rulebook const& rules;
	std::list<Card const*> visible_piles[7];
	std::stack<Card const*> hidden_piles[7];
	friend std::ostream & operator << (std::ostream &, Tableau const&);
};

size_t to_pile(char);

}
