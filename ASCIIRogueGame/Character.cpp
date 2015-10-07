#include "Character.h"

Character::Character(char type,Position p, int level, int health, int attack, int defence, int experience):
_type(type),
_position(p),
_level(level),
_health(health),
_attack(attack),
_defence(defence),
_experience(experience)
{}

int Character::getLevel() const
{
	return this->_level;
}

void Character::setLevel(int level){
	this->_level = level;
}

int Character::getAttack() const
{
	return this->_attack;
}

void Character::setAttack(int attack){
	this->_attack = attack;
}

int Character::getDefence() const
{
	return this->_defence;
}

void Character::setDefence(int defence){
	this->_defence = defence;
}

void Character::setHealth(int health){
	this->_health = health;
}

int Character::getHealth() const{
	return this->_health;
}

int Character::getExperience() const
{
	return this->_experience;
}

void Character::setExperience(int exp){
	this->_experience = exp;
}

void Character::addExerience(int exp){
	this->_experience += exp;
}

const Position & Character::getPosition() const {
	return this->_position;
}

void Character::setPosition(Position p) {
	_position = p;
}

void Character::setPosition(int x, int y) {
	_position.setXCoord(x);
	_position.setYCoord(y);
}

void Character::setType(char type){
	this->_type = type;
}

char Character::getType(){
	return this->_type;
}

int Character::attack() {
	static default_random_engine randomEngine((unsigned int)time(NULL));//only time seed setting
	uniform_int_distribution<int> attackRoll(this->getAttack(), this->getAttack());
	return attackRoll(randomEngine);
}

int Character::takeDamage(int dmg)
{
	int remainingDefence = this->_defence - dmg;
	if (remainingDefence <= 0) {
		this->_defence = 0;
		this->_health -= (remainingDefence*-1);
	}
	else {
		this->_defence = remainingDefence;
	}
	if (this->_health <= 0) {
		return this->_experience;
	}
	else return 0;
}

void Character::setSymbol(char s) {
	this->_symbol = s;
}

char Character::getSymbol() const{
	return this->_symbol;
}


