#include "Wberry.h"

Wberry::Wberry(Wberry* wberry, Position* position, World* world)
	:Plant(wberry, position, world) {
	initialParameters();
}

Organism* Wberry::clone() {
	return new Wberry(this, nullptr, nullptr);
}

std::vector<Action> Wberry::collision(Organism* atackingOrganism) {
	std::vector<Action> result;
	result.push_back(Action(REMOVE, 0, atackingOrganism->getPosition(), atackingOrganism));
	result.push_back(Action(REMOVE, 0, getPosition(), this));
	return result;
}

void Wberry::initialParameters() {
	setStrength(99);
	setInitiative(0);
	setAge(0);
	setSign('R');
	setName("Wberry");
}