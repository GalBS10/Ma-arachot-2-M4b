#include "YoungNinja.hpp"

YoungNinja::YoungNinja(string _name, Point _place) : Ninja( _place, 100, _name, 14)
{
}

// string YoungNinja::print(){
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
void YoungNinja::move(Character *enemy){
    // cout << "in move of young ninja" << endl;
    // getLocation().print();
    this->setPlace(this->getLocation().moveTowards(this->getLocation(),enemy->getLocation(),14));//may causee some problems.
    // getLocation().print();
}