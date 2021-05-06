#include "Guarana.h"

Guarana::Guarana(Guarana* guarana, Position* position, World* world)
	:Plant(guarana, position, world) {
	initialParameters();
}

Organism* Guarana::clone() {
	return new Guarana(this, nullptr, nullptr);
}

std::vector<Action> Guarana::collision(Organism* atackingOrganism) {
	std::vector<Action> result;
	result.push_back(Action(INCREASEPOWER, 3, atackingOrganism->getPosition(), atackingOrganism));
	result.push_back(Action(REMOVE, 0, getPosition(), this));
	return result;
}

void Guarana::initialParameters() {
	setStrength(0);
	setInitiative(0);
	setAge(0);
	setSign('+');
	setName("Guarana");
}