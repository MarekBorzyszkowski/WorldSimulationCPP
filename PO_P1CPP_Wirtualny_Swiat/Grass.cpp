#include "Grass.h"

Grass::Grass(Grass* grass, Position* position, World* world)
	:Plant(grass, position, world) {
	initialParameters();
}

Organism* Grass::clone() {
	return new Grass(this, nullptr, nullptr);
}

void Grass::initialParameters() {
	setStrength(0);
	setInitiative(0);
	setAge(0);
	setSign('G');
	setName("Grass");
}