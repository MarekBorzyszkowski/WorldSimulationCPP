#include "Sonchus.h"

Sonchus::Sonchus(Sonchus* sonchus, Position* position, World* world)
	:Plant(sonchus, position, world) {
	initialParameters();
}

Organism* Sonchus::clone() {
	return new Sonchus(this, nullptr, nullptr);
}

void Sonchus::initialParameters() {
	setStrength(0);
	setInitiative(0);
	setAge(0);
	setSign('G');
	setName("Sonchus");
	growthRate = 3;
}