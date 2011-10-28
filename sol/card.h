#pragma once

#include "rank.h"
#include "suit.h"

namespace sol {

struct Card {
	Suit suit;
	Rank rank;
	Card(Suit, Rank);
};

std::ostream & operator << (std::ostream &, Card const*);

}
