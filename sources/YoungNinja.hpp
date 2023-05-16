#ifndef YOUNGNINJA
#define YOUNGNINJA
#include "Ninja.hpp"
#include "Point.hpp"

class YoungNinja : public Ninja
{
    private:
    
    public:
        YoungNinja(string name, Point place);
        string print() override;
        void move(Character *enemy) override;
    
};
#endif

