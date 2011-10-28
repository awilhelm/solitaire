#pragma once

#include <list>
#include <stack>
#include <vector>

#include "card.h"

namespace sol {

struct Deck {
	Deck(void);
	void deal(std::list<Card const*> &);
	void deal(std::stack<Card const*> &);
private:
	std::vector<Card> cards;
	std::vector<Card>::iterator cursor;
};

}
