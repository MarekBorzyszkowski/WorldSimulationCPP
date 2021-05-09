#include "Fox.h"

Fox::Fox(Fox* fox, Position* position, World* world)
	:Animal(fox, position, world) {
	initialParameters();
}

Organism* Fox::clone() {
	return new Fox(this, nullptr, nullptr);
}

void Fox::initialParameters() {
	setStrength(3);
	setInitiative(7);
	setAge(0);
	setSign('F');
	setName("Fox");
}

std::vector<Position> Fox::getNeighboringPositions() {
	std::vector<Position> positionToSearch = Animal::getNeighboringPositions();
	std::vector<Position> result;
	Organism* pomOrganism;
	for (int p = 0; p < (int)positionToSearch.size(); p++) {
		pomOrganism = getWorld()->getOrganismFromPosition(positionToSearch[p]);
		if (pomOrganism != nullptr) {
			if (pomOrganism->getStrength() <= getStrength()) {
				result.push_back(positionToSearch[p]);
			}
		}
		else {
			result.push_back(positionToSearch[p]);
		}
		
	}
	return result;
}