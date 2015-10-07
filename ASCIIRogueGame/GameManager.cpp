#include "GameManager.h"
#include <iostream>
#include <conio.h>

using namespace std;

int GameManager::levelHeigth = 0;
int GameManager::levelWidth = 0;
Level GameManager::_level;

GameManager::GameManager(string levelFile){
	_player = Player('P', Position(0,0),1,100,10,10,0);
	_level.loadLevel(levelFile, _player, _enemies);
	levelHeigth = _level.getHeigth();
	levelWidth = _level.getWidth();
}

void GameManager::startGame(){
	bool exitGame = false;
	//game loop
	while (!exitGame) {
		if (this->_player.getHealth() <= 0) {
			_player.setSymbol('x');
			_level.setTile(_player.getPosition().getXCoord(), _player.getPosition().getYCoord(), _player.getSymbol());
			cout << "Game Over: You Died!" << endl;
			_level.print();
			system("PAUSE");
			exit(0);
		}
		_level.print();
		printf("\nHP: %d, DEF: %d, ATK: %d\n\n", _player.getHealth(), _player.getDefence(), _player.getAttack());
		getCharacterMovement(this->_player);
		for (size_t i = 0, len = this->_enemies.size(); i < len; ++i) {
			getCharacterMovement(this->_enemies[i]);
		}
	}
}


void GameManager::getCharacterMovement(Character &character){
	char input;
	int charPosX = character.getPosition().getXCoord();
	int charPosY = character.getPosition().getYCoord();

	if (character.getType() == 'P') {
		input = _getch();
	}
	else {//get enemy movement
		int playerXPos = this->_player.getPosition().getXCoord();
		int playerYPos = this->_player.getPosition().getYCoord();
		input = character.move(playerXPos,playerYPos);
	}

	char targetTile;
	switch (input) {
	case 'w':
		targetTile = _level.getTile(charPosX, charPosY -1);
		updateGame(charPosX, charPosY -1, targetTile, character);
		break;
	case 's':
		targetTile = _level.getTile(charPosX, charPosY +1);
		updateGame(charPosX, charPosY +1, targetTile, character);
		break;
	case 'd':
		targetTile = _level.getTile(charPosX +1, charPosY);
		updateGame(charPosX +1, charPosY, targetTile, character);
		break;
	case 'a':
		targetTile = _level.getTile(charPosX -1, charPosY);
		updateGame(charPosX -1, charPosY, targetTile, character);
		break;
	default:
		cout << "INVALID INPUT" << endl;
		system("PAUSE");
		break;
	}
}

void GameManager::updateGame(int targetX, int targetY, char moveTile, Character &character){
	int charPosX = character.getPosition().getXCoord();
	int charPosY = character.getPosition().getYCoord();
	int index = 0;
	switch(moveTile){
	case '.':
		character.move(targetX, targetY);
		_level.setTile(targetX, targetY, character.getSymbol());
		_level.setTile(charPosX, charPosY, '.');
		if (character.getType() == 'M') {//update monster position in the game manager vector _enemies										 
			this->_player.takeDamage(character.attack());
			index = this->getMonsterIndexAtPosition(charPosX, charPosY);
			this->_enemies[index].setPosition(targetX, targetY);
		}
		break;
	case '#': case '@'://monster and player can't go over '#' and mosters can't go over '@' 
		break;
	case 's': case 'g': case 'b': case 'O': case 'D':
		if (character.getType() == 'P') {//only player can engage in battle other monsters
			index = this->getMonsterIndexAtPosition(targetX, targetY);
			if (index >= 0) {
				if (this->monsterFight(index)) {
					_level.setTile(targetX, targetY, '.');
					this->_enemies.erase(_enemies.begin() + index);					
					cout << "Monster died!" << endl;
				}
			}
			else {
				perror("\nCould not find enemy in the game manager vector. Exiting the game");
				system("PAUSE");
				exit(1);
			}
		}
		break;
	default:
		perror("This type of tile does not exist! Exiting program!");
		system("PAUSE");
		exit(1);
		break;
	}
}

bool GameManager::monsterFight(int index){
	int attackResult = this->_player.attack();
	int exp = this->_enemies[index].takeDamage(attackResult);//exp = 0 if mob survives the attack
	if (exp > 0) {
		this->_player.addExerience(exp);
		return true;
	}
	else {//if monster survives, he attacks the player too
		attackResult = this->_enemies[index].attack();
		this->_player.takeDamage(attackResult);
		return false;
	}
}

int GameManager::getMonsterIndexAtPosition(int posX, int posY) {
	int x;
	int y;
	for (size_t i = 0, enemyNo = this->_enemies.size(); i < enemyNo; ++i) {
		x = this->_enemies[i].getPosition().getXCoord();
		y = this->_enemies[i].getPosition().getYCoord();
		if (x == posX && y == posY) {
			return i;
		}
	}
	return -1;
}
