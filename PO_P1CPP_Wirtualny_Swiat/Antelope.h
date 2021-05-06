#ifndef AL_H
#define AL_H

#include "Animal.h"

class Antelope : public Animal {
public:
	Antelope(Antelope*, Position*, World*);
	Organism* clone() override;
	void initialParameters() override;
	std::vector<Action> collision(Organism*) override; 
	std::vector<Position> getNeighboringPositions() override;
};

#endif