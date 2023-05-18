#include "TrainedNinja.hpp"

TrainedNinja::TrainedNinja(string _name, Point _place) : Ninja( _place, 120, _name, 12)
{

}
// string TrainedNinja::print(){
//     string print = "";
//     if(isAlive()){

//         print = "N " + getName() + " " + to_string(getHP()) + " (" + to_string(getPlace().getX())  + "," \
//         + to_string(getPlace().getY()) + ")";
//     }
//     else{
//         print = "C (" + getName() + ")";
//     }
//     return print;
// }

void TrainedNinja::move(Character *enemy){
    this->setPlace(this->getLocation().moveTowards(this->getLocation(),enemy->getLocation(),12));//may causee some problems.
}