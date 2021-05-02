#include"Organism.h"
#ifndef P_H
#define P_H

class Plant : public Organism {
public:
	void action() override;
	//void collision() override;
};

#endif