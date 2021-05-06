#include "Wolf.h"

Wolf::Wolf(Wolf* wolf, Position* position, World* world)
	:Animal(wolf, position, world) {
	initialParameters();
}

Organism* Wolf::clone() {
	return new Wolf(this, nullptr, nullptr);
}

void Wolf::initialParameters() {
	setStrength(9);
	setInitiative(5);
	setAge(0);
	setSign('W');
	setName("Wolf");
}