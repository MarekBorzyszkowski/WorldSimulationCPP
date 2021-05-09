#include "Turtle.h"

Turtle::Turtle(Turtle* turtle, Position* position, World* world)
	:Animal(turtle, position, world) {
	initialParameters();
}

Organism* Turtle::clone() {
	return new Turtle(this, nullptr, nullptr);
}

void Turtle::initialParameters() {
	setStrength(2);
	setInitiative(1);
	setAge(0);
	setSign('T');
	setName("Turtle");
}

std::vector<Action> Turtle::move() {
	int randomNum = rand() % 4;
	if (randomNum == 0) {
		return Animal::move();
	}
	return std::vector<Action>();
}

std::vector<Action> Turtle::collision(Organism* atackingOrganism) {
	std::vector<Action> result;
	if (atackingOrganism->getStrength() < 5) {
		Position* lastOrgPosition = new Position(atackingOrganism->getPosition()->getX(),
			atackingOrganism->getPosition()->getY());
		result.push_back(Action(MOVE, 0, lastOrgPosition, atackingOrganism));

	}
	else if (this->getStrength() > atackingOrganism->getStrength()) {
		result.push_back(Action(REMOVE, 0, getPosition(), atackingOrganism));
	}
	else {
		result.push_back(Action(REMOVE, 0, getPosition(), this));
	}
	return result;
}