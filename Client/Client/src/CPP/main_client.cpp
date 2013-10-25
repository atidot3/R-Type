#include "log.hpp"

int		main()
{	Logger::Instance()->open("COIN.txt");
	Logger::Instance()->log(3, "----------------Client Initialized-------------\n");
	Logger::Instance()->log(3, "Exit with code 0");
	return (0);
}
