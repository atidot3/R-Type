#include "player.hpp"
#include "game.hpp"
#include "monster.hpp"
#include "rocket.hpp"
#include "bullet.hpp"

Player::Player()
{
	level = 1;
    life = 1;
	_isAlive = true;
}

Player::~Player()
{
}

void Player::die()
{

}

bool        Player::isAlive() const
{
	return (this->_isAlive);
}

char        Player::getColor() const
{
    return (color);
}

string      Player::getIp() const
{
    return ip;
}

void        Player::update()
{

}

bool	Player::stuck() const
{
	return false;
}

void        Player::init()
{
	_isAlive = true;
    life += 4;
	level++;
}

void		Player::send(string data)
{
;
}

void        Player::sendMovePacket() const
{

}

void        Player::checkBounds()
{

}

void		Player::recv(string& data)
{
 
}
