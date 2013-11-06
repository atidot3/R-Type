#include "server.hpp"
#include "time.h"
#include "stdlib.h"

Server::Server(int port) : running(false)
{
	socket = new AbstractSocket(port);
	game = NULL;
}

Server::~Server()
{
	while (games.size() > 0)
    {
        delete games.front();
        games.pop_front();
    }
	delete socket;
}

Player*     Server::findPlayer(string& ip)
 {
	list<Player*>	playerss;
	list<Player*>::iterator pl, plEnd; 
	plEnd = playerss.end();
	pl = playerss.begin();
	while (pl != plEnd)
	{
		if ((*pl)->getIp() == ip)
            return (*pl);
		++pl;
	}
    return (NULL);
}

void		Server::stop()
{
    running = false;
}

Server::PlayerList& Server::getPlayers()
{
    return players;
}

Game*&      Server::getCurrentGame()
{
    return game;
}

void		Server::run()
{
	string	buff, ip;
    Player* p;
    srand(time(NULL));
	cout << "\t\t\t\tR-Type Started..." << endl << endl << endl << "Please wait...." << endl;
	Logger::Instance()->log(0, "----------------Server Starting...-------------\n");
    try
	{
		running = true;
		while (running == true)
		{
			buff = socket->recv(100, &ip);
			p = this->findPlayer(ip);
		    if (p)
		    {
				Logger::Instance()->log(1, "client already connected\n");
		        p->recv(buff);
		    }
			socket->send("salut", ip, CLIENT_PORT);
		    if (buff == WELCOME_MSG)
		    {
		        cout << "New client " << ip << endl;
				Logger::Instance()->log(0, "New client\n");
		        if (!game)
		            game = new Game(this);
		        if (game->started() || game->getPlayers().size() >= MAX_PLAYERS)
		        {
					Logger::Instance()->log(0, "new Game\n");
		            game = new Game(this);
		        }
		        cout << "Added to game " << game->getId() << endl;
		        p = new Player(game, ip);
		        players.push_back(p);
		    }
		}
	}
	catch (std::exception *e)
	{
        cerr << e->what() << endl;
        delete e;
        Sleep(20000);
    }
}
