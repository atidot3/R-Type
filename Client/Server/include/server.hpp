#ifndef SERVER
# define SERVER

#include <list>
#include <iostream>

#include "game.hpp"
#include "player.hpp"
#include <winsock2.h>
#include <Windows.h>
#include "sockets/iSocket.hpp"

#define WELCOME_MSG "salut"
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
	ISocket		*socket;
	Game*   	game;
	bool		running;
};

#endif // SERVER