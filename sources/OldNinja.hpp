#ifndef OLDNINJA
#define OLDNINJA
#include "Ninja.hpp"
#include "Point.hpp"

class OldNinja : public Ninja
{
    private:

    public:
        OldNinja(string name, Point place);
        string print();
        void move(Character *enemy) override;


};
#endif