#include "Player.h"

Player::Player() : Player('M',Position(0,0), 0, 0, 0, 0, 0){
}

Player::Player(char type,Position p, int level, int health, int attack, int defence, int experience) : 
Character('P',p, level, health, attack, defence, experience)
{
	this->setSymbol('@');
}

void Player::addExerience(int exp){
	Character::addExerience(exp);
	int currentExp = this->getExperience();
	if ((currentExp % 20) == 0) {//LevelUp
		cout << "leveled UP" << endl;
		this->setLevel(this->getLevel() + 1);
		this->setAttack(this->getAttack() + 10);
		this->setDefence(this->getDefence() + 10);
		this->setHealth(this->getHealth() + 20);
		system("PAUSE");
	}
}

int Player::takeDamage(int dmg)
{
	cout << "Player taking " << dmg << " damage" << endl;
	return Character::takeDamage(dmg);
}

char Player::move(int x, int y){
	this->setPosition(x,y);
	return 0;
}
