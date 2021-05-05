#include"Organism.h"
#ifndef P_H
#define P_H

class Plant : public Organism {
public:
	Plant(Plant*, Position*, World*);

	std::vector<Action> move() override;
	std::vector<Action> action() override;
	std::vector<Action> reproduce() override;
	std::vector<Position> getFreeNeighboringPositions();
};

#endif