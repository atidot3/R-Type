#ifndef ENTITY
#define ENTITY

#include "math\vertex.hpp";

using std::string;
class Entity
{
public:
    string      netPosition() const;
    void        setPos(Vertex<float>);
    void        setSpeed(Vertex<float>);
    const Vertex<float>& getPos() const;
    const Vertex<float>& getSpeed() const;

protected:
	Vertex<float>	pos, speed;
};

#endif // ENTITY
