#include <iostream>
#include <string>
#include "server.hpp"

using namespace std;

int	main()
{
	srand(43);
	try 
	{
		Server	serv;
		serv.run();
    } 
	catch (std::exception* e)
	{
        std::cerr << e->what() << std::endl;
        delete e;
    }
    return 0;
}
