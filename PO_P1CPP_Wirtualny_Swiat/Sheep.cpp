#include "Sheep.h"

Sheep::Sheep(Sheep* sheep, Position* position, World* world)
	:Animal(sheep, position, world) {
}

Organism* Sheep::clone() {
	return new Sheep(this, nullptr, nullptr);
}

void Sheep::initialParameters() {
	setStrength(4);
	setInitiative(4);
	setAge(0);
	setSign('S');
	setName(new std::string("Sheep"));
}