#ifndef AC_H
#define AC_H

class Organism;
class World;

#include "Organism.h"
#include "Position.h"


#define ADD 0
#define REMOVE 1
#define MOVE 2
#define INCREASEPOWER 3

class Action {
private:
	int action;
	int value;
	Position* position;
	Organism* organism;
	friend std::ostream& operator<<(std::ostream&, const Action&);

public:
	Action(int, int, Position*, Organism*);

	int getAction() const;
	int getValue() const;
	Position* getPositon() const;
	Organism* getOrganism() const;


};

#endif