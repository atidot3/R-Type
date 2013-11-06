#include "monsterGest.hpp"

monsterGest::monsterGest(const string& name, const int qty) : name(name), qty(qty)
{
	//Ici sera chargé les lib.
}

monsterGest::~monsterGest()
{
    delete lib;
}

Vertex<int>     monsterGest::fMove(float time) const
{
    return ((*move)(time));
}

Vertex<int>     monsterGest::fFire(float time) const
{
    return ((*fire)(time));
}

Vertex<int>     monsterGest::fSpawnPos(float time) const
{
    return ((*spawnPos)(time));
}

const string&   monsterGest::getName() const
{
    return (name);
}

int             monsterGest::getQty() const
{
    return (qty);
}

char			monsterGest::getType() const
{
	return (type);
}

int             monsterGest::getHp() const
{
    return (hp);
}

float           monsterGest::getFireRate() const
{
    return (fireRate);
}
