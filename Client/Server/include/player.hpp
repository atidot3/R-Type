#ifndef PLAYER
# define PLAYER

#include <string>
#include "math/vertex.hpp"
#include "math/time.hpp"
#include "identifiable.hpp"
#include "entity.hpp"

#define	DIE					0x05
#define	MOVE_PACKET			0x03
#define PLAYER_ALIVE		5

using namespace std;

class Game;
class monsterGest;
class Spawn;
class ISocket;

class Player : public Identifiable, public Entity
{
public:
	Player(Game* game, string ip);
	~Player();
	void		send(string data);
	void		recv(string& data);
    void        update(GameTime);
    char        getColor() const;
    bool	    stuck() const;
    void        die();
    bool        isAlive() const;
    GameTime     getAliveTime() const;
    string      getIp() const;
    void        init();
    void        sendMovePacket() const;
    void        checkBounds();

private:
	int			color;
	int         level;
	bool        _isAlive;
	Game*		game;
	char        life;
	string		ip;
    GameTime    begin;
	GameTime	charge;
	GameTime	alive;
	GameTime	lastDeath;
	ISocket*	socket;
};

#endif // PLAYER