#ifndef SP_H
#define SP_H

#include "Animal.h"

class Sheep : public Animal {
private:
	Organism* clone() override;
public:
	Sheep(Sheep*, Position*, World*);
	void initialParameters() override;

};

#endif