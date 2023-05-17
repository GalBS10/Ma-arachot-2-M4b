#include "Ninja.hpp"

Ninja::Ninja(Point _place, int _HP, string _name, int _speed) : Character(_place,_HP,_name)
{
    speed = _speed;
}

void Ninja::slash(Character* enemy)
{
    

}
string Ninja::print()
{
    return "Ninja";
}

void Ninja::move(Character *enemy)
{

}

