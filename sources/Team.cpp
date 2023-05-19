#include "Team.hpp"
#include <limits>

using namespace ariel;

Team::Team(Character* char_leader) : leader(char_leader) {
    if(char_leader->getInTeam()){
        throw runtime_error ("can't be in different groups");
    }
    team.emplace_back(char_leader);
    char_leader->setInTeam(true);
}

Team::Team(const Team& other_team) : team(other_team.team), leader(other_team.leader) {
}

Team::Team(Team&& other) noexcept : team(std::move(other.team)), leader(other.leader) {
}

Team::~Team() {
    for (Character* character : team) {
        delete character; // Deallocate memory for each character
    }
    team.clear(); // Clear the list of characters
}

Team& Team::operator=(const Team& other)
{
    if (this != &other) {
        team = other.team;
        leader = other.leader;
    }
    return *this;
}

Team& Team::operator=(Team&& other) noexcept
{
    if (this != &other) {
        team = std::move(other.team);
        leader = other.leader;
        other.leader = nullptr;

    }
    return *this;
}

void Team::add(Character* new_char){
    if(team.size()>=10){
        throw runtime_error ("can't be more then 10 members");
    }
    if(new_char->getInTeam()){
        throw runtime_error ("can't be in different groups");
    }
    team.emplace_back(new_char);//didn't use push because thar way is more efficient
    new_char->setInTeam(true);
}
void Team::attack(Team* enemy_team){

    if(enemy_team == nullptr){
        throw invalid_argument ("enemy team is null");
    }
    if(this->stillAlive()==0){
        throw runtime_error ("enemy team is alredy dead");
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
                if(victim == nullptr){
                    return;
                }
            }
            if(member->getType()==1){//The Character is a Cowboy
                Cowboy* tmp_cowboy = static_cast<Cowboy*>(member);
                if(tmp_cowboy->hasboolets()){
                    tmp_cowboy->shoot(victim);
                }
                else{
                    tmp_cowboy->reload();
                }
            }
        }
    }
    for(Character* member : team){
        if(member->isAlive()){
            if(enemy_team->stillAlive() == 0){
                return;
            }
            if(!victim->isAlive()){
                victim = set_closest(enemy_team);
                if(victim == nullptr){
                    return;
                }
            }
            if(member->getType()==0){//The Character is a Ninja
                Ninja* tmp_ninja = static_cast<Ninja*>(member);//My friend "Yuval yurzd" helped me with it.
                if(tmp_ninja->distance(victim)<1){
                    tmp_ninja->slash(victim);
                }
                else{
                    tmp_ninja->move(victim);
                }
            }
        }
    }
}

Character* Team::set_closest(Team* group){
    double min = std::numeric_limits<double>::max();
    double dist = 0;
    Character* answer  = nullptr;
    for(Character* member : group->team){
        if(member->getType()==1){//Cowboy
            if(this->leader != member && member->isAlive() == 1){
                dist = this->leader->distance(member);
                if(dist < min){
                    // // cout << "new victim = " << member->print() <<endl;
                    // bool a = member->isAlive();
                    // cout << a << endl;

                    min = dist;
                    answer = member;
                }
            }
        }
    }
    for(Character* member : group->team){
        if(member->getType()==0){//Ninja
            if(this->leader != member && member->isAlive() == 1){
                // cout << "new victim = " << member->print() <<endl;
                    // bool a = member->isAlive();
                    // cout << a << endl;
                // dist = this->leader->distance(member);
                if(dist < min){
                    min = dist;
                    answer = member;
                }
            }
        }
    }
    return answer;
}

int Team::stillAlive(){
    // cout << "lives: " << endl;
    int how_many_alive = 0;
    // cout << "in cowboy" << endl;
    for(Character* member : team){
        if(member->getType()==1){//Cowboy
            if(member->isAlive() ==1){
                // cout << member->print() << endl;
                how_many_alive++;
            }
        }
    }
    // cout << "out of cowboy" << endl;

    // cout << "in ninja" << endl;
    for(Character* member : team){
        if(member->getType()==0){//Ninja
            if(member->isAlive() == 1){
                // cout << member->print() << endl;
                how_many_alive++;
            }
        }
    }
    //     cout << "out of ninja" << endl;
    // cout << endl;

    return how_many_alive;
}

void Team::print(){
    for(Character* member : team){
        if(member->getType()==1){
            Cowboy* tmp_cowboy = static_cast<Cowboy*>(member);
            tmp_cowboy->print();
        }
    }

    for(Character* member : team){
        if(member->getType() == 0){//Ninja
            Ninja* tmp_ninja = static_cast<Ninja*>(member);
            tmp_ninja->print();
        }
    }

}