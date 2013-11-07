#include "Monster.hpp"

Monster::Monster(float time, std::vector<int> MonsterPos, std::vector<int> PlayerPos);
{
	this->time = time;
	this->MonsterPos = MonsterPos;
	this->PLayerPos = PlayerPos;
}

Monster::~Monster(void)
{
}
