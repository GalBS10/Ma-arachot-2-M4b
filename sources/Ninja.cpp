#include "Ninja.hpp"

Ninja::Ninja(Point _place, int _HP, string _name, int _speed) : Character(_place,_HP,_name)
{
    speed = _speed;
}

void Ninja::slash(Character* enemy)
{
    if(isAlive()){
        if(this->distance(enemy)<1){
            enemy->hit(40);
        }
    }

}
string Ninja::print()
{
    string print = "";
    if(isAlive()){

        print = "N " + getName() + " " + to_string(getHP()) + " (" + to_string(getPlace().getX())  + "," \
        + to_string(getPlace().getY()) + ")";
    }
    else{
        print = "C (" + getName() + ")";
    }
    return print;
}

void Ninja::move(Character *enemy)
{
    cout << "move: Ninja" << endl;
}
