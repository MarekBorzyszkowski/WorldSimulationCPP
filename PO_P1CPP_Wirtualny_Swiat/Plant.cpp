#include "Plant.h"

Plant::Plant(Plant* plant, Position* position, World* world)
	:Organism(plant, position, world) {}

std::vector<Action> Plant::move() {
	return std::vector<Action>();
}

std::vector<Action> Plant::action() {
	return reproduce();
}

std::vector<Action> Plant::reproduce() {
	std::vector<Action> result;
	std::vector<Position> pomPositions = getFreeNeighboringPositions();
	Organism* newPlant;
	Position* newPosition;
	int placeIndex; 
	if (pomPositions.size() > 0) {
		placeIndex = rand() % pomPositions.size();
		newPosition = new Position(pomPositions[placeIndex].getX(), pomPositions[placeIndex].getY());
		newPlant = clone();
		newPlant->initialParameters();
		newPlant->setPosition(newPosition);
		result.push_back(Action(ADD, 0, newPlant->getPosition(), newPlant));
	}
	return result;
}

std::vector<Position> Plant::getFreeNeighboringPositions() {
	return getWorld()->filterFreePositions(getWorld()->getNeighboringPositions(*getPosition()));
}

/*Plant(Organism*, Position*, World*);

	std::vector<Action> move() override;
	std::vector<Action> action() override;
	std::vector<Action> reproduce() override;
	std::vector<Position> getFreeNeighboringPositions();*/