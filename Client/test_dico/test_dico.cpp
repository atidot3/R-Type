#include <cstdlib>
#include <stdio.h>
#include <string>

using namespace std;


#define MESSAGE_LIST(ITEM)                          \
                                       ITEM(player), \
                                       ITEM(weapon), \
                                       ITEM(mob)
#define GET_LIST__ITEM(msg)   _##msg##_
#define GET_LIST_SRTING_ITEM(msg)  #msg

enum MessagesEnum
{
   MESSAGE_LIST(GET_LIST__ITEM)
};
static const char* Type[] = 
{
   MESSAGE_LIST(GET_LIST_SRTING_ITEM)
};

int main(int argc, char** argv) 
{

    int totalMessages = sizeof(Type)/4; //nombre objet -1
	string data = "player";
    for (int i = 0; i < totalMessages; i++)
    {
/*        if (i == _player_)
        {
                printf ("_MSG_A_ => [%d]=[%s]\n", i, Type[i]);
        }
        else if (i == _weapon_)
        {
                printf ("_MSG_B_ => [%d]=[%s]\n", i, Type[i]);
        }
        else if (i == _mob_)
        {
                printf ("_MSG_C_ => [%d]=[%s]\n", i, Type[i]);
        }
        else
        {
                printf ("??? => [%d]=[%s]\n", i, Type[i]);
        }
		*/
		if (data == Type[i])
		{
			printf ("[%s]\n", Type[i]);
			break;
		}
		else
			printf("NO MATCH\n");
    }   
	system("PAUSE");
    return 0;
}