#pragma once

class Position{
public:
	Position();
	Position(int x, int y);

	int getXCoord() const;
	int getYCoord() const;
	void setXCoord(int x);
	void setYCoord(int y);
	void setPosition(int x, int y);
private:
	int _x;
	int _y;
};