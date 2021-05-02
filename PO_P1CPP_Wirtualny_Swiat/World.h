#ifndef W_H
#define W_H

class Organism;

#include "Organism.h"

class World {
private:
	int xLength;
	int yLength;
	int turn;
	std::vector<Organism> organisms;
	std::vector<Organism> newOrganisms;
	bool sortOrganisms(Organism&, Organism&);
public:
	World(int, int);

	int getXLength() const;
	int getYLength() const;
	int getTurn() const;
	std::vector<Organism> getOrganisms() const;
	std::vector<Organism> getNewOrganisms() const;

	void setTurn(int);
	void setOrganisms(std::vector<Organism>);
	void setNewOrganisms(std::vector<Organism>);

	void makeTurn();

	void makeMove(Action);

	bool addOrganism(Organism&);
	bool positionOnBoard(Position*);

	Organism* getOrganismFromPosition(Position);

	Position* getNeighboringPositions(Position);

	std::vector<Position> filterFreePositions(std::vector<Position>);

	std::vector<Position> filterPositionsWithoutAnimals(std::vector<Position>);
	
	std::vector<Position> filterPositionsWithOtherSpecies(std::vector<Position>);


};

#endif

