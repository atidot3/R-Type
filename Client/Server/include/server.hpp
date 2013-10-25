#ifndef SERVER
# define SERVER

#include <list>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "player.hpp"
#include "game.hpp"

#define WELCOME_MSG "salut"
#define SERVER_PORT 4242
using namespace std;

class Server
{
public:
	typedef	list<Player*>	PlayerList;
	typedef	list<Game*>		GameList;

	Server(int port = SERVER_PORT);
	~Server();
	void		run();
	void		stop();
	Player*     findPlayer(string& ip);
	PlayerList& getPlayers();
	Game*&      getCurrentGame();

private:
	PlayerList	players;
	GameList	games;
	//ISocket		*socket;
	Game*   	game;
	bool		running;
};

#endif // SERVER