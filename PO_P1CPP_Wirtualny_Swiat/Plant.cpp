#include "Plant.h"

Plant::Plant(Plant* plant, Position* position, World* world)
	:Organism(plant, position, world) {
	growthRate = 1;
}

std::vector<Action> Plant::move() {
	return std::vector<Action>();
}

std::vector<Action> Plant::action() {
	return reproduce();
}

std::vector<Action> Plant::reproduce() {
	std::vector<Action> result;
	std::vector<Position> pomPositions = getNeighboringPositions();
	Organism* newPlant;
	Position* newPosition;
	int placeIndex; 
	for (int i = 0; i < growthRate && pomPositions.size()>0; i++) {
		placeIndex = rand() % pomPositions.size();
		newPosition = new Position(pomPositions[placeIndex].getX(), pomPositions[placeIndex].getY());
		if (!getWorld()->getOrganismFromPosition(*newPosition)) {
			newPlant = clone();
			newPlant->initialParameters();
			newPlant->setPosition(newPosition);
			result.push_back(Action(ADD, 0, newPlant->getPosition(), newPlant));
			pomPositions.erase(std::begin(pomPositions) + placeIndex);
		}
	}
	newPlant = nullptr;
	newPosition = nullptr;
	return result;
}

std::vector<Position> Plant::getNeighboringPositions() {
	return getWorld()->getNeighboringPositions(*getPosition());
}
