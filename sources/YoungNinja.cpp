#include "YoungNinja.hpp"

YoungNinja::YoungNinja(string _name, Point _place) : Ninja( _place, 100, _name, 14)
{
}

void YoungNinja::move(Character *enemy){
    this->setPlace(this->getLocation().moveTowards(this->getLocation(),enemy->getLocation(),14));//may causee some problems.
}