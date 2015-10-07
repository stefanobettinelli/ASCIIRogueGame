#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Level
{
public:
	Level();
	void loadLevel(string fileName, Player &player, vector<Enemy> &enemy_v);
	void print();
	char getTile(int x, int y) const;
	void setTile(int x, int y, char tile);
	int getWidth();
	int getHeigth();
	void setWidth(int w);
	void setHeigth(int h);
private:
	vector<string> _levelData;
	int _width;
	int _heigth;
};

