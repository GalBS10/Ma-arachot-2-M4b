#include "Ninja.hpp"

Ninja::Ninja(Point _place, int _HP, string _name, int _speed) : Character(_place,_HP,_name,0)
{
    speed = _speed;
}

void Ninja::slash(Character* enemy)
{
    // cout << getName() << " attcking " << enemy->getName() << endl;
    //  cout << "in slash" << endl;
    if(isAlive()){
        // cout << "in slash : in if 1" << endl;
        // cout << distance(enemy) << endl;
        if(this->distance(enemy) < 1){
            // cout << "in slash : in if 2" << endl;
            enemy->hit(40);
        }
        else{
            // cout << "in slash in else" << endl;
            // cout << print() << endl;
            // cout << "blah" << endl;
            this->move(enemy);
            // cout << "in slash in else after move" << endl;
        }
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
