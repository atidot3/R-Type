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
	list<Player*>::iterator pl, plEnd; 
	plEnd = players.end();
	pl = players.begin();
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
	string data = "player positionX 19 positionY 20 life 10";
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
				Logger::Instance()->log(0, "client already connected, exiting...\n");
				buff = "";
		    }
			socket->send("salut", ip, CLIENT_PORT);
		    if (buff == WELCOME)
		    {
		        cout << "New client " << ip << endl;
		        if (!game)
		            game = new Game(this);
		        if (game->started() || game->getPlayers().size() >= MAX_PLAYERS)
		        {
		            game = new Game(this);
		        }
		        cout << "Added to game " << game->getId() << endl;
		        p = new Player(game, ip);
		        players.push_back(p);
				// TEST PARSER DICTIONNAIRE //
				game->sendAll(data);
				//TEST PARSER DICTIONNAIRE //
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
