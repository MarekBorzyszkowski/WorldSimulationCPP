#ifndef G_H
#define G_H

class World;
class Organism;
class Animal;
class Plant;
class Action;

#include "Antelope.h"
#include "Fox.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Wolf.h"
#include "Human.h"
#include "Borscht.h"
#include "Grass.h"
#include "Guarana.h"
#include "Sonchus.h"
#include "Wberry.h"
#include <fstream>

class Game  {
public:
	void load(World& world);
	void setUpWorld(World* world);
};

#endif