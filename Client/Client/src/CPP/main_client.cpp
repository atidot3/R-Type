#include <iostream>
#include "client.hpp"
#include <stdlib.h>
#include <vector>
#include "log.hpp"

using namespace std;

int	main()
{
	Logger::Instance()->open("Client.txt");
	Logger::Instance()->log(0, "----------------Client Initialized-------------\n");
	srand(43);
	try 
	{
		Client	clie;
		clie.run();
    } 
	catch (std::exception* e)
	{
        std::cerr << e->what() << std::endl;
		Logger::Instance()->log(3, e->what());
        delete e;
    }
	Logger::Instance()->log(0, "Exit with code 0");
    return 0;
}

//#include "log.hpp"

//int		main()
//{
//	Logger::Instance()->open("COIN.txt");
//	Logger::Instance()->log(3, "----------------Client Initialized-------------\n");
//	Logger::Instance()->log(3, strcat(prout, "YOUHOU"));
//	Logger::Instance()->log(3, "Exit with code 0");
//	return (0);
//}
