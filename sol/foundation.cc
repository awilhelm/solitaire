#include "card.h"
#include "except/empty-pile.h"
#include "except/illegal-move.h"
#include "foundation.h"
#include "rulebook.h"
#include "tableau.h"
#include "waste.h"

using namespace std;

namespace sol {

void Foundation::move_from(Waste & waste) {
	waste.move_to(*this);
}

void Foundation::move_from(Waste & waste, Suit suit) {
	try {
		waste.move_to(piles[suit]);
	} catch(except::empty_pile) {
	} catch(except::illegal_move) {}
}

void Foundation::move_from(Tableau & tableau, size_t origin) {
	tableau.move_to(*this, origin);
}

void Foundation::move_from(Tableau & tableau, size_t origin, Suit suit) {
	try {
		tableau.move_to(piles[suit], origin);
	} catch(except::empty_pile) {
	} catch(except::illegal_move) {}
}

void Foundation::move_to(list<Card const*> & pile, Suit suit) {
	if(piles[suit].empty()) throw except::empty_pile();
	if(!rules.validate_move_for_tableau(piles[suit].top(), pile)) throw except::illegal_move();
	pile.push_back(piles[suit].top());
	piles[suit].pop();
}

ostream & operator << (ostream & out, Foundation const& foundation) {
	for(size_t i = 0; i < SUIT_MAX; ++i) {
		if(!foundation.piles[i].empty()) {
			out << (i ? " " : "") << foundation.piles[i].top();
		}
	}
	return out;
}

}
