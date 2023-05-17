#include "Cowboy.hpp"
#include "Point.hpp"
#include "Character.hpp"

using namespace std;


Cowboy::Cowboy(string _name, Point _place)
: Character(_place,110,_name)
{
    bullets_amount = 6;
}

string Cowboy::print()
{
    string print = "";
    if(isAlive()){

        print = "C " + getName() + " " + to_string(getHP()) + " (" + to_string(getPlace().getX())  + "," \
        + to_string(getPlace().getY()) + ")" + to_string(bullets_amount);
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
    if(isAlive()){
        if(hasboolets()){
            enemy->hit(10);
            bullets_amount--;
        }
        else{
            reload();
        }
    }

}
bool Cowboy::hasboolets()
{
    return bullets_amount>0;
}

void Cowboy::reload()
{
    bullets_amount = 6;
}