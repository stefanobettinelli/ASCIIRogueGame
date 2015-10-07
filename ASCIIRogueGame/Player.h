#pragma once
#include "Position.h"
#include "Character.h"
#include <iostream>

using namespace std;

class Player: public Character{
public:
	Player();
	Player(char type,Position p, int level, int health ,int attack, int defence, int experience);
	virtual void addExerience(int exp);
	virtual int takeDamage(int dmg);
	virtual char move(int x, int y);
private:
};