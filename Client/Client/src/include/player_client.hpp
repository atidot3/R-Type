#ifndef PLAYER
# define PLAYER

#include <string>

class Player
{
public:
	Player();
	~Player();
	void		send_socket();
	void		recv_socket();

private:

	int			posx;
	int			posy;
	int			life;
	bool        _isAlive;

};

#endif //player_client