#pragma once
#include "Position.h"
#include <random>
#include <ctime>

using namespace std;

class Character
{
public:
	Character(char type, Position p, int level, int health, int attack, int defence, int experience);
	virtual void setSymbol(char s);
	virtual char getSymbol() const;
	virtual int getLevel() const;
	virtual void setLevel(int level);
	virtual int getAttack() const;
	virtual void setAttack(int attack);
	virtual int getDefence() const;
	virtual void setDefence(int defence);
	virtual void setHealth(int health);
	virtual int getHealth() const;
	virtual int getExperience() const;
	virtual void setExperience(int exp);
	virtual void addExerience(int exp);
	virtual const Position & getPosition() const;
	virtual void setPosition(Position p);
	virtual void setPosition(int x, int y);
	virtual char move(int x, int y) = 0;
	virtual void setType(char type);
	virtual char getType();
	virtual int attack();
	virtual int takeDamage(int dmg);

private:
	Position _position;
	int _health;
	int _level;
	int _attack;
	int _defence;
	int _experience;
	char _symbol;
	char _type;
};

