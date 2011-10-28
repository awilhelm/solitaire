#pragma once

#include <list>
#include <ostream>
#include <stack>

namespace sol {

struct Card;
struct Foundation;
struct Rulebook;
struct Stock;

struct Waste {
	Waste(Rulebook const& rules): rules(rules) {}
	void move_from(Stock &);
	void move_to(Foundation &);
	void move_to(std::list<Card const*> &);
	void move_to(std::stack<Card const*> &);
private:
	const Rulebook &rules;
	std::stack<Card const*> pile;
	friend std::ostream & operator << (std::ostream &, Waste const&);
};

}
