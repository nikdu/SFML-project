#include "Player.h"

using namespace std;

Player::Player(string name, int score)
{
	this->name = name;
	this->score = score;
	//this->lifeLinesCounter = lifeLinesCounter;
}

Player::Player()
{
	this->name = "";
	this->score = 0;
	//this->lifeLinesCounter = 4;
}

Player::~Player()
{
}

int Player::getScore()
{
	return this->score;
}

void Player::setScore(int score)
{
	this->score = score;
}

string Player::getName() {
	return this->name;
}

void Player::setName(string name) {
	this->name = name;
}

