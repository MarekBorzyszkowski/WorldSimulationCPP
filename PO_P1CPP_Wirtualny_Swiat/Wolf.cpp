#include "Wolf.h"

Wolf::Wolf(Wolf* sheep, Position* position, World* world)
	:Animal(sheep, position, world) {
}

Organism* Wolf::clone() {
	return new Wolf(this, nullptr, nullptr);
}

void Wolf::initialParameters() {
	setStrength(9);
	setInitiative(5);
	setAge(0);
	setSign('W');
	setName(new std::string("Wolf"));
}