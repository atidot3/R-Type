#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "server.hpp"

Server::Server(int port) : running(false)
{

}

Server::~Server()
{

}

void		Server::stop()
{
    running = false;
}

Player*     findPlayer(string& ip)
{
    return (NULL);
}

void		Server::run()
{
	string	buff, ip;
    Player* p;

    srand(time(NULL));

    try
	{
	running = true;
	while ((running == true))
	{
		/*buff = socket->recv(100, &ip);
        if ((p = findPlayer(ip)))
        {
            p->recv(buff);
        }
        else if (buff == WELCOME_MSG)
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
        }*/
	}
    } 
	catch (std::exception *e)
	{
        cerr << e->what() << endl;
        delete e;
        Sleep(20000);
    }
}
