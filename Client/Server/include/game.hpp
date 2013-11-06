#ifndef GAME
# define GAME

#include <string>
#include <list>
#include <math.h>
#include "player.hpp"
#include "server.hpp"
#include "identifiable.hpp"
#include "threads\iThread.hpp"
#include "monster.hpp"
#include "level.hpp"
#include "spawn.hpp"
#include "monsterGest.hpp"
#include "math/time.hpp"
#include "bullet.hpp"

#define MAX_PLAYERS 4

using namespace std;

class Monster;
class Level;
class Player;
class Rocket;
class Bullet;
class Server;

class Game : public Identifiable
{
public:
    typedef list<Monster*> MonsterList;
    //typedef list<Rocket*>  RocketList;
    //typedef list<Bullet*>  BulletList;
    typedef list<Player*>	PlayerList;

    Game(Server* server);
    ~Game();
    int         run();
	int			loop();
	void		start();
	bool        started() const;
	int 		addPlayer(Player*);
	void 		removePlayer(Player*);
	float		loadingBlock() const;
	void		sendAll(string& data) const;
	Monster*    findMonster(int id);
	//Rocket*     findRocket(int id);
	Player*     findPlayer(int id);
    //Bullet*     findBullet(int id);
    void        addPoints(int pts);
    bool        nextLevel();
    int         pixPos() const;
    void        sendMapInfo() const;
    bool        gameOver() const;
    //BulletList& getBullets();
    PlayerList& getPlayers();
    //RocketList& getRockets();
    float       getTime() const;
    Player*     getReferee() const;
private:
	int         pos;
    GameTime     time;
    GameTime     begin;
    GameTime     last;
    GameTime     endTime;
    int         life;
    int         score;
    //Level       *level;
    MonsterList monsters;
    IThread*    thread;
	PlayerList	players;
	//RocketList  rockets;
	//BulletList  bullets;
	Player*		referee;
    Server*	server;
};

int     threadFunc(void *data);

#endif // GAME




