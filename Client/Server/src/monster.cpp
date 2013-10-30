#include <iostream>
#include <stdlib.h>

#include "monster.hpp"
#include "spawn.hpp"
#include "monsterType.hpp"
#include "math/time.hpp"
#include "game.hpp"
#include "bullet.hpp"

using namespace std;

Monster::Monster(Game* game, const Spawn* spawn, Seconds begin) : begin(begin), time(0), game(game)
{
}

Monster::~Monster()
{
}

void		Monster::sendMovePacket()
{
}

void                Monster::update(float time)
{
}


const MonsterType*  Monster::getType() const
{
    return (type);
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

Seconds             Monster::getTime() const
{
    return time;
}
