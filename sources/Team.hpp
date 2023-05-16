#ifndef TEAM
#define TEAM

#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <list>

constexpr int SIZE = 10;

namespace ariel {

class Team {
private:
    std::list<Character> team;
    Character* leader;

public:
    Team(Character* char_leader);
    Team(const Team& other);
    Team(Team&& other) noexcept; // Marked as noexcept
    Team& operator=(const Team& other);
    Team& operator=(Team&& other) noexcept;
    ~Team();

    void add(Character* new_char);
    void attack(Team* enemy_team);
    int stillAlive();
    void print();
};

} // namespace ariel

#endif
