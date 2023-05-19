#include "OldNinja.hpp"

OldNinja::OldNinja(string _name, Point _place) : Ninja( _place, 150, _name, 8)
{

}
// string OldNinja::print()
// {
    
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
void OldNinja::move(Character *enemy)
{
    //  cout << "in move of old ninja" << endl;
    //  getLocation().print();
    this->setPlace(this->getLocation().moveTowards(this->getLocation(),enemy->getLocation(),8));//may causee some problems.
    // getLocation().print();
}