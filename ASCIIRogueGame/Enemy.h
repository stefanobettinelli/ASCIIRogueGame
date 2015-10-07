#pragma once
#include "Position.h"
#include "Character.h"
#include <string>

using namespace std;

class Enemy: public Character {
public:
	Enemy();
	Enemy(char type,Position p, int level ,string name, char s, int att, int def, int hp, int exp);
	virtual int takeDamage(int dmg);
	virtual char move(int x, int y);
	virtual int attack();
private:
	string _name;
	char _symbol;
	//vector<Item> _dropItems;
};

