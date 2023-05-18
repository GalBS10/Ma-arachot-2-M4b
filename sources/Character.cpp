#include "Character.hpp"
#include "Point.hpp"

Character::Character(Point _place, int hitpoint, string _name) : place(_place), HP(hitpoint), name(_name)
{
}
Character::Character(const Character& other)
    : place(other.place), HP(other.HP), name(other.name)
{
}
Character::~Character(){
    //there is no allocated memory to free.
}
Character& Character::operator=(const Character& other)
{
    if (this != &other) {
        place = other.place;
        HP = other.HP;
        name = other.name;
    }
    return *this;
}

Character::Character(Character&& other) noexcept
    : place(std::move(other.place)), HP(std::move(other.HP)), name(std::move(other.name))
{
}

Character& Character::operator=(Character&& other) noexcept
{
    if (this != &other) {
        place = move(other.place);
        HP = move(other.HP);
        name = move(other.name);

    }
    return *this;
}

bool Character::isAlive(){
    return HP>0;
}
int Character::getHP(){
    return HP;
}
Point Character::getPlace(){
    return place;
}
void Character::setPlace(const Point& new_place){
    this->place = new_place;
}
double Character::distance(Character* other){
    return place.distance(other->place);
}
void Character::hit(int damage){
    HP-=damage;
    if(HP<0){
        HP = 0;
    }
}
string Character::getName(){
    return name;
}

// Point Character::getLoactaion(){
//     return place;
// }

string Character::print()
{
    return "Character";
}
