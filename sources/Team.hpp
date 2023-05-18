#ifndef TEAM
#define TEAM

#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
// #include "Team2.hpp"
#include <list>

constexpr int SIZE = 10;

namespace ariel {};

class Team {
    private:

    public:
        std::list<Character*> team;
        Character* leader;
        Team(Character* char_leader);
        Team(const Team& other);
        Team(Team&& other) noexcept; // Marked as noexcept
        Team& operator=(const Team& other);
        Team& operator=(Team&& other) noexcept;
        virtual ~Team();

        void add(Character* new_char);
        virtual void attack(Team* enemy_team);
        int stillAlive();
        virtual void print();
        virtual Character* set_closest(Team* group);
};

 // namespace ariel

#endif
