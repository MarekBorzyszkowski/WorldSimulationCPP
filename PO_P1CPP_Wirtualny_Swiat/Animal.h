#ifndef A_H
#define A_H
#include "Organism.h"

class Animal : public Organism {
protected:
	Position* lastPosition;
public:
	Animal(Animal*, Position* , World* );

	Position* getLastPosition() const;

	void setLastPosition(Position*);

	std::vector<Action> move() override;
	std::vector<Action> action() override;
	//void collision() override;
};

#endif