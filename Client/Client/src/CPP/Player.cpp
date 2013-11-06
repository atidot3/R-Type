#include "player_client.hpp"
#include <stdio.h>
#include <list>
#include <iostream>

Player::Player()
{
	std::cout << "New player :) " << std::endl;
	posx = 1;
	posy = 1;
}

Player::~Player()
{

}