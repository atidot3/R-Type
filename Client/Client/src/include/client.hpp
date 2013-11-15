#ifndef __CLIENT_HPP__
#define	__CLIENT_HPP__

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
#define SUCCESS	1
#define FAILURE	-1
#define ERROR_INSTRUCTION "Bad Instruction\n"

/* fonction parser selon le type d'objet */
#define MESSAGE_LIST(ITEM)                          \
                                       ITEM(player), \
                                       ITEM(weapon), \
                                       ITEM(mob)
#define NBR_ITEM 4 //nombre d'item dans MESSAGE_LIST +1
#define GET_LIST__ITEM(msg)   _##msg##_
#define GET_LIST_SRTING_ITEM(msg)  #msg

/* fonction parser selon le type d'objet */
#define MESSAGE_OPT(OPT)                          \
                                       OPT(positionX), \
                                       OPT(positionY), \
                                       OPT(life)
#define NBR_ITEM 4 //nombre d'item dans MESSAGE_OPT +1
#define GET_OPT__OPT(msg)   _##msg##_
#define GET_OPT_SRTING_OPT(msg)  #msg

enum MessagesEnum
{
   MESSAGE_LIST(GET_LIST__ITEM)
};
static const char* Type[] = 
{
   MESSAGE_LIST(GET_LIST_SRTING_ITEM)
};

enum MessagesOptEnum
{
   MESSAGE_OPT(GET_OPT__OPT)
};
static const char* Opt[] = 
{
   MESSAGE_OPT(GET_OPT_SRTING_OPT)
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
	void		parse_all_data(string &data) const;

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
	int			life;
	bool        _isAlive;

protected:
	int			WindowsX;
	int			WindowsY;
};

#endif /* __CLIENT_HPP__ */