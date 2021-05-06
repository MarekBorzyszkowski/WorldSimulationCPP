#ifndef GS_H
#define GS_H

#include "Plant.h"

class Grass : public Plant {
public:
	Grass(Grass*, Position*, World*);
	Organism* clone() override;
	void initialParameters() override;
};

#endif