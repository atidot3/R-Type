#include <list>
#include <iostream>

#include "log.hpp"
#include <winsock2.h>
#include <Windows.h>
#include "sockets/iSocket.hpp"

#define WELCOME_MSG "salut"
using namespace std;

class Client
{
public:

	Client(int port = CLIENT_PORT);
	~Client();
	void		run();
	void		stop();
//	Player*     findPlayer(string& ip);
//	PlayerList& getPlayers();
//	Game*&      getCurrentGame();

private:
	ISocket		*socket;
	bool		running;
};