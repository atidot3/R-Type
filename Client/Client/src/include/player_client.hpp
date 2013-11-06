#ifndef PLAYER
# define PLAYER

#include "player_client.hpp"

class Player
{
public:
	Player();
	~Player();

private:

	int			posx;
	int			posy;
	int			life;
	bool        _isAlive;

};

#endif //player_client