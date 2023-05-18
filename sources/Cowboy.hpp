#ifndef COWBOY
#define COWBOY
#include "Character.hpp"
#include "Point.hpp"

class Cowboy : public Character
{
private:
    int bullets_amount;
public:
    Cowboy(string _name,Point _place );
    string print() override;
    int getBullets();
    void shoot(Character* enemy);
    bool hasboolets();
    void reload();
};
#endif
