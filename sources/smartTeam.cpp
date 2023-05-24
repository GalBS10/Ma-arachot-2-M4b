#include "smartTeam.hpp"
#include "Team.hpp"
#include "Team2.hpp"
#include <limits>


smartTeam::smartTeam(Character* char_leader) : Team2(char_leader)
{

}

list<Character*>* smartTeam::enemy_members_stats(Team* enemy_team)
{
    return &enemy_team->team;
}

Character* smartTeam::get_lowest_enemy(list<Character*> *enemy_team)
{
    int lowest_HP = 200;//because no one has 200 HP
    int curr_HP = 0;
    Character* answer  = nullptr;

    for(Character* member : *enemy_team){
        if(member->isAlive()){
            curr_HP = member->getHP();
            if(curr_HP<lowest_HP){
                lowest_HP = curr_HP;
                answer = member;
            }
        }
    }
    return answer;
}

void smartTeam::attack(Team* enemy_team)
{
    if(enemy_team == nullptr){
        throw invalid_argument ("enemy team is null");
    }
    if(this->stillAlive()==0){
        throw runtime_error ("team is alredy dead");
    }
    if(enemy_team->stillAlive()==0){
        throw runtime_error ("enemy team is alredy dead");
    }
    if(!leader->isAlive()){
        leader = this->set_closest(this);
    }
    list<Character*>* enemy_team_s = enemy_members_stats(enemy_team);
    Character* c_victim = get_lowest_enemy(enemy_team_s);
    Character* n_victim = this->set_closest(enemy_team);
    if(n_victim == nullptr){
        return;
    }
    if(c_victim == nullptr){
        c_victim = n_victim;
    }
    for(Character* member : team){
        if(member->isAlive()){
            if(enemy_team->stillAlive() == 0){
                return;
            }
            if(!n_victim->isAlive()){
                n_victim = this->set_closest(enemy_team);
                if(n_victim == nullptr){
                    return;
                }
            }
            if(!c_victim->isAlive()){
                c_victim = get_lowest_enemy(enemy_team_s);
                if(c_victim == nullptr){
                    c_victim = n_victim;
                }
            }
            if(member->getType()==0){//The Character is a Ninja
                Ninja* tmp_ninja = static_cast<Ninja*>(member);//My friend "Yuval yurzd" helped me with it.
                if(tmp_ninja->distance(n_victim)<1){
                    tmp_ninja->slash(n_victim);
                }
                else{
                    tmp_ninja->move(n_victim);
                }
            }
            else{//The Character is a Cowboy
                Cowboy* tmp_cowboy = static_cast<Cowboy*>(member);
                if(tmp_cowboy->hasboolets()){
                    tmp_cowboy->shoot(c_victim);
                }
                else{
                    tmp_cowboy->reload();
                }
            }
        }
    }
}

Character* smartTeam::set_closest(Team* group) 
{
    double min = std::numeric_limits<double>::max();
    double dist = 0;
    Character* answer  = nullptr;
    for(Character* member : group->team){
        if(this->leader != member && member->isAlive()){
            dist = this->leader->distance(member);
            if(dist < min){
                min = dist;
                answer = member;
            }
        }
    }
    return answer;
}