#ifndef SS_H
#define SS_H

#include "Plant.h"

class Sonchus : public Plant {
private:
	Organism* clone() override;
public:
	Sonchus(Sonchus*, Position*, World*);
	void initialParameters() override;
};

#endif