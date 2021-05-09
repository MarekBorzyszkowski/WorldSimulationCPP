#ifndef AL_H
#define AL_H

#include "Animal.h"

class Antelope : public Animal {
private:
	Organism* clone() override;
	std::vector<Position> getNeighboringPositions() override;
public:
	Antelope(Antelope*, Position*, World*);
	void initialParameters() override;
	std::vector<Action> collision(Organism*) override; 
};

#endif