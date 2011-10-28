#include <algorithm>
#include <iterator>

#include "deck.h"
#include "except/empty-pile.h"
#include "except/illegal-move.h"
#include "foundation.h"
#include "rulebook.h"
#include "tableau.h"
#include "waste.h"

#define sizeofarray(x) (sizeof(x) / sizeof(*(x)))

using namespace std;

namespace sol {

void Tableau::feed(Deck & deck) {
	for(size_t pile = 0; pile < sizeofarray(hidden_piles); ++pile) {
		for(size_t i = 0; i < pile; ++i) deck.deal(hidden_piles[pile]);
		deck.deal(visible_piles[pile]);
	}
}

void Tableau::flip(size_t i) {
	if(!visible_piles[i].empty() || hidden_piles[i].empty()) return;
	visible_piles[i].push_back(hidden_piles[i].top());
	hidden_piles[i].pop();
}

bool Tableau::validate_index(size_t i) const {
	return i < sizeofarray(visible_piles);
}

void Tableau::move(size_t origin, size_t destination) {
	visible_piles[destination].splice(visible_piles[destination].end(), visible_piles[origin], find_if(visible_piles[origin].begin(), visible_piles[origin].end(), rules.make_move_validator_for_tableau(visible_piles[destination])), visible_piles[origin].end());
	flip(origin);
}

void Tableau::move_from(Waste & waste, size_t destination) {
	waste.move_to(visible_piles[destination]);
}

void Tableau::move_from(Foundation & foundation, Suit suit, size_t destination) {
	foundation.move_to(visible_piles[destination], suit);
}

void Tableau::move_to(Foundation & foundation, size_t origin) {
	foundation.move_from(*this, origin, visible_piles[origin].back()->suit);
}

void Tableau::move_to(stack<Card const*> & pile, size_t origin) {
	if(visible_piles[origin].empty()) throw except::empty_pile();
	if(!rules.validate_move_for_foundation(visible_piles[origin].back(), pile)) throw except::illegal_move();
	pile.push(visible_piles[origin].back());
	visible_piles[origin].pop_back();
	flip(origin);
}

ostream & operator << (ostream & out, Tableau const& tableau) {
	for(size_t i = 0; i < sizeofarray(tableau.hidden_piles); ++i) {
		out << (i + 1) << ":" << tableau.hidden_piles[i].size() << " ";
		copy(tableau.visible_piles[i].begin(), tableau.visible_piles[i].end(), ostream_iterator<Card const*>(out, " "));
		out << endl;
	}
	return out;
}

size_t to_pile(char x) {
	return x - '1';
}

}
