#include "Position.h"

Position::Position() : x(0), y(0) {}
Position::Position(int x, int y) : x(x), y(y) {}

std::ostream& operator<<(std::ostream& os, const Position& position) {
	os << "positon {x: " << position.getX()
		<< ", y: " << position.getY() << "}";
	return os;
}

int Position::getX() const {
	return x;
}
int Position::getY() const {
	return y;
}

void Position::setX(int x) {
	this->x = x;
}
void Position::setY(int y) {
	this->y = y;
}

bool Position::isThisPositionEqualTo(Position p) {
	return (p.getX() == x && p.getY() == y) ? true : false;
}