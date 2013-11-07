#pragma once

class Monster
{
public:
	Monster(float time, std::vector<int> MonsterPos, std::vector<int> PlayerPos); // Demander le format des positions
	virtual ~Monster(void);
private:
	float		time;
	std::vector<int>	MonsterPos;
	std::vector<int>	PlayerPos;
	virtual const float		getTime() = 0;
};

