#include "client.hpp"
#include "config.hpp"
#include "time.h"
#include "stdlib.h"

Client::Client(int port) : running(false)
{
Configuration   config;

config.Load(PATH_CONFIG);

 if (config.Get("ip", adresse)    &&
    config.Get("port", port)    &&
	config.Get("player_name", player_name)    &&
	config.Get("player_life", player_life)    &&
    config.Get("errorMessage", errorMessage))
	{
    cout << "votre ip est :" << adresse << endl << "votre port est: " << port << endl;
	}
else
	{
	  cout << "Missing parameter in configuration file." << endl;
	}
	socket = new AbstractSocket(port);
}

Client::~Client()
{
	delete socket;
}

void		Client::stop()
{
    running = false;
}

void		Client::update()
{

}

void		Client::run()
{
	Logger::Instance()->open("Client.txt");
	string	buff, ip;
	Player* c;
	c = new Player();
    srand(time(NULL));
	cout << "\t\t\t\tR-Type Started..." << endl << endl << endl << "Please wait...." << endl;
    try
	{
		running = true;
		while (running == true)
		{
			socket->send("salut", adresse, SERVER_PORT);
		    buff = socket->recv(100, &adresse);
		    if (buff == WELCOME)
		    {
		        cout << "New client " << adresse << endl;
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