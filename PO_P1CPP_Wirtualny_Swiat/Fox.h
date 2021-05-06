#ifndef FX_H
#define FX_H

#include "Animal.h"

class Fox : public Animal {
public:
	Fox(Fox*, Position*, World*);
	Organism* clone() override;
	void initialParameters() override;
	std::vector<Position> getNeighboringPositions() override;
	};

#endif