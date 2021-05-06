#ifndef GR_H
#define GR_H

#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana(Guarana*, Position*, World*);
	Organism* clone() override;
	void initialParameters() override;
	std::vector<Action> collision(Organism*) override;
};

#endif