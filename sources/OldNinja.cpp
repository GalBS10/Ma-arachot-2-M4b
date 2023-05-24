#include "OldNinja.hpp"

OldNinja::OldNinja(string _name, Point _place) : Ninja( _place, 150, _name, 8)
{

}

void OldNinja::move(Character *enemy)
{
    this->setPlace(this->getLocation().moveTowards(this->getLocation(),enemy->getLocation(),8));
}