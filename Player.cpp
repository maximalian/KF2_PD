#include "Player.h"

Player::Player()
{
	this->score = 0;
}

void Player::setScore(int score)
{
	this->score = score;
}

int Player::getScore()
{
	return this->score;
}

void Player::setStatus(bool makingMove)
{
	this->makingMove = makingMove;
}

bool Player::getStatus()
{
	return makingMove;
}



