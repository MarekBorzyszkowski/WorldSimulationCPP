#include "Human.h"
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Human::Human(Human* human, Position* position, World* world) 
	:Organism(human, position, world){
	initialParameters();
}


std::vector<Action> Human::move() {
    getAction();
    if (whatToDo != SPECIAL) {
        //check if can move to direction
    }
    return std::vector<Action>();
}
std::vector<Action> Human::action() {
    if (whatToDo == SPECIAL) {
        // DO
    }
    return std::vector<Action>();
}

std::vector<Action> Human::reproduce() {
	return std::vector<Action>();
}

void Human::initialParameters() {
	setStrength(5);
	setInitiative(4);
	setAge(0);
	setSign('H');
	setName("Human");
	whatToDo = 0;
	timeToUseSpecial = 0;
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
            std::cout << "You must wait " << timeToUseSpecial << " turns to move.\n";
            break;
        }
        default:
            break;
        }

    }
}

/*
	std::vector<Action> move() override;
	std::vector<Action> action() override;
	std::vector<Action> reproduce() override;*/