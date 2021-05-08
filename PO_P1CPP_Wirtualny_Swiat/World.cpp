#include "World.h"
#include <algorithm>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

World::World(int x, int y) :
	xLength(x),
	yLength(y),
	turn(0),
	emptyPlace('.'){
	srand(time(NULL));
}

int World::getXLength() const {
	return xLength;
}
int World::getYLength() const {
	return yLength;
}
int World::getTurn() const {
	return turn;
}
char World::getEmptyPlace() const {
	return emptyPlace;
}
std::vector<Organism*> World::getOrganisms() const {
	return organisms;
}
std::vector<Organism*> World::getNewOrganisms() const {
	return newOrganisms;
}

void World::setTurn(int turn) {
	this->turn = turn;
}
void World::setOrganisms(std::vector<Organism*> organisms) {
	this->organisms = organisms;
}
void World::setNewOrganisms(std::vector<Organism*> newOrganisms) {
	this->newOrganisms = newOrganisms;
}

void World::makeTurn() {
	//(c = _getch())
	std::vector<Action> actions;
	for (int o = 0; o < (int)organisms.size(); o++) {
		if (positionOnBoard(organisms[o]->getPosition())) {
			actions = organisms[o]->move();
			for (int a = 0; a < (int)actions.size(); a++) {
				makeMove(actions[a]);
			}
			actions.clear();
			if (positionOnBoard(organisms[o]->getPosition())) {
				actions = organisms[o]->action();
				for (int a = 0; a < (int)actions.size(); a++) {
					makeMove(actions[a]);
				}
				actions.clear();
			}
		}
	}

	for (int o = organisms.size() - 1; o >= 0; o--) {
		if (!positionOnBoard(organisms[o]->getPosition()))
			organisms.erase(organisms.begin() + o);
	}
	for (int o = newOrganisms.size() - 1; o >= 0; o--) {
		if (!positionOnBoard(newOrganisms[o]->getPosition()))
			newOrganisms.erase(newOrganisms.begin() + o);
	}
	for (int o = 0; o < (int)newOrganisms.size(); o++) {
		organisms.push_back(newOrganisms[o]);
	}
	std::sort(organisms.begin(), organisms.end(), [](const Organism* x, const Organism* y) {
		if (x->getInitiative() != y->getInitiative()) {
			return x->getInitiative() < y->getInitiative();
		}
		return x->getAge() < y->getAge();
		});
	//TODO: CHECK SORT ALGORITHM 
	newOrganisms.clear();
	turn++;
}

void World::makeMove(Action action) {
	std::cout << action;
	if (action.getAction() == ADD) {
		newOrganisms.push_back(action.getOrganism());
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

void World::getAction() {
	int c;
	while (1) {
		c = 0;
		switch ((c = _getch())) {
		case 224: {
			switch ((c = _getch())) {
			case KEY_UP: {
				whatToDo = UP;
				return;
			}
			case KEY_DOWN: {
				whatToDo = DOWN;
				return;
			}
			case KEY_LEFT: {
				whatToDo = LEFT;
				return;
			}
			case KEY_RIGHT: {
				whatToDo = RIGHT;
				return;
			}
			default: {
				break;
			}
			}
			break;
		}
		case 's': {
			if (canUseSpecial) {
				whatToDo = SPECIAL;
				return;
			}
			std::cout << "You must wait " << turnsToUseSpecial << " turns to use special ability.\n";
			break;
		}
		case 'v': {
			//save;
			return;
		}
		default:
			break;
		}

	}
}

bool World::addOrganism(Organism* newO) {
	if (positionOnBoard(newO->getPosition())) {
		organisms.push_back(newO);
		std::sort(organisms.begin(), organisms.end(), [](const Organism* x, const Organism* y) {
			// compare last names first
			if (x->getInitiative() != y->getInitiative()) {
				return x->getInitiative() < y->getInitiative();
			}

			// compare first names only if the last names are equal
			return x->getAge() < y->getAge();
			}); 
		return true;
	}
	return false;
}

bool World::positionOnBoard(Position* p) const{
	return (p->getX() >= 0 && p->getY() >= 0 &&
		p->getX() < xLength && p->getY() < yLength) ? true : false;
}

Organism* World::getOrganismFromPosition(Position searchedPosition) const{
	Organism* pomOrganism = nullptr;
	for (int o = 0; o < (int)organisms.size(); o++) {
		if (searchedPosition.getX() == organisms[o]->getPosition()->getX()
			&& searchedPosition.getY() == organisms[o]->getPosition()->getY()) {
			pomOrganism = organisms[o];
			break;
		}
	}
	if (pomOrganism == nullptr) {
		for (int o = 0; o < (int)newOrganisms.size(); o++) {
			if (searchedPosition.getX() == newOrganisms[o]->getPosition()->getX()
				&& searchedPosition.getY() == newOrganisms[o]->getPosition()->getY()) {
				pomOrganism = newOrganisms[o];
				break;
			}
		}
	}
	return pomOrganism;
}

std::vector<Position> World::getNeighboringPositions(Position p) const{
	std::vector<Position> result;
	Position positionToCheck;
	for (int x = -1; x < 2; x++) {
		for (int y = -1; y < 2; y++) {
			positionToCheck = Position(p.getX() + x, p.getY() + y);
			if (positionOnBoard(&positionToCheck) && (y != 0 || x != 0)) {
				result.push_back(positionToCheck);
			}
		}
	}
	return result;
}

std::vector<Position> World::filterFreePositions(std::vector<Position> positions) {
	std::vector<Position> result;
	for (int p = 0; p < (int)positions.size(); p++) {
		if (getOrganismFromPosition(positions[p]) == nullptr) {
			result.push_back(positions[p]);
		}
	}
	return result;
}

std::vector<Position> World::filterPositionsWithoutAnimals(std::vector<Position> positions) {
	std::vector<Position> result;
	Organism* pomOrganism;
	for (int p = 0; p < (int)positions.size(); p++) {
		pomOrganism = getOrganismFromPosition(positions[p]);
		if (pomOrganism != nullptr) {
			if (pomOrganism->getInitiative() > 0) {
				result.push_back(positions[p]);
			}
		}
	}
	return result;
}
std::vector<Position> World::filterPositionsWithOtherSpecies(std::vector<Position> positions) {
	std::vector<Position> result;
	for (int p = 0; p < (int)positions.size(); p++) {
		if (getOrganismFromPosition(positions[p]) == nullptr) {
			result.push_back(positions[p]);
		}
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const World& world) {
	Organism* pomOrg;
	os << "\nTurn: " << world.getTurn() << "\n";
	for (int x = 0; x < world.getXLength(); x++) {
		for (int y = 0; y < world.getYLength(); y++) {
			pomOrg = world.getOrganismFromPosition(Position(x, y));
			if (pomOrg) {
				os << pomOrg->getSign();
			}
			else {
				os << world.getEmptyPlace();
			}	
		}
	}
	return os;
}