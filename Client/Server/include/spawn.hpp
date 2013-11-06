#ifndef SPAWN
# define SPAWN

#include <string>

using namespace std;

class monsterGest;
class Level;

class Spawn
{
public:
    Spawn(monsterGest *monster, Level& level);
    ~Spawn();
    const monsterGest     *getMonster() const;
    float                 getPos() const;
    int                   getOffset() const;

private:
    float               pos;
    int                 offset;
    const monsterGest   *monster;
};

#endif //SPAWN



