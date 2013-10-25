#include "log.hpp"

int		main()
{	Logger::Instance()->open("LOG.txt");
	Logger::Instance()->log(-1, "----------------Client Initialized-------------\n");
	Logger::Instance()->log(-1, "Exit with code 0");
	return (0);
}
