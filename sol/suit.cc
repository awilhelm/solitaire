#include <algorithm>

#include "suit.h"

using namespace std;

namespace sol {

ostream & operator << (ostream & out, Suit suit) {
	static char const* const suits[] = { "♦", "♠", "♥", "♣" };
	return out << suits[suit];
}

Suit to_suit(char x) {
	static char const suits[] = { 'd', 's', 'h', 'c' };
	return Suit(find(suits, suits + 4, x) - suits);
}

}
