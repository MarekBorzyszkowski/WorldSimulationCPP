#ifndef TT_H
#define TT_H

#include "Animal.h"

class Turtle : public Animal{
private:
	Organism* clone() override;
public:
	Turtle(Turtle*, Position*, World*);
	void initialParameters() override;
	std::vector<Action> move() override;
	std::vector<Action> collision(Organism*) override;
};
#endif