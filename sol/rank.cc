#include "rank.h"

using namespace std;

namespace sol {

ostream & operator << (ostream & out, Rank rank) {
	static char const* const ranks[] = { " ", "₂", "₃", "₄", "₅", "₆", "₇", "₈", "₉", "₀", "♝", "♞", "♛", "♚" };
	return out << ranks[rank];
}

}
