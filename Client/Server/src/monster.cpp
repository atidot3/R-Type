#include <iostream>
#include <stdlib.h>

#include "monster.hpp"
#include "spawn.hpp"
#include "monsterGest.hpp"
#include "math/time.hpp"
#include "game.hpp"
#include "bullet.hpp"

using namespace std;

Monster::Monster(Game* game, const Spawn* spawn, GameTime begin) : begin(begin), time(0), game(game)
{
    monster_gest = spawn->getMonster();
    pos.x = spawn->getPos() * blockSize;
    pos.y = spawn->getOffset();
    speed = Vertex<float>(0, 0);
    hp = monster_gest->getHp();
    nextShoot = 0;
    sendMovePacket();
}

Monster::~Monster()
{
    string  t;

    t += MONSTER_DEAD;
    t = Formater::pack<int>(t, getId());
    game->sendAll(t);
}

void		Monster::sendMovePacket()
{
	string	t;

    t += MONSTER_MOV;
    t = Formater::pack<int>(t, getId());
    t = Formater::pack<char>(t, monster_gest->getType());
    t = Formater::pack<float>(t, game->getTime());
    t += netPosition();
    game->sendAll(t);
}

void                Monster::update(float time)
{
    float diff = time - (this->time + this->begin);

    nextShoot += diff;
    if (nextShoot >= (1 / monster_gest->getFireRate()))
    {
        nextShoot -= (1 / monster_gest->getFireRate());
        //new Bullet(game, this);
    }
    speed = monster_gest->fMove(this->time);
    if (!(lastSpeed == speed))
        sendMovePacket();
    lastSpeed = speed;
    speed *= diff;
    pos += speed;
    this->time = time - begin;
}


const monsterGest*  Monster::getType() const
{
    return (monster_gest);
}

void                Monster::setHp(int hp)
{
    this->hp = hp;
}

Vertex<int>			Monster::getPos() const
{
	return (Vertex<int>(pos));
}

int                 Monster::getHp() const
{
    return (hp);
}

GameTime             Monster::getTime() const
{
    return time;
}