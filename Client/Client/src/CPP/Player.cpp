#include <stdio.h>
#include <list>
#include <string>
#include <iostream>
#include "player_client.hpp"


Player::Player()
{
	_isAlive = true;
	posx = 1;
	posy = 1;
	while (_isAlive == true)
	{
		
	}
}

Player::~Player()
{

}

void	Player::recv_socket()
{

}
