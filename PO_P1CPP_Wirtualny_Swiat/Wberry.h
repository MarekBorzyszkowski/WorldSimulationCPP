#ifndef WB_H
#define WB_H

#include "Plant.h"

class Wberry : public Plant {
public:
	Wberry(Wberry*, Position*, World*);
	Organism* clone() override;
	void initialParameters() override;
	std::vector<Action> collision(Organism*) override;
};

#endif