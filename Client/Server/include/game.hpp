#ifndef GAME
# define GAME
#include <string>
#include <list>
#include <math.h>
#include "player.hpp"
#include "server.hpp"
#include "identifiable.hpp"

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
    //typedef list<Monster*> MonsterList;
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
	void		sendAll(string& data) const; // send data to all players
	//Monster*    findMonster(int id);
	//Rocket*     findRocket(int id);
	Player*     findPlayer(int id);
    //Bullet*     findBullet(int id);
    void        addPoints(int pts);
    bool        nextLevel();
    int         pixPos() const; // Get pix position
    void        sendMapInfo() const; // send map info to players
    bool        gameOver() const;
    //BulletList& getBullets();
    PlayerList& getPlayers();
    //RocketList& getRockets();
    float       getTime() const;
    Player*     getReferee() const;
private:
	int         pos; // game position (in pixels)
    Seconds     time; // game position (in seconds)
    Seconds     begin; // game start (in seconds)
    Seconds     last; // last frame (in seconds)
    Seconds     endTime; // Level end time (used for tempo)
    int         life; // players life (when 0, restart at the level begining)
    int         score; // game total score
    //Level       *level; // current game level
    //MonsterList monsters; // visible monsters on screen
    //IThread*    thread;
	PlayerList	players;
	//RocketList  rockets;
	//BulletList  bullets;
	Player*		referee;
    Server*	server;
};

#endif // GAME




