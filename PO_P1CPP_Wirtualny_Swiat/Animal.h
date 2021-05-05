#ifndef A_H
#define A_H
#include "Organism.h"

class Animal : public Organism {
protected:
	Position* lastPosition;
public:
	Animal(Animal*, Position* , World* );

	Position* getLastPosition() const;

	void setLastPosition(Position*);

	virtual std::vector<Action> move() override;
	std::vector<Action> action() override;
	std::vector<Action> reproduce() override;
	virtual std::vector<Position> getNeighboringPositions();
	virtual std::vector<Position> getNeighboringBirthPositions();
};

#endif