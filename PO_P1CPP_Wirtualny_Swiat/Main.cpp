#include <iostream>
#include <conio.h>
#include "Game.h"

using namespace std;

int main() {
	Game game;
	cout << "Do you want to load the world? (y/n): ";
	World world(0,0);
	char c;
	int x = 0, y = 0;
	cin >> c;
	if (c == 'y') {
		game.load(world);
	}
	else if (c == 'n') {
		cout << "Pass the world size(for best experience pick at least 6x6): ";
		while (true) {
			cin >> x >> y;
			if (x < 1 || y < 1) {
				cout << "Value of x or y is too small(<1), pass values that are >0: ";
			}
			else {
				break;
			}
		}
		world = World(x, y);
		game.setUpWorld(&world);
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