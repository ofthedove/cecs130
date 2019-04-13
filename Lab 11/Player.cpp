#include "Player.h"

Player::Player()
{
	
}
Player::Player(bool isPlayerX)
{
	isXPlayer = isPlayerX;
}
Player::~Player()
{
	
}
bool Player::getIsXPlayer()
{
	return isXPlayer;
}
