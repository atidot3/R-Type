#ifndef ROCKET
#define ROCKET

#include "identifiable.hpp"
#include "entity.hpp"

class Player;
class Game;

class Rocket : public Identifiable, public Entity
{
public:
    Rocket(/*Game* game, Player* player, int size*/);
    ~Rocket();
	void    update();
    int     getSize() const;
private:
    //Game*   game;
    //Player* player;
    int     size;
};

#endif // ROCKET

