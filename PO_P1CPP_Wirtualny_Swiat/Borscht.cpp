#include "Borscht.h"

Borscht::Borscht(Borscht* borscht, Position* position, World* world)
	:Plant(borscht, position, world) {
	initialParameters();
}

Organism* Borscht::clone() {
	return new Borscht(this, nullptr, nullptr);
}

std::vector<Action> Borscht::action() {
	std::vector<Action> result;
	result = reproduce();
	std::vector<Position> positionsToCheck = getWorld()
		->filterPositionsWithoutAnimals(getNeighboringPositions());
	Organism* pomOrganism;
	for (int i = 0; i < positionsToCheck.size(); i++) {
		pomOrganism = getWorld()->getOrganismFromPosition(positionsToCheck[i]);
		result.push_back(Action(REMOVE, 0, pomOrganism->getPosition(), pomOrganism));
	}
	return result;
}

std::vector<Action> Borscht::collision(Organism* atackingOrganism) {
	std::vector<Action> result;	
	if (this->getStrength() > atackingOrganism->getStrength()) {
		result.push_back(Action(REMOVE, 0, getPosition(), atackingOrganism));
	}
	else {
		result.push_back(Action(REMOVE, 0, getPosition(), this));
		result.push_back(Action(REMOVE, 0, getPosition(), atackingOrganism));
	}
	return result;
}

void Borscht::initialParameters() {
	setStrength(10);
	setInitiative(0);
	setAge(0);
	setSign('B');
	setName("Borscht");
}