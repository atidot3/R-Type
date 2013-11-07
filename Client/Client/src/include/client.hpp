#include <list>
#include <iostream>

#include "log.hpp"
#include "player_client.hpp"
#include <winsock2.h>
#include <Windows.h>
#include "iSocket.hpp"
#include <map>
#include <string>
#include <fstream>
#include <iostream>

#define WELCOME "salut"
using namespace std;

class Client
{
public:

	Client(int port = CLIENT_PORT);
	~Client();
	void		run();
	void		stop();
	void		update();
//	Player*     findPlayer(string& ip);
//	PlayerList& getPlayers();
//	Game*&      getCurrentGame();

private:
	ISocket		*socket;
	bool		running;
	int             ports;
int				player_life;
string			ips;
string			player_name;
string          errorMessage;
};