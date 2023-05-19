#include "Team2.hpp"
#include <limits>

Team2::Team2(Character* char_leader) : Team(char_leader)
{

}


// Team2::~Team2() 
// {
 
// }

Character* Team2::set_closest(Team* group) 
{
    double min = std::numeric_limits<double>::max();
    double dist = 0;
    Character* answer  = leader;
    for(Character* member : team){
        if(this->leader != member && member->isAlive())
            dist = this->leader->distance(member);
            if(dist < min){
                min = dist;
                answer = member;
            }
    }
    return answer;
}

void Team2::attack(Team* enemy_team)
{
    if(enemy_team == nullptr){
        throw invalid_argument ("enemy team is null");
    }
    if(this->stillAlive()==0){
        return;
    }
    if(!leader->isAlive()){
        set_closest(this);
    }
    Character* victim = set_closest(enemy_team);
    for(Character* member : team){
        if(member->isAlive()){
            if(enemy_team->stillAlive() == 0){
                return;
            }
            if(!victim->isAlive()){
                victim = set_closest(enemy_team);
            }
            if(victim->getType()==0){//The Character is a Ninja
                Ninja* tmp_ninja = static_cast<Ninja*>(member);//My friend "Yuval yurzd" helped me with it.
                tmp_ninja->slash(victim);
            }
            else{//The Character is a Cowboy
                Cowboy* tmp_cowboy = static_cast<Cowboy*>(member);
                tmp_cowboy->shoot(victim);
            }
        }
    }

}
void Team2::print() 
{
    for(Character* member : team){
        if(member->getType() == 0){//Ninja
            Ninja* tmp_ninja = static_cast<Ninja*>(member);
            tmp_ninja->print();
        }
        else{
            Cowboy* tmp_cowboy = static_cast<Cowboy*>(member);
            tmp_cowboy->print();
        }
    }

}