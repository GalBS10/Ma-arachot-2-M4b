#ifndef TRAINEDNINJA
#define TRAINEDNINJA
#include "Ninja.hpp"
#include "Point.hpp"

class TrainedNinja : public Ninja
{
    private:
        
    public:
        TrainedNinja(string name, Point place);
        string print() override;
        void move(Character *enemy) override;
    
};
#endif