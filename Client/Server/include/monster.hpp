#ifndef MONSTER
# define MONSTER

#include <string>
#include "library/iLibrary.hpp"
#include "math/vertex.hpp"
#include "math/time.hpp"
#include "identifiable.hpp"
#include "entity.hpp"
#include "spawn.hpp"
#include "monsterGest.hpp"
#include "math/time.hpp"
#include "game.hpp"
#include "bullet.hpp"

#define MONSTER_DEAD	9
#define MONSTER_MOV		8

using namespace std;

class Game;
class monsterGest;
class Spawn;

class Monster : public Identifiable, public Entity
{
public:
    Monster(Game*, const Spawn*, GameTime begin);
    ~Monster();
    const monsterGest*  getType() const;
    int                 getHp() const;
	Vertex<int>			getPos() const;
	void                setHp(int hp);
    void                update(float time);
    void				sendMovePacket();
    GameTime            getTime() const;

private:
    const monsterGest*  monster_gest;
    int                 hp;
    Vertex<float>       lastSpeed;
    GameTime            begin;
	GameTime			time;
	GameTime			nextShoot;
    Game*               game;
};

#endif // MONSTER