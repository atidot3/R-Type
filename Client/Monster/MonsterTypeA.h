#pragma once

class MonsterTypeA : public Monster
{
public:
	MonsterTypeA(float time, std::vector<int> MonsterPos, std::vector<int> PlayerPos);
	virtual ~MonsterTypeA(void);
private:
	float	time;
	std::vector<int>	MonsterPos;
	std::vector<int>	PlayerPos;
};

