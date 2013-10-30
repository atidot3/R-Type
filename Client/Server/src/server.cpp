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

Player*     findPlayer(string& ip)
{
	/*PlayerList::iterator pl, plEnd; 
	plEnd = players.end();
	pl = players.begin();
	while (pl != plEnd)
	{
		if ((*pl)->getIp() == ip)
            return (*pl);
		++pl;
	}*/
    return (NULL);
}

void		Server::run()
{
	Logger::Instance()->open("Server.txt");
	string	buff, ip;
    Player* p;
	ip = "127.0.0.1";
    srand(time(NULL));
	cout << "\t\t\t\tR-Type Started..." << endl << endl << endl << "Please wait...." << endl;
    try
	{
		running = true;
		while (running == true)
		{
		    /*if ((p = findPlayer(ip)))
		    {
		        p->recv(buff);
		    }*/
			buff = socket->recv(100, &ip);
			socket->send("salut", ip, CLIENT_PORT);
		    if (buff == WELCOME_MSG)
		    {
		        cout << "New client " << ip << endl;
		        if (!game)
		            game = new Game(this);
		        if (game->started() || game->getPlayers().size() >= MAX_PLAYERS)
		        {
		            // New game
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
