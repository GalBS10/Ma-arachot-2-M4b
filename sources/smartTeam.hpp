#ifndef SMARTTEAM
#define SMARTTEAM
#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Team.hpp"
#include "Team2.hpp"
#include <list>


class smartTeam : public Team2
{
private:

public:
    smartTeam(Character* char_leader);

    void attack(Team* enemy_team) override;
    Character* set_closest(Team* group) override;//sneak = 1 return null.
    std::list<Character*>* enemy_members_stats(Team* enemy_team);
    Character* get_lowest_enemy(list<Character*> *enemy_team);
};
/*Expaination
    The Cowboys will always shoot the lowest HP Character and that will make the enemy team to lose a Character first (most of the time).
    Therefore, the smart team will have amount advantage.
*/


#endif