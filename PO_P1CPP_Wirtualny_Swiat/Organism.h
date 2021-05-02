#ifndef O_H
#define O_H

class Action;
class World;

#include "Action.h"
#include "Position.h"
#include "World.h"
#include <string>
#include <vector>

class Organism {
protected:
	int strength;
	int initiative;
	int age;
	char sign;
	std::string* name;
	Position* position;
	World* world;

	friend std::ostream& operator<<(std::ostream&, const Organism&);

public:
	Organism(Organism*, Position*, World*);

	int getStrength() const;
	int getInitiative() const;
	int getAge() const;
	char getSign() const;
	std::string* getName() const;
	Position* getPosition() const;
	World* getWorld() const;

	void setStrength(int);
	void setInitiative(int);
	void setAge(int);
	void setSign(char);	
	void setName(std::string*);
	void setPosition(Position*);
	void setWorld(World*);

	virtual std::vector<Action> move() = 0;
	virtual std::vector<Action> action() = 0;
	virtual void initialParameters() = 0;
	virtual Organism clone() = 0;
	Action collision(Organism*);

	virtual ~Organism();
};

#endif