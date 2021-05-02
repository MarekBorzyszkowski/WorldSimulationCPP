#ifndef A_H
#define A_H
#include "Organism.h"

class Animal : public Organism {
public:
	void action() override;
	//void collision() override;
};

#endif