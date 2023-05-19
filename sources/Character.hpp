#ifndef CHARACTER
#define CHARACTER

#include "Point.hpp"
#include <string>

using namespace std;

class Character {
private:
    Point place;
    int HP; // hit point
    string name;
    int type;
    bool in_team;

public:
    Character(Point _place, int hitpoint, string _name, int type);
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
    Point getLocation();
    int getType();
    bool getInTeam();
    void setPlace(const Point& new_place);
    void setInTeam(bool flag);

    //each chcaracter has a different print therefore need virtual
    virtual string print();
};

#endif
