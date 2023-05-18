#ifndef CHARACTER
#define CHARACTER

#include "Point.hpp"
#include <string>

class Character {
private:
    Point place;
    int HP; // hit point
    std::string name;

public:
    Character(Point _place, int hitpoint, std::string _name);
    Character(const Character& other);
    //each chcaracter has a different destructor therefore need virtual
    virtual ~Character();

    Character& operator=(const Character& other); // Copy assignment operator
    Character(Character&& other) noexcept; // Move constructor
    Character& operator=(Character&& other) noexcept; // Move assignment operator

    //all kinds of character do the same therefore there is no need of virtual
    bool isAlive();
    double distance(Character* other);
    void hit(int damage);
    string getName();
    // Point getLoactaion();
    int getHP();
    Point getPlace();
    void setPlace(const Point& new_place);

    //each chcaracter has a different print therefore need virtual
    virtual string print();
};

#endif
