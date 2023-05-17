#ifndef NINJA
#define NINJA
#include "Character.hpp"
#include "Point.hpp"

class Ninja : public Character
{
private:
    int speed;
public:
    Ninja( Point _place, int hitpoint, string _name, int _speed);
    void slash(Character* enemy);
    string print() override;
    virtual void move(Character *enemy);
};
#endif


