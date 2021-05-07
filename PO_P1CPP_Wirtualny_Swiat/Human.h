#ifndef H_H
#define H_H

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SPECIAL 4

#include"Organism.h"

class Human : public Organism {
private:
	int whatToDo;
	int timeToUseSpecial;
	char specialKeyActivation;
	bool canUseSpecial;
public:
	Human(Human*, Position*, World*);
	std::vector<Action> move() override;
	std::vector<Action> action() override;
	std::vector<Action> reproduce() override;
	void initialParameters() override;
	Organism* clone() override;

	void getAction();

};

#endif