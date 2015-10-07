#pragma once
#include <string>
#include "Player.h"
#include "Level.h"

using namespace std;

class GameManager{
public:
	GameManager(string);
	void startGame();
	static int LevelWidth() { return levelWidth; }
	static int LevelHiegth() { return levelHeigth; }
	static char characterAt(int x, int y) { return _level.getTile(x, y); }
private:
	void getCharacterMovement(Character &character);
	void updateGame(int x, int y, char tile, Character &character);
	bool monsterFight(int index);
	int getMonsterIndexAtPosition(int posX, int posY);

	Player _player;
	static Level _level;
	vector<Enemy> _enemies;
	static int levelWidth;
	static int levelHeigth;
};
