#include "card.h"
#include "rulebook.h"

using namespace std;

namespace sol {

Rulebook::move_validator_for_tableau Rulebook::make_move_validator_for_tableau(list<Card const*> const& pile) const {
	return move_validator_for_tableau(*this, pile);
}

Rulebook::move_validator_for_foundation Rulebook::make_move_validator_for_foundation(stack<Card const*> const& pile) const {
	return move_validator_for_foundation(*this, pile);
}

bool Rulebook::validate_move_for_tableau(Card const* card, list<Card const*> const& destination) const {
	return (destination.empty() && card->rank == KING) || (!destination.empty() && card->suit % 2 != destination.back()->suit % 2 && card->rank == destination.back()->rank - 1);
}

bool Rulebook::validate_move_for_foundation(Card const* card, stack<Card const*> const& destination) const {
	return (destination.empty() && card->rank == ACE) || (!destination.empty() && card->rank == destination.top()->rank + 1);
}

bool Rulebook::move_validator_for_tableau::operator()(Card const* card) const {
	return rules.validate_move_for_tableau(card, destination);
}

bool Rulebook::move_validator_for_foundation::operator()(Card const* card) const {
	return rules.validate_move_for_foundation(card, destination);
}

}
