#include "Antelope.h"

Antelope::Antelope(Antelope* antelope, Position* position, World* world)
	:Animal(antelope, position, world) {
	initialParameters();
}

Organism* Antelope::clone() {
	return new Antelope(this, nullptr, nullptr);
}

void Antelope::initialParameters() {
	setStrength(4);
	setInitiative(4);
	setAge(0);
	setSign('A');
	setName("Antelope");
}

std::vector<Action> Antelope::collision(Organism* atackingOrganism) {
	int randomNum = rand() % 2;
	std::vector<Action> result;
	if (randomNum == 0) {
		std::vector<Position> positionToRun = getWorld()
			->filterPositionsWithOtherSpecies(Animal::getNeighboringPositions());
		if (positionToRun.size() == 0) {
			result = Animal::collision(atackingOrganism);
		}
		else {
			randomNum = rand() % positionToRun.size();
			result.push_back(Action(MOVE, 0, new Position(positionToRun[randomNum]), this));
		}
	}
	else {
		result = Animal::collision(atackingOrganism);
	}
	return result;
}

std::vector<Position> Antelope::getNeighboringPositions() {
	std::vector<Position> result;
	Position currPosition = *getPosition();
	Position positionToCheck;
	for (int x = -2; x < 3; x++) {
		for (int y = -2; y < 3; y++) {
			positionToCheck = Position(currPosition.getX() + x, currPosition.getY() + y);
			if (getWorld()->positionOnBoard(&positionToCheck) && (y != 0 || x != 0)) {
				result.push_back(positionToCheck);
			}
		}
	}
	return result;
}