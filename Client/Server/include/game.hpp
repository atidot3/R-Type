#ifndef GAME
# define GAME
#include <string>
#include <list>
#include <math.h>
#include "identifiable.hpp"

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
    Game(Server* server);
    ~Game();
private:
};

#endif // GAME




