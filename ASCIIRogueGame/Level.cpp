#include "Level.h"
#include "Position.h"
#include <fstream>
#include <iostream>

using namespace std;

Level::Level()
{
}

void Level::loadLevel(string fileName, Player &player, vector<Enemy> &enemy_v)
{
	//first load the level...
	ifstream file;
	file.open(fileName);
	if (file.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);//quit the whole game
	}

	string line;
	while (getline(file, line)) {
		_levelData.push_back(line);
	}

	file.close();

	//...and then process the level
	char tile;
	for (size_t i = 0, lvlHeight = _levelData.size(); i < lvlHeight; ++i) {
		for (size_t j = 0, lvlWidth = _levelData[i].size(); j < lvlWidth; ++j) {
			tile = _levelData[i][j];
			switch (tile) {
			case '@'://player
				player.setPosition(Position(j,i));
				break;
			case 's'://Snake
				enemy_v.push_back(Enemy('M',Position(j,i),1,"Snake", 's', 2, 5, 10, 10));
				break;
			case 'b'://Bandit
				enemy_v.push_back(Enemy('M',Position(j,i),3,"Bandit", 'b', 5, 7, 12, 13));
				break;
			case 'g'://goblin
				enemy_v.push_back(Enemy('M',Position(j,i),5,"Goblin", 'g', 6, 12, 30, 50));
				break;
			case 'D'://Dragon				
				enemy_v.push_back(Enemy('M',Position(j,i),100,"Dragon", 'D', 20, 20, 100, 100));
				break;
			case 'O'://Ogre
				enemy_v.push_back(Enemy('M',Position(j,i),60, "Ogre", 'O', 15, 15, 30, 50));
				break;
			default:
				//cout << "invalied tile" << endl;
				break;
			}
		}
	}
	_width = _levelData[0].length();
	_heigth = _levelData.size();
}

int Level::getWidth() {
	return _width;
}
int Level::getHeigth() {
	return _heigth;
}
void Level::setWidth(int w) {
	_width = w;
}
void Level::setHeigth(int h) {
	_heigth = h;
}

void Level::print()
{
	cout << string(100, '\n');
	for (size_t i = 0, lvlHeight = _levelData.size(); i < lvlHeight; ++i) {
		printf("%s\n",_levelData[i].c_str());
	}
	printf("\n");
}

char Level::getTile(int x, int y) const
{
	size_t u_x = x;
	size_t u_y = y;
	if (y < 0 || u_y >= _levelData.size() || x < 0 || u_x >= _levelData[y].size()) {
		perror("getTile: BAD COORDINATES");
		exit(1);
	}
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile)
{
	_levelData[y][x] = tile;
}
