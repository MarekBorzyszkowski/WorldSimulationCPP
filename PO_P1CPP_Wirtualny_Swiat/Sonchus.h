#ifndef SS_H
#define SS_H

#include "Plant.h"

class Sonchus : public Plant {
public:
	Sonchus(Sonchus*, Position*, World*);
	Organism* clone() override;
	void initialParameters() override;
};

#endif