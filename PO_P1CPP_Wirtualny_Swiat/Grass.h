#ifndef GS_H
#define GS_H

#include "Plant.h"

class Grass : public Plant {
private:
	Organism* clone() override;
public:
	Grass(Grass*, Position*, World*);
	void initialParameters() override;
};

#endif