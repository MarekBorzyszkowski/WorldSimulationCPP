#ifndef A_H
#define A_H
#include "Organism.h"

class Animal : public Organism {
protected:
	bool canReproduce;
	std::vector<Action> reproduce() override;
	virtual std::vector<Position> getNeighboringPositions();
	virtual std::vector<Position> getNeighboringBirthPositions();
public:
	Animal(Animal*, Position* , World* );

	virtual std::vector<Action> move() override;
	std::vector<Action> action() override;
};

#endif