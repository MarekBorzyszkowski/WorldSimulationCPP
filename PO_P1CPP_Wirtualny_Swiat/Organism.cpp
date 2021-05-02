#include "Organism.h"

class Action;

Organism::Organism(Organism* organism, Position* position, World* world) {
	strength = NULL;
	initiative = NULL;
	age = NULL;
	sign = NULL;
	name = nullptr;
	position = nullptr;
	world = nullptr; 
	if (organism != nullptr) {
		strength = organism->getStrength();
		initiative = organism->getInitiative();
		age = organism->getAge();
		sign = organism->getSign();
		name = organism->getName();
		position = organism->getPosition();
		world = organism->getWorld();
	}
	else {
		if (position != nullptr) {
			this->position = position;
		}
		if (world != nullptr) {
			this->world = world;
		}
		//initialParameters();
	}
}

int Organism::getStrength() const {
	return strength;
}
int Organism::getInitiative() const {
	return initiative;
}
int Organism::getAge() const {
	return age;
}
char Organism::getSign() const {
	return sign;
}
std::string* Organism::getName() const {
	return name;
}
Position* Organism::getPosition() const {
	return position;
}
World* Organism::getWorld() const {
	return world;
}

void Organism::setStrength(int s) {
	strength = s;
}
void Organism::setInitiative(int i) {
	initiative = i;
}
void Organism::setAge(int a) {
	age = a;
}
void Organism::setSign(char s) {
	sign = s;
}
void Organism::setName(std::string* n) {
	name = n;
}
void Organism::setPosition(Position* p) {
	position = p;
}
void Organism::setWorld(World* w) {
	world = w;
}

Action Organism::collision(Organism* atackingOrganism) {
	return Action(0, 0, new Position(0, 0), atackingOrganism);
}

std::ostream& operator<<(std::ostream& os, const Organism& organism) {
	os << "Organism{ name: " << organism.getName()
		<< ", strength: " << organism.getStrength()
		<< ", initiative: " << organism.getInitiative()
		<< ", age: " << organism.getAge()
		<< ", " << organism.getPosition();
	return os;
}

Organism::~Organism() {
}