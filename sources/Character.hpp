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
    virtual ~Character();
    Character(const Character& other);
    Character& operator=(const Character& other); // Copy assignment operator
    Character(Character&& other) noexcept; // Move constructor
    Character& operator=(Character&& other) noexcept; // Move assignment operator
    bool isAlive();
    double distance(Character* other);
    void hit(int damage);
    std::string getName();
    Point getLoactaion();
    int getHP();
    Point getPlace();
    // virtual std::string print();
};

#endif
