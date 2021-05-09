#ifndef BT_H
#define BT_H

#include "Plant.h"

class Borscht : public Plant {
private:
	Organism* clone() override;
public:
	Borscht(Borscht*, Position*, World*);
	void initialParameters() override;
	std::vector<Action> action() override;
	std::vector<Action> collision(Organism*) override;
};

#endif