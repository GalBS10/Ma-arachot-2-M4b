#include "TrainedNinja.hpp"

TrainedNinja::TrainedNinja(string _name, Point _place) : Ninja( _place, 120, _name, 12)
{

}

void TrainedNinja::move(Character *enemy){
    this->setPlace(this->getLocation().moveTowards(this->getLocation(),enemy->getLocation(),12));//may causee some problems.
}