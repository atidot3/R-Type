#include "player.hpp"
#include "game.hpp"
#include "rocket.hpp"
#include "bullet.hpp"
#include "iSocket.hpp"

Player::Player(Game* game, string ip) : game(game), ip(ip)
{
	socket = new AbstractSocket(ip, CLIENT_PORT);
	color = game->addPlayer(this);
	level = 1;
	charge = -1;
	speed = Vertex<float>(blockSize * BLOCKS_PER_SECOND, 0);
	pos = Vertex<int>(100, 50 + color * 60);
	alive = -1;
    life = 1;
	_isAlive = true;
}

Player::~Player()
{
	delete socket;
}

void Player::die()
{
    string t;

    if (game->getTime() - lastDeath < 2)
        return;
    lastDeath = game->getTime();
    life--;
    if (life == 0)
        this->_isAlive = false;
    t += DIE;
    t = Formater::pack<int>(t, this->getId());
    t = Formater::pack<char>(t, this->life);
    game->sendAll(t);
    sendMovePacket();
}

bool        Player::isAlive() const
{
	return (_isAlive);
}

char        Player::getColor() const
{
    return (color);
}

GameTime     Player::getAliveTime() const
{
    return (alive);
}

string      Player::getIp() const
{
    return (ip);
}

void        Player::update(GameTime elapsedTime)
{
	bool	alive = false;

	alive = isAlive();
	if (alive)
	{
	    checkBounds();
    	pos += speed * elapsedTime;
	}
}

bool	Player::stuck() const
{
	if (game->getTime() > PLAYER_ALIVE && game->getTime() - alive > PLAYER_ALIVE)
		return true;
	return false;
}

void        Player::init()
{
	speed = Vertex<float>(blockSize * BLOCKS_PER_SECOND, 0);
	pos = Vertex<int>(100, 50 + color * 60);
    alive = game->getTime();
	_isAlive = true;
	charge = -1;
    life += 4;
	level++;
	lastDeath = game->getTime();
	for (int i = 0; i < 10; i++)
	{
        Sleep(100);
        sendMovePacket();
	}
}

void		Player::send(string data)
{
	socket->send(data, ip, CLIENT_PORT);
}

void        Player::sendMovePacket() const
{
    string	t;
	bool	alive = false;

	alive = isAlive();
	t += MOVE_PACKET;
	t = Formater::pack<int>(t, getId());
	t = Formater::pack<char>(t, color);
	t = Formater::pack<float>(t, game->getTime());
	t += netPosition();
	if (alive)
		game->sendAll(t);
}

void        Player::checkBounds()
{
 
}

void		Player::recv(string& data)
{
	unsigned char   command;

    command = data[0];
    data.erase(0, 1);
}
