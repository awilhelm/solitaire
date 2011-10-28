#include <algorithm>
#include <iostream>

#include "sol/game.h"

using namespace sol;
using namespace std;

int main(void) {
	srand(time(0));
	Game game;
	while(cin) {
		cout << "\033[2J" << game << " > ";
		cin >> game;
	}
	cout << endl;
}
