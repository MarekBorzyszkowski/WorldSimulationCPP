#include <iostream>
#include <conio.h>
#include "Game.h"

using namespace std;

int main() {
	cout << "Do you want to load the world? (y/n) ";
	World world(0,0);
	int c;
	int x, y;
	Game game;
	while (c = _getch()) {
		if (c == 'y') {
			game.load(world);
			break;
		}
		else if (c == 'n') {
			cout << "\nPass the world size(for best experience pick at least 6x6) ";
			cin >> x >> y;
			world = World(x, y);
			game.setUpWorld(&world);
			break;
		}
	}
	world.draw();
	while (true) {
		if (!world.makeTurn()) {
			break;
		}
		world.draw();
	}
	world.clear();
	cout << "GAME HAS ENDED\nTHANKS FOR PLAYING!";
	return 0;
	
}