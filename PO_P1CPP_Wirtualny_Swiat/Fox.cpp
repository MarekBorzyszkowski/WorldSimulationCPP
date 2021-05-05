#include "Fox.h"

Fox::Fox(Fox* sheep, Position* position, World* world)
	:Animal(sheep, position, world) {
}

Organism* Fox::clone() {
	return new Fox(this, nullptr, nullptr);
}

void Fox::initialParameters() {
	setStrength(3);
	setInitiative(7);
	setAge(0);
	setSign('F');
	setName(new std::string("Fox"));
}

std::vector<Position> Fox::getNeighboringPositions() {
	std::vector<Position> positionToSearch = Animal::getNeighboringPositions();
	std::vector<Position> result;
	for (int p = 0; p < (int)positionToSearch.size(); p++) {
		if (getWorld()->getOrganismFromPosition(positionToSearch[p])->getStrength() > getStrength()) {
			result.push_back(positionToSearch[p]);
		}
	}
	return result;
}
