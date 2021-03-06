#include "Animal.h"

Animal::Animal(Animal* animal, Position* position, World* world)
	: Organism(animal, position, world) {
	canReproduce = false;
}


std::vector<Action> Animal::move() {
	std::vector<Action> result;
	std::vector<Action> pomVector;
	std::vector<Position> pomPositions = getNeighboringPositions();
	Position* newPosition;
	int placeIndex;
	if (pomPositions.size() > 0) {
		placeIndex = rand() % pomPositions.size();
		newPosition = new Position(pomPositions[placeIndex].getX(), pomPositions[placeIndex].getY());
		Organism* metOrganism = getWorld()->getOrganismFromPosition(*newPosition);
		if (metOrganism != nullptr) {
			if (metOrganism->getName() == getName()) {
				canReproduce = true;
			}
			else {
				result.push_back(Action(MOVE, 0, newPosition, this));
				pomVector = metOrganism->collision(this);
			}
			result.insert(std::end(result), std::begin(pomVector), std::end(pomVector));
		}
		else {
			result.push_back(Action(MOVE, 0, newPosition, this));
		}
	}
	newPosition = nullptr;
	return result;
}
std::vector<Action> Animal::action() {
	if (canReproduce) {
		canReproduce = false;
		return reproduce();
	}
	return std::vector<Action>();
}

std::vector<Action> Animal::reproduce() {
	std::vector<Action> result;
	Organism* newAnimal;
	std::vector<Position> birthPlace = getNeighboringBirthPositions();
	int placeIndex;
	if (birthPlace.size() > 0) {
		newAnimal = clone();
		placeIndex = rand() % birthPlace.size();
		newAnimal->initialParameters();
		newAnimal->setPosition(new Position(birthPlace[placeIndex].getX(), birthPlace[placeIndex].getY()));
		result.push_back(Action(ADD, 0, newAnimal->getPosition(), newAnimal));
	}
	newAnimal = nullptr;
	return result;
}

std::vector<Position> Animal::getNeighboringPositions() {
	return getWorld()->getNeighboringPositions(*getPosition());
}
std::vector<Position> Animal::getNeighboringBirthPositions() {
	return getWorld()->filterFreePositions(getWorld()->getNeighboringPositions(*getPosition()));
}