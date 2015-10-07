#include "Enemy.h"
#include "GameManager.h"
#include <iostream>

using namespace std;

Enemy::Enemy() : Enemy('M',Position(0, 0), 0,"",'E',0, 0, 0, 0) {
}

Enemy::Enemy(char type,Position p, int level ,string name, char s, int attack, int defence, int health, int experience) :
Character('M',p, level ,health, attack, defence, experience)
{
	this->_name = name;
	Character::setSymbol(s);
}

int Enemy::takeDamage(int dmg)
{
	cout << "Monster: " << this->getSymbol() << " taking " << dmg << " damage" << endl;
	return Character::takeDamage(dmg);
}

char Enemy::move(int x, int y){
	static default_random_engine randomEngine((unsigned int)time(NULL));
	uniform_int_distribution<int> moveRoll(0, 4);

	int dx = this->getPosition().getXCoord() - x;
	int dy = this->getPosition().getYCoord() - y;
	int adx = abs(dx);
	int ady = abs(dy);
	int distance = adx + ady;

	if (distance <= 5) {
		//moving along the X axis
		if (adx >= ady) {
			if (dx > 0) {
				return 'a';
			} else {
				return 'd';
			}
		} else {
			if (dy > 0) {
				return 'w';
			} else {
				return 's';
			}
		}
	}

	int randomMove = moveRoll(randomEngine);
	switch (randomMove)	{
	case 0:
		return 'a';
		break;
	case 1:
		return 'w';
		break;
	case 2:
		return 's';
		break;
	case 3:
		return 'd';
		break;
	default:
		return 'a';
		break;
	}

	return 0;
}

int Enemy::attack(){

	int damage = 0;
	int xPos = this->getPosition().getXCoord();
	int yPos = this->getPosition().getYCoord();
	char attackableTiles[] = {
		GameManager::characterAt(xPos - 1, yPos),
		GameManager::characterAt(xPos + 1, yPos),
		GameManager::characterAt(xPos, yPos - 1),
		GameManager::characterAt(xPos, yPos + 1),
		GameManager::characterAt(xPos - 1, yPos - 1),
		GameManager::characterAt(xPos + 1, yPos - 1),
		GameManager::characterAt(xPos - 1, yPos + 1),
		GameManager::characterAt(xPos + 1, yPos + 1)
	};

	if(xPos > 0 && xPos < GameManager::LevelWidth()-1 && yPos > 0 && yPos < GameManager::LevelHiegth() - 1) {
		for (size_t i = 0, len = sizeof(attackableTiles); i < len; i++) {
			switch (attackableTiles[i])
			{
			case '@':
				damage = Character::attack();
				break;
			default:
				break;
			}
		}
	}
	return damage;

}
