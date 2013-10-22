#ifndef MONSTERTYPE
# define MONSTERTYPE

#include <string>
#include <map>

using namespace std;

class MonsterType
{
public:
    MonsterType(const string& name);
    ~MonsterType();
    const string&   getName() const;
    char			getType() const;
    int             getHp() const;
    float           getFireRate() const;
private:
    const string    name;
    int             hp;
    char			type;
    float           fireRate;
};

#endif //MONSTERTYPE



