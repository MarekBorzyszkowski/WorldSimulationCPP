#include "Human.h"
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Human::Human(Human* human, Position* position, World* world) 
	:Animal(human, position, world){
	initialParameters();
}


std::vector<Action> Human::move() {
    inspectStrength();
    getAction();
    if (whatToDo != SPECIAL) {
        std::vector<Action> result;
        std::vector<Action> pomVector;
        Position* newPosition = new Position(getPosition()->getX(), getPosition()->getY());
        int x, y;
        switch (whatToDo) {
        case UP: {
            x = newPosition->getX() - 1;
            newPosition->setX(x);
            break;
        }
        case DOWN: {
            x = newPosition->getX() + 1;
            newPosition->setX(x);
            break;
        }
        case LEFT: {
            y = newPosition->getY() - 1;
            newPosition->setY(y);
            break;
        }
        case RIGHT: {
            y = newPosition->getY() + 1;
            newPosition->setY(y);
            break;
        }
        }
        if (getWorld()->positionOnBoard(newPosition)) {
            result.push_back(Action(MOVE, 0, newPosition, this));
            setLastPosition(getPosition());
            Organism* metOrganism = getWorld()->getOrganismFromPosition(*newPosition);
            if (metOrganism != nullptr) {
                pomVector = metOrganism->collision(this);
                result.insert(std::end(result), std::begin(pomVector), std::end(pomVector));
            }
        }
        return result;
    }
    return std::vector<Action>();
}
std::vector<Action> Human::action() {
    if (whatToDo == SPECIAL) {
        std::vector<Action> result;
        if (getStrength() <= 10) {
            strengthIncreased = 10 - baseStrength;
            result.push_back(Action(INCREASEPOWER, strengthIncreased, getPosition(), this));
        }
        turnsToUseSpecial = 10;
        canUseSpecial = false;
        return result;
    }
    return std::vector<Action>();
}

std::vector<Action> Human::reproduce() {
	return std::vector<Action>();
}

void Human::initialParameters() {
    baseStrength = 5;
    strengthIncreased = 0;
	setStrength(5);
	setInitiative(4);
	setAge(0);
	setSign('H');
	setName("Human");
	whatToDo = 0;
	turnsToUseSpecial = 0;
	specialKeyActivation = 's';
	canUseSpecial = true;
}

Organism* Human::clone() {
	return new Human(this, nullptr, world);
}

void Human::getAction() {
    int c;
    while (1) {
        c = 0;
        switch ((c = _getch())) {
        case 224: {
            switch ((c = _getch())) {
                case KEY_UP: {
                    whatToDo = UP;
                    return;
                }
                case KEY_DOWN: {
                    whatToDo = DOWN;
                    return;
                }
                case KEY_LEFT: {
                    whatToDo = LEFT;
                    return;
                }
                case KEY_RIGHT: {
                    whatToDo = RIGHT;
                    return;
                }
                default: {
                    break;
                }
            }
            break;
        }
        case 's': {
            if (canUseSpecial) {
                whatToDo = SPECIAL;
                return;
            }
            std::cout << "You must wait " << turnsToUseSpecial << " turns to use special ability.\n";
            break;
        }
        default:
            break;
        }

    }
}

void Human::inspectStrength() {//TODO check logic in this method
    if (canUseSpecial && baseStrength != getStrength()) {
        baseStrength = getStrength();
        return;
    }
    else if (canUseSpecial) return;
    else if (strengthIncreased ==0 && baseStrength != getStrength()) {
        baseStrength = getStrength();
    }
    else if (baseStrength+strengthIncreased != getStrength()
        && baseStrength>getStrength()) {
        baseStrength += getStrength() - strengthIncreased;
    }
    if (strengthIncreased > 0) {
        strengthIncreased--;
        setStrength(getStrength() - 1);
    }
    if (turnsToUseSpecial > 1) {
        turnsToUseSpecial--;
    }
    else if (turnsToUseSpecial == 1) {
        turnsToUseSpecial = 0;
        canUseSpecial = true;
    }
}

