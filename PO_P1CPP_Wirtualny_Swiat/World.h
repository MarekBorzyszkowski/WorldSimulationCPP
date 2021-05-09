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
#define SAVE 5
#define ENDGAME 6

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
	int getWhatToDo() const;
	char getEmptyPlace() const;

	void setTurn(int);

	bool makeTurn();

	void makeMove(Action);

	void getAction();

	bool addOrganism(Organism*);
	bool positionOnBoard(Position*) const;

	Organism* getOrganismFromPosition(Position) const;

	std::vector<Position> getNeighboringPositions(Position) const;

	std::vector<Position> filterFreePositions(std::vector<Position>) const;

	std::vector<Position> filterPositionsWithoutAnimals(std::vector<Position>) const;
	
	std::vector<Position> filterPositionsWithOtherSpecies(std::vector<Position>) const;

	void save() const;

	void draw() const;

	void clear() const;
};

#endif

