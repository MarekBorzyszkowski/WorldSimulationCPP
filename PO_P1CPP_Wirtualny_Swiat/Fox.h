#ifndef FX_H
#define FX_H

#include "Animal.h"

class Fox : public Animal {
private:
	Organism* clone() override;
	std::vector<Position> getNeighboringPositions() override;
public:
	Fox(Fox*, Position*, World*);
	void initialParameters() override;
};

#endif