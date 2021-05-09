#ifndef WB_H
#define WB_H

#include "Plant.h"

class Wberry : public Plant {
private:
	Organism* clone() override;
public:
	Wberry(Wberry*, Position*, World*);
	void initialParameters() override;
	std::vector<Action> collision(Organism*) override;
};

#endif