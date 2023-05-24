#include "Ninja.hpp"

Ninja::Ninja(Point _place, int _HP, string _name, int _speed) : Character(_place,_HP,_name,0)
{
    speed = _speed;
}

void Ninja::slash(Character* enemy)
{
    if(enemy == this){
        throw runtime_error ("can't shoot yourself");
    }
    if(isAlive()){
        if(enemy->isAlive()){
            if(this->distance(enemy) < 1){
                enemy->hit(40);
            }
        }
        else{
            throw runtime_error ("ninja members can't attack the deads");
        }
    }
    else{
        throw runtime_error ("dead members can't attack");
    }
}
string Ninja::print()
{
    string print = "";
    if(isAlive()){

        print = "N " + getName() + " " + to_string(getHP()) + " (" + to_string(getLocation().getX())  + "," \
        + to_string(getLocation().getY()) + ")";
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
