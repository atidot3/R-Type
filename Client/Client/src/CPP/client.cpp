#include "client.hpp"
#include "config.hpp"
#include "time.h"
#include "stdlib.h"

Client::Client(int port) : running(false)
{
Configuration   config;

config.Load(PATH_CONFIG);

 if (config.Get("ip", ips)    &&
    config.Get("port", ports)    &&
	config.Get("player_name", player_name)    &&
	config.Get("player_life", player_life)    &&
    config.Get("errorMessage", errorMessage))
	{
    cout << "votre ip est :" << ips << endl << "votre port est: " << ports << endl;
	}
else
	{
	  cout << "Missing parameter in configuration file." << endl;
	}
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

void		Client::update()
{

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
	Player* c;
	c = new Player();
    srand(time(NULL));
	cout << "\t\t\t\tR-Type Started..." << endl << endl << endl << "Please wait...." << endl;
    try
	{
		running = true;
		while (running == true)
		{
			socket->send("salut", ip, SERVER_PORT);
		    buff = socket->recv(100, &ip);
		    if (buff == WELCOME)
		    {
		        cout << "New client " << ip << endl;
		    }
			system("PAUSE");
		}
	}
	catch (std::exception *e)
	{
        cerr << e->what() << endl;
        delete e;
        Sleep(20000);
    }
}