#ifndef BT_H
#define BT_H

#include "Plant.h"

class Borscht : public Plant {
public:
	Borscht(Borscht*, Position*, World*);
	Organism* clone() override;
	void initialParameters() override;
	std::vector<Action> action() override;
	std::vector<Action> collision(Organism*) override;
};

#endif