#include "Animal.h"
#ifndef SP_H
#define SP_H

class Sheep : public Animal {
public:
	Sheep(Sheep*, Position*, World*);
	Organism* clone() override;
	void initialParameters() override;

};

#endif