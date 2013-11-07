#include "MonsterTypeA.h"


MonsterTypeA::MonsterTypeA(float time, std::vector<int> MonsterPos, std::vector<int> PlayerPos);
{
	this->time = time;
	this->MonsterPos = MonsterPos;
	this->PLayerPos = PlayerPos;
}


MonsterTypeA::~MonsterTypeA(void)
{
}
