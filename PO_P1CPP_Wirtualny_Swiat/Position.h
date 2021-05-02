#ifndef XY_H
#define XY_H

#include <iostream>

class Position {
private:
	int x, y;
	friend std::ostream& operator<<(std::ostream&, const Position&);
public:
	Position();
	Position(int, int);
	
	int getX() const;
	int getY() const;

	void setX(int);
	void setY(int);

	bool isThisPositionEqualTo(Position);
};

#endif