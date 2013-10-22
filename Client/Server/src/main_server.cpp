#include <iostream>
#include <stdlib.h>
#include <vector>
#define BUFFSIZE 1024

using namespace std;

int	main() 
{
    srand(43);

    try 
	{
		std::cout << "Test Connection Server" << std::endl;
    } 
	catch (std::exception* e)
	{
        std::cerr << e->what() << std::endl;
        delete e;
    }
    return 0;
}