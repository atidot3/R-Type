#ifndef ROCKET
#define ROCKET

class Player;
class Game;

class Rocket : public Identifiable, public Entity
{
public:
    Rocket(/*Game* game, Player* player,*/ int size);
    ~Rocket();
};

#endif // ROCKET

