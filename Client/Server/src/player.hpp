#ifndef PLAYER
# define PLAYER

#include <string>

using namespace std;

class Game;
class MonsterType;
class Spawn;

class Player : public Identifiable, public Entity
{
public:
	Player(/*Game* game,*/ string ip);
	~Player();
private:
	int			color;
	int         level;
	bool        _isAlive;
	//Game*		game;
	char        life;
	string		ip;
};

#endif // PLAYER




