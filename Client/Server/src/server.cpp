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

void		Server::run()
{
	string	buff, ip;
    srand(time(NULL));
    try 
	{
	running = true;
	while ((running == true))
	{
	}
    } 
	catch (std::exception *e) {
        cerr << e->what() << endl;
        delete e;
        //sleep(20000);
    }
}
