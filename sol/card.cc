#include "card.h"

using namespace std;

namespace sol {

Card::Card(Suit suit, Rank rank): suit(suit), rank(rank) {}

ostream & operator << (ostream & out, Card const* card) {
	return out << "\033[3" << ((card->suit % 2) ? '4' : '1') << 'm' << card->suit << card->rank << "\033[m";
}

}
