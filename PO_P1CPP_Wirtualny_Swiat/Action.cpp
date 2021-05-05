#include "Action.h"
//#define ADD 0
//#define REMOVE 1
//#define MOVE 2
//#define INCREASEPOWER 3

std::ostream& operator<<(std::ostream& os, const Action& action) {
	switch (action.getAction()) {
	case 0: {
		os << action.getOrganism()->getName()
			<< " add at: " << action.getPositon();
		break;
	}
	case 1: {
		os << action.getOrganism()->getName()
			<< " remove from: " << action.getOrganism()->getPosition();
		break;
	}
	case 2: {
		os << action.getOrganism()->getName()
			<< " move from: " << action.getOrganism()->getPosition()
			<< " to: " << action.getPositon();
		break;
	}
	case 3: {
		os << action.getOrganism()->getName()
			<< " increase power: " << action.getValue();
		break;
	}
	}
	return os;
}

Action::Action(int action, int value,
	Position* position, Organism* organism)
	:action(action),
	value(value),
	position(position),
	organism(organism) {}

int Action::getAction() const {
	return action;
}
int Action::getValue() const {
	return value;
}
Position* Action::getPositon() const {
	return position;
}
Organism* Action::getOrganism() const {
	return organism;
}