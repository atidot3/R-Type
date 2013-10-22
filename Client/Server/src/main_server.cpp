#include <iostream>
#include <string>
#include <stdlib>
#include "server.hpp"

using namespace std;

int	main()
{
	srand(43);
	try 
	{
		std::cout << "visual la grosse merde" << std::endl;
    } 
	catch (std::exception* e)
	{
        std::cerr << e->what() << std::endl;
        delete e;
    }
    return 0;
}
