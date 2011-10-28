#pragma once

#include <ostream>

namespace sol {

enum Suit { DIAMONDS, SPADES, HEARTS, CLUBS, SUIT_MAX };

std::ostream & operator << (std::ostream & out, Suit suit);

Suit to_suit(char);

}
