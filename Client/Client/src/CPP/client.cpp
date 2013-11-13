#include "client.hpp"
#include "config.hpp"
#include "time.h"
#include "SFML_window.hpp"

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
		socket = new AbstractSocket(port);
		Logger::Instance()->log(0, adresse + " Connected");
	}
else
	{
	  Logger::Instance()->log(2, "Invalide configuration file");
	}
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

void	Client::getupdate()
{

}

void		Client::getIP()
{
	return;
}
void		Client::run()
{
	Logger::Instance()->open("Client.txt");
	string	buff, ip;
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    srand(time(NULL));
	cout << "\t\t\t\tR-Type Started..." << endl << endl << endl << "Please wait...." << endl;
    try
	{
		running = true;
			socket->send("salut", adresse, SERVER_PORT);
		    buff = socket->recv(100, &adresse);
		    if (buff == WELCOME)
		    {
		        cout << "New client " << adresse << endl;
				_isAlive = true;
				posx = 1;
				posy = 1;
				while (running == true && window.isOpen())
				{
					sf::Event event;
					 while (window.pollEvent(event))
					   {
					     if (event.type == sf::Event::Closed)
				          window.close();
						}
					window.clear();
					window.draw(shape);
					window.display();
					recv_socket(data);

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

bool	Client::recv_socket(string &data)
{
	data = socket->recv(100, &adresse);
	parser(data);
	return (true);
}

bool	Client::send_socket(string &data) const
{
	string buffer;
	socket->send(data, adresse, SERVER_PORT);
	return (true);
}

void	Client::parser(string &data) const
{
    int totalItem = sizeof(Type)/4; //nombre objet +1
    for (int i = 0; i < totalItem; i++)
	{
		if (data == Type[i])
		{
			cout << Type[i] << " ok" << endl;
			// recuperer les param
			return;
		}
	}
	cout << ERROR_INSTRUCTION;
}