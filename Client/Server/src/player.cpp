#include "player.hpp"
#include "game.hpp"
#include "monster.hpp"
#include "rocket.hpp"
#include "bullet.hpp"

Player::Player(Game* game, string ip) : game(game), ip(ip)
{
	//socket = new AbstractSocket(ip, CLIENT_PORT);
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
	//delete socket;
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
	return (this->_isAlive);
}

char        Player::getColor() const
{
    return (color);
}

Seconds     Player::getAliveTime() const
{
    return (alive);
}

string      Player::getIp() const
{
    return ip;
}

void        Player::update(Seconds elapsedTime)
{
	if (isAlive())
	{
	    checkBounds();
    	pos += speed * elapsedTime; // Move the player command
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
        //sleep(100);
        sendMovePacket();
	}
}

void		Player::send(string data)
{
	//socket->send(data, ip, CLIENT_PORT);
}

void        Player::sendMovePacket() const
{
    string t;

	t += MOVE_PACKET;
	t = Formater::pack<int>(t, getId());
	t = Formater::pack<char>(t, color);
	t = Formater::pack<float>(t, game->getTime());
	t += netPosition();
	if (isAlive())
		game->sendAll(t);
    cout << "player " << getId() << " at " << pos << " - " << speed << endl;
}

void        Player::checkBounds()
{
    bool affected = false;

    if ((speed.x < 0) && ((pos.x - game->pixPos()) < 5))
    {
        speed.x = blockSize * BLOCKS_PER_SECOND;
        affected = true;
    }
    else if ((speed.x > 0) && ((pos.x - game->pixPos()) > (640 - 70)))
    {
        speed.x = blockSize * BLOCKS_PER_SECOND;
        affected = true;
    }
    if (speed.y < 0 && pos.y < 5)
    {
        speed.y = 0;
        affected = true;
    }
    else if (speed.y > 0 && pos.y > (480 - 62))
    {
        speed.y = 0;
        affected = true;
    }
    if (affected && isAlive())
        sendMovePacket();
}

void		Player::recv(string& data)
{
}
