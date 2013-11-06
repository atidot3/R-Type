#include <stdlib.h>
#include "spawn.hpp"
#include "level.hpp"
#include "monsterGest.hpp"

int     randPos(int min, int max)
{
    return (rand() % (max - min) + min);
}

Spawn::Spawn(monsterGest *monster, Level& level) : monster(monster)
{
    int min = 12;
    int max = 100 - 12; // à changer suivant la taille du level

    Vertex<int> spawnPos = monster->fSpawnPos(0);
    if (spawnPos.x == -1)
        this->pos = randPos(min, max) + ((float)(rand() % blockSize) / (float)blockSize);
    else
        this->pos = (float)spawnPos.x / (float)blockSize;
    if (spawnPos.y == -1)
        this->offset = randPos(blockSize * 0.5, blockSize * 5);
    else
        this->offset = spawnPos.y;
}

Spawn::~Spawn()
{
}

const monsterGest     *Spawn::getMonster() const
{
    return (monster);
}

float             Spawn::getPos() const
{
    return (pos);
}

int               Spawn::getOffset() const
{
    return (offset);
}