#include "World.h"
#include <algorithm>

World::World(int x, int y) :
	xLength(x),
	yLength(y),
	turn(0){}

int World::getXLength() const {
	return xLength;
}
int World::getYLength() const {
	return yLength;
}
int World::getTurn() const {
	return turn;
}
std::vector<Organism> World::getOrganisms() const {
	return organisms;
}
std::vector<Organism> World::getNewOrganisms() const {
	return newOrganisms;
}

void World::setTurn(int turn) {
	this->turn = turn;
}
void World::setOrganisms(std::vector<Organism> organisms) {
	this->organisms = organisms;
}
void World::setNewOrganisms(std::vector<Organism> newOrganisms) {
	this->newOrganisms = newOrganisms;
}

void World::makeTurn() {
	std::vector<Action> actions;
	for (int o = 0; o < organisms.size(); o++) {
		if (positionOnBoard(organisms[o].getPosition())) {
			actions = organisms[o].move();
			for (int a = 0; a < actions.size(); a++) {
				makeMove(actions[a]);
			}
			actions.clear();
			if (positionOnBoard(organisms[o].getPosition())) {
				actions = organisms[o].action();
				for (int a = 0; a < actions.size(); a++) {
					makeMove(actions[a]);
				}
				actions.clear();
			}
		}
	}

	for (int o = organisms.size() - 1; o >= 0; o--) {
		if (!positionOnBoard(organisms[o].getPosition()))
			organisms.erase(organisms.begin() + o);
	}
	for (int o = newOrganisms.size() - 1; o >= 0; o--) {
		if (!positionOnBoard(newOrganisms[o].getPosition()))
			newOrganisms.erase(newOrganisms.begin() + o);
	}
	for (int o = 0; o < newOrganisms.size(); o++) {
		organisms.push_back(newOrganisms[o]);
	}
	std::sort(organisms.begin(), organisms.end(), sortOrganisms);
	//TODO: CHECK SORT ALGORITHM 
	newOrganisms.clear();
	turn++;
}

void World::makeMove(Action action) {
	std::cout << action;
	if (action.getAction() == ADD) {
		newOrganisms.push_back(*action.getOrganism());
	}
	else if (action.getAction() == REMOVE) {
		action.getOrganism()->setPosition(new Position(-1, -1));
	}
	else if (action.getAction() == MOVE) {
		action.getOrganism()->setPosition(action.getPositon());
	}
	else if (action.getAction() == INCREASEPOWER) {
		int currStrength = action.getOrganism()->getStrength();
		action.getOrganism()->setStrength(currStrength + action.getValue());
	}
}

bool World::addOrganism(Organism& newO) {
	if (positionOnBoard(newO.getPosition())) {
		organisms.push_back(newO);
		std::sort(organisms.begin(), organisms.end(), sortOrganisms);
		return true;
	}
	return false;
}

bool World::positionOnBoard(Position* p) {
	return (p->getX() >= 0 && p->getY() >= 0 &&
		p->getX() < xLength && p->getY() < yLength) ? true : false;
}

bool World::sortOrganisms(Organism &o1, Organism &o2) {
	if (o1.getInitiative() > o2.getInitiative()) return true;
	else if (o1.getInitiative() == o2.getInitiative()) {
		if (o1.getAge() > o2.getAge()) return true;
		else return false;
	}
	else return false;
}



/*
	Organism* getOrganismFromPosition(Position);

	Position* getNeighboringPositions(Position);

	std::vector<Position> filterFreePositions(std::vector<Position>);

	std::vector<Position> filterPositionsWithoutAnimals(std::vector<Position>);
	
	std::vector<Position> filterPositionsWithOtherSpecies(std::vector<Position>);
*/
