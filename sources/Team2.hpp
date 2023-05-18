#ifndef TEAM2
#define TEAM2
#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Team.hpp"
#include <list>

namespace ariel{};

class Team2 : public Team
{
    private:
        
    public:
        Team2(Character* char_leader);
        // ~Team2() override;

        Character* set_closest(Team* group) override;
        void attack(Team* enemy_team) override;
        void print() override;

};


#endif