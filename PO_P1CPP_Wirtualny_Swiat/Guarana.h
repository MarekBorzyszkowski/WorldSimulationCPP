#ifndef GR_H
#define GR_H

#include "Plant.h"

class Guarana : public Plant {
private:
	Organism* clone() override;
public:
	Guarana(Guarana*, Position*, World*);
	void initialParameters() override;
	std::vector<Action> collision(Organism*) override;
};

#endif