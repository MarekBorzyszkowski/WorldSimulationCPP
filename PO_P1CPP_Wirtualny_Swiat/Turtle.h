#include "Animal.h"
#ifndef TT_H
#define TT_H
class Turtle : public Animal{
public:
	Turtle(Turtle*, Position*, World*);
	Organism* clone() override;
	void initialParameters() override;
	std::vector<Action> move() override;
	std::vector<Action> collision(Organism*) override;
};
#endif