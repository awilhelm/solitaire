#include "deck.h"
#include "except/empty-pile.h"
#include "stock.h"

using namespace std;

namespace sol {

void Stock::feed(Deck & deck) {
	try {
		for(;;) deck.deal(pile);
	} catch(except::empty_pile) {}
}

void Stock::feed(stack<Card const*> & source) {
	while(!source.empty()) {
		pile.push(source.top());
		source.pop();
	}
}

void Stock::move_to(stack<Card const*> & target) {
	if(pile.empty()) throw except::empty_pile();
	target.push(pile.top());
	pile.pop();
}

ostream & operator << (ostream & out, Stock const& stock) {
	return out << stock.pile.size();
}

}
