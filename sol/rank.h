#pragma once

#include <ostream>

namespace sol {

enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, HEIGHT, NINE, TEN, JACK, KNIGHT, QUEEN, KING, RANK_MAX };

std::ostream & operator << (std::ostream & out, Rank rank);

}
