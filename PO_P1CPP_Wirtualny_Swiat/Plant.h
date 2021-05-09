#ifndef P_H
#define P_H


#include"Organism.h"

class Plant : public Organism {
protected:
	int growthRate; 
	std::vector<Action> reproduce() override;
	std::vector<Position> getNeighboringPositions();
public:
	Plant(Plant*, Position*, World*);

	std::vector<Action> move() override;
	virtual std::vector<Action> action() override;
};

#endif