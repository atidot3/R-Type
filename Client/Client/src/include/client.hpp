#include <list>
#include <iostream>

#include "log.hpp"
#include <winsock2.h>
#include <Windows.h>
#include "iSocket.hpp"
#include <map>
#include <string>
#include <fstream>
#include <iostream>

#define WELCOME "salut"
#define ERROR_INSTRUCTION "Bad Instruction\n"
#define MESSAGE_LIST(ITEM)                          \
                                       ITEM(player), \
                                       ITEM(weapon), \
                                       ITEM(mob)
#define NBR_ITEM 4 //nombre d'item dans MESSAGE_LIST +1
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

using namespace std;

class Client
{
public:

	Client(int port = CLIENT_PORT);
	~Client();
	void		run();
	void		stop();
	void		update();
	void		getIP();
	void		getupdate();
	void		send(string data) const;
	void		recv(string& data) const;
	bool		send_socket(string &data) const;
	bool		recv_socket(string &data);
	void		parser(string &data) const;

private:
	ISocket		*socket;
	bool		running;
	int         ports;
	int			player_life;
	string		adresse;
	string		ips;
	string		player_name;
	string      errorMessage;
	string		data;
	int			posx;
	int			posy;
	int			life;
	bool        _isAlive;
};