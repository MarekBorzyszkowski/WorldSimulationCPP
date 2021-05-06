#ifndef P_H
#define P_H


#include"Organism.h"

class Plant : public Organism {
protected:
	int growthRate;
public:
	Plant(Plant*, Position*, World*);

	std::vector<Action> move() override;
	virtual std::vector<Action> action() override;
	std::vector<Action> reproduce() override;
	std::vector<Position> getNeighboringPositions();
};

#endif