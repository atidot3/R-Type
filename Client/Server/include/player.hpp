#ifndef PLAYER
# define PLAYER

#include <string>
#include "math/vertex.hpp"
#include "math/time.hpp"
//#include "sockets/iSocket.hpp"
#include "identifiable.hpp"
#include "entity.hpp"

#define PLAYER_ALIVE	5

using namespace std;

class Game;
class MonsterType;
class Spawn;

class Player : public Identifiable, public Entity
{
public:
	Player(Game* game, string ip);
	~Player();
	void		send(string data); // send data to graphic terminal
	void		recv(string& data); // callback on data receive
    void        update(Seconds); // update player's position
    char        getColor() const;
    bool	    stuck() const;
    void        die();
    bool        isAlive() const;
    Seconds     getAliveTime() const;
    string      getIp() const;
    void        init(); // called when the game start
    void        sendMovePacket() const;
    void        checkBounds();

private:
	int			color;
	int         level;
	bool        _isAlive;
	Game*		game;
	char        life;
	//ISocket*	socket;
	string		ip;
    Seconds     begin, charge, alive, lastDeath;
};

#endif // PLAYER