#include <algorithm>

#include "deck.h"
#include "except/empty-pile.h"

using namespace std;

namespace sol {

Deck::Deck(void) {
	cards.reserve(SUIT_MAX * RANK_MAX);
	for(long suit = 0; suit < SUIT_MAX; ++suit) {
		for(long rank = 0; rank < RANK_MAX; ++rank) {
			cards.push_back(Card(Suit(suit), Rank(rank)));
		}
	}
	random_shuffle(cards.begin(), cards.end());
	cursor = cards.begin();
}

void Deck::deal(list<Card const*> & target) {
	if(cursor == cards.end()) throw except::empty_pile();
	target.push_back(&*cursor++);
}

void Deck::deal(stack<Card const*> & target) {
	if(cursor == cards.end()) throw except::empty_pile();
	target.push(&*cursor++);
}

}
