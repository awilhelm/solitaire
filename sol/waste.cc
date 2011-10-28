#include "card.h"
#include "except/empty-pile.h"
#include "except/illegal-move.h"
#include "foundation.h"
#include "rulebook.h"
#include "stock.h"
#include "waste.h"

using namespace std;

namespace sol {

void Waste::move_from(Stock & stock) {
	try {
		stock.move_to(pile);
	} catch(except::empty_pile) {
		stock.feed(pile);
	}
}

void Waste::move_to(Foundation & foundation) {
	foundation.move_from(*this, pile.top()->suit);
}

void Waste::move_to(list<Card const*> & target) {
	if(pile.empty()) throw except::empty_pile();
	if(!rules.validate_move_for_tableau(pile.top(), target)) throw except::illegal_move();
	target.push_back(pile.top());
	pile.pop();
}

void Waste::move_to(stack<Card const*> & target) {
	if(pile.empty()) throw except::empty_pile();
	if(!rules.validate_move_for_foundation(pile.top(), target)) throw except::illegal_move();
	target.push(pile.top());
	pile.pop();
}

ostream & operator << (ostream & out, Waste const& waste) {
	out << waste.pile.size();
	if(!waste.pile.empty()) out << ' ' << waste.pile.top();
	return out;
}

}
