#include "client.hpp"
#include "time.h"
#include "stdlib.h"

Client::Client(int port) : running(false)
{
	socket = new AbstractSocket(port);
}

Client::~Client()
{
/*	while (games.size() > 0)
    {
        delete games.front();
        games.pop_front();
    }
	delete socket; */
}

void		Client::stop()
{
    running = false;
}
/*
 Client::PlayerList& Client::getPlayers()
{
    return players;
}

Game*&      Client::getCurrentGame()
{
    return game;
}

Player*     findPlayer(string& ip)
{
    return (NULL);
} */

void		Client::run()
{
	Logger::Instance()->open("Client.txt");
	string	buff, ip;
	ip = "127.0.0.1";
//    Player* p;

    srand(time(NULL));
	cout << "\t\t\t\tR-Type Started..." << endl << endl << endl << "Please wait...." << endl;
    try
	{
		running = true;
		while (running == true)
		{
			socket->send("salut", ip, SERVER_PORT);
		    buff = socket->recv(100, &ip);
			/*if ((p = findPlayer(ip)))
		    {
		        p->recv(buff);
		    }*/
		    if (buff == WELCOME_MSG)
		    {
		        cout << "New client " << ip << endl;
	/*	        if (!game)
		            game = new Game(this);
		        if (game->started() || game->getPlayers().size() >= MAX_PLAYERS)
		        {
		            // New game
		            game = new Game(this);
		        }
		        cout << "Added to game " << game->getId() << endl;
		        p = new Player(game, ip);
		        players.push_back(p); */
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
