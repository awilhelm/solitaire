#include "except/illegal-move.h"
#include "game.h"

using namespace std;

namespace sol {

Game::Game(void): waste(rules), foundation(rules), tableau(rules) {
	tableau.feed(deck);
	stock.feed(deck);
}

void Game::deal(void) {
	waste.move_from(stock);
}

ostream & operator << (ostream & out, Game const& game) {
	return out << endl << game.tableau << endl << game.stock << '/' << game.waste << " ~ " << game.foundation;
}

istream & operator >> (istream & in, Game & game) {
	string x;
	in >> x;
	try {
		switch(x.size()) {

			/// <ul><li> Si l'utilisateur a entré un seul caractère :
			case 1: {
				size_t destination = to_pile(x[0]);

				///- Déplace la carte au sommet de la défausse vers le tableau si la commande est un numéro de pile valide.
				if(game.tableau.validate_index(destination)) game.tableau.move_from(game.waste, destination);

				///- Déplace la carte au sommet de la défausse vers la fondation si la commande est une couleur valide.
				else if(to_suit(x[0]) != SUIT_MAX) game.foundation.move_from(game.waste);

				///- Distribue une carte sinon.
				else game.deal();

				break;
			}
			/// </ul>

			/// <ul><li> Si l'utilisateur a entré deux caractères :
			case 2: {
				size_t origin = to_pile(x[0]);
				size_t destination = to_pile(x[1]);
				if(game.tableau.validate_index(origin)) {

					///- Déplace une carte d'une pile vers une autre si la commande consiste en deux numéros de piles valides.
					if(game.tableau.validate_index(destination)) game.tableau.move(origin, destination);

					///- Déplace une carte du tableau vers la fondation si la commande consiste en un numéro de pile et une couleur.
					else if(to_suit(x[1]) != SUIT_MAX) game.foundation.move_from(game.tableau, origin);

				///- Déplace une carte de la fondation vers le tableau si la commande consiste en une couleur et un numéro de pile.
				} else if(to_suit(x[0]) != SUIT_MAX) game.tableau.move_from(game.foundation, to_suit(x[0]), destination);

				break;
			}
			/// </ul>
		}
	} catch(except::illegal_move) {}
	return in;
}

}
