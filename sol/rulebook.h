#pragma once

#include <list>
#include <stack>

namespace sol {

struct Card;

class Rulebook {
	struct move_validator_for_tableau;
	struct move_validator_for_foundation;
public:
	move_validator_for_tableau make_move_validator_for_tableau(std::list<Card const*> const&) const;
	move_validator_for_foundation make_move_validator_for_foundation(std::stack<Card const*> const&) const;
	virtual bool validate_move_for_tableau(Card const*, std::list<Card const*> const& destination) const;
	virtual bool validate_move_for_foundation(Card const* card, std::stack<Card const*> const& destination) const;
};

struct Rulebook::move_validator_for_tableau {
	move_validator_for_tableau(Rulebook const& rules, std::list<Card const*> const& pile): rules(rules), destination(pile) {}
	bool operator()(Card const* card) const;
private:
	Rulebook const& rules;
	std::list<Card const*> const& destination;
};

struct Rulebook::move_validator_for_foundation {
	move_validator_for_foundation(Rulebook const& rules, std::stack<Card const*> const& pile): rules(rules), destination(pile) {}
	bool operator()(Card const* card) const;
private:
	Rulebook const& rules;
	std::stack<Card const*> const& destination;
};

}
