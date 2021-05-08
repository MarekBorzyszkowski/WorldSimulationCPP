#ifndef W_H
#define W_H

class Organism;
class Action;

#include <vector>
#include "Position.h"
#include "Organism.h"
#include "Action.h"
#include <stdlib.h>
#include <time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SPECIAL 4

class World {
private:
	int xLength;
	int yLength;
	int turn;
	int whatToDo;
	char emptyPlace;
	std::vector<Organism*> organisms;
	std::vector<Organism*> newOrganisms;

	friend std::ostream& operator<<(std::ostream&, const World&);
public:
	World(int, int);

	int getXLength() const;
	int getYLength() const;
	int getTurn() const;
	char getEmptyPlace() const;
	std::vector<Organism*> getOrganisms() const;
	std::vector<Organism*> getNewOrganisms() const;

	void setTurn(int);
	void setOrganisms(std::vector<Organism*>);
	void setNewOrganisms(std::vector<Organism*>);

	void makeTurn();

	void makeMove(Action);

	void getAction();

	bool addOrganism(Organism*);
	bool positionOnBoard(Position*) const;

	Organism* getOrganismFromPosition(Position) const;

	std::vector<Position> getNeighboringPositions(Position) const;

	std::vector<Position> filterFreePositions(std::vector<Position>);

	std::vector<Position> filterPositionsWithoutAnimals(std::vector<Position>);
	
	std::vector<Position> filterPositionsWithOtherSpecies(std::vector<Position>);

};

#endif

