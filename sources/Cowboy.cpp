#include "Cowboy.hpp"
#include "Point.hpp"
#include "Character.hpp"

using namespace std;


Cowboy::Cowboy(string _name, Point _place)
: Character(_place,110,_name,1)
{
    bullets_amount = 6;
}

string Cowboy::print()
{
    string print = "";
    if(isAlive()){

        print = "C " + getName() + " " + to_string(getHP()) + " (" + to_string(getLocation().getX())  + "," \
        + to_string(getLocation().getY()) + ") " + to_string(bullets_amount);
    }
    else{
        print = "C (" + getName() + ")";
    }
    return print;
    
}

int Cowboy::getBullets()
{
    return bullets_amount;
}

void Cowboy::shoot(Character* enemy)
{
    if(enemy == this){
        throw runtime_error ("can't shoot yourself");
    }
    if(isAlive()){
        if(enemy->isAlive()){
            if(hasboolets()){
                enemy->hit(10);
                bullets_amount--;
            }
        }
        else{
            throw runtime_error ("members can't attack the deads");
        }
    }
    else{
        throw runtime_error ("dead members can't attack");
    }
}
bool Cowboy::hasboolets()
{
    return bullets_amount>0;
}

void Cowboy::reload()
{
    if(!isAlive()){
        throw runtime_error ("dead cowboy cant reload");
    }
    bullets_amount = 6;
}