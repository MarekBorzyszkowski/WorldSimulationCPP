#include "Game.h"

void Game::load(World& world) {
	std::string fileName;
	std::ifstream fileToRead;
	while (true) {
		std::cout << "Enter file name: ";
		std::cin >> fileName;
		fileToRead.open(fileName);
		if (fileToRead.good()) {
			break;
		}
		else {
			std::cout << "Bad file name, remember about extention(like .txt)";
		}
	}
	world.clear();
	int x, y;
	int turn;
	int howManyOrganisms;
	int strength, age;
	char animal;
	Position* position;
	fileToRead >> x >> y >> turn >> howManyOrganisms;
	world = World(x, y);
	world.setTurn(turn);
	Organism* org ;
	for (int i = 0; i < howManyOrganisms;i++) {
		fileToRead >> animal;
		switch (animal) {
		case 'A': {
			org = new Antelope(nullptr, nullptr, &world);
			break;
		}
		case 'F': {
			org = new Fox(nullptr, nullptr, &world);
			break;
		}
		case 'S': {
			org = new Sheep(nullptr, nullptr, &world);
			break;
		}
		case 'T': {
			org = new Turtle(nullptr, nullptr, &world);
			break;
		}
		case 'W': {
			org = new Wolf(nullptr, nullptr, &world);
			break;
		}
		case 'H': {
			org = new Human(nullptr, nullptr, &world);
			break;
		}
		case 'B': {
			org = new Borscht(nullptr, nullptr, &world);
			break;
		}
		case 'G': {
			org = new Grass(nullptr, nullptr, &world);
			break;
		}
		case '+': {
			org = new Guarana(nullptr, nullptr, &world);
			break;
		}
		case 'U': {
			org = new Sonchus(nullptr, nullptr, &world);
			break;
		}
		case 'R': {
			org = new Wberry(nullptr, nullptr, &world);
			break;
		}
		default: {
			return;
		}
		}
		fileToRead >> strength >> age >> x >> y;
		org->setStrength(strength);
		org->setAge(age);
		position = new Position(x, y);
		org->setPosition(position);
		world.addOrganism(org);
	}
	org = nullptr;
	position = nullptr;
	fileToRead.close();
}

void Game::setUpWorld(World* world) {
	std::vector<Position*> availblePositions;
	for (int x = 0; x < world->getXLength(); x++) {
		for (int y = 0; y < world->getYLength(); y++) {
			availblePositions.push_back(new Position(x, y));
		}
	}
	Organism* org;
	int positionsNumberLeft = availblePositions.size() / 3 - 1;
	if (positionsNumberLeft > 30) {
		positionsNumberLeft = 30;
	}
	int randomPlace = rand() % availblePositions.size();
	org = new Human(nullptr, availblePositions[randomPlace], world);
	availblePositions[randomPlace] = nullptr;
	availblePositions.erase(std::begin(availblePositions) + randomPlace);
	int organismIndex=0;
	world->addOrganism(org);
	while (positionsNumberLeft > 0) {
		randomPlace = rand() % availblePositions.size();
		positionsNumberLeft--;
		switch (organismIndex) {
		case 0: {
			org = new Antelope(nullptr, availblePositions[randomPlace], world);
			break;
		}
		case 1: {
			org = new Fox(nullptr, availblePositions[randomPlace], world);
			break;
		}
		case 2: {
			org = new Sheep(nullptr, availblePositions[randomPlace], world);
			break;
		}
		case 3: {
			org = new Turtle(nullptr, availblePositions[randomPlace], world);
			break;
		}
		case 4: {
			org = new Wolf(nullptr, availblePositions[randomPlace], world);
			break;
		}
		case 5: {
			org = new Borscht(nullptr, availblePositions[randomPlace], world);
			break;
		}
		case 6: {
			org = new Grass(nullptr, availblePositions[randomPlace], world);
			break;
		}
		case 7: {
			org = new Guarana(nullptr, availblePositions[randomPlace], world);
			break;
		}
		case 8: {
			org = new Sonchus(nullptr, availblePositions[randomPlace], world);
			break;
		}
		case 9: {
			org = new Wberry(nullptr, availblePositions[randomPlace], world);
			break;
		}
		default: {
			break;
		}
		}
		world->addOrganism(org);
		organismIndex++;
		organismIndex %= 10;
		availblePositions[randomPlace] = nullptr;
		availblePositions.erase(std::begin(availblePositions) + randomPlace);
	}
	org = nullptr;
}
