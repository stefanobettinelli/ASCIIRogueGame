#include "Position.h"

Position::Position() : _x(0), _y(0)
{}

Position::Position(int x, int y) : _x(x), _y(y)
{}

int Position::getXCoord() const
{
	return this->_x;
}

int Position::getYCoord() const
{
	return this->_y;
}

void Position::setXCoord(int x) {
	this->_x = x;
}

void Position::setYCoord(int y){
	this->_y = y;
}

void Position::setPosition(int x, int y)
{
	this->_x = x;
	this->_y = y;
}
