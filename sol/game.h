#pragma once

#include <ostream>

#include "deck.h"
#include "foundation.h"
#include "rulebook.h"
#include "stock.h"
#include "tableau.h"
#include "waste.h"

namespace sol {

/// \addtogroup solitaire
/// \{

struct Game {
	Game(void);
	void deal(void);
private:
	Deck deck;
	Stock stock;
	Waste waste;
	Foundation foundation;
	Tableau tableau;
	Rulebook rules;
	friend std::ostream & operator << (std::ostream &, Game const&);
	friend std::istream & operator >> (std::istream &, Game &);
};

/// \}

}
