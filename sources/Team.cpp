#include "Team.hpp"
#include <limits>

using namespace ariel;

Team::Team(Character* char_leader) : leader(char_leader) {
    team.emplace_back(char_leader);
}

Team::Team(const Team& other_team) : team(other_team.team), leader(other_team.leader) {
    // Create copies of the characters in the other team
    // for (auto member : other.team) {
    //     if(member.getType()==1){//Cowboy
    //         Character* newCharacter = &member;
    //         team.emplace_back(newCharacter);
    //         if (member == other.leader) {
    //             leader = newCharacter;
    //         }
    //     }
    // }
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
    team.emplace_back(new_char);//didn't use push because thar way is more efficient
}
void Team::attack(Team* enemy_team){

    if(enemy_team == NULL){
        throw runtime_error ("enemy team is null");
    }
    cout << "in team : 1" << endl;
    if(this->stillAlive()==0){
        throw runtime_error ("enemy team is alredy dead");
    }
    cout << "in team : 2" << endl;
    if(!leader->isAlive()){
        set_closest(this);
    }
    cout << "in team : 3" << endl;
    Character* victim = set_closest(enemy_team);
    int c = 0;
    for(Character* member : team){
        c++;
        cout << "in team : c = " << c << endl;
        if(enemy_team->stillAlive() == 0){
            return;
        }
        if(!victim->isAlive()){
            victim = set_closest(enemy_team);
        }
        if(victim->getType()==1){//The Character is a Cowboy
            Cowboy* tmp_cowboy = static_cast<Cowboy*>(member);
            tmp_cowboy->shoot(victim);
        }
    }
    cout << "in team : 4" << endl;
    c = 1;
    for(Character* member : team){
        cout << "in team : c = " << c << endl;
        if(enemy_team->stillAlive() == 0){
            return;
        }
        cout << "in team : c = " << c << endl;
        if(!victim->isAlive()){
            victim = set_closest(enemy_team);
        }
        cout << "in team : c = " << c << endl;
        if(victim->getType()==0){//The Character is a Ninja
            cout << "here" << endl;
            Ninja* tmp_ninja = static_cast<Ninja*>(member);//My friend "Yuval yurzd" helped me with it.
             cout << "here2" << endl;
            tmp_ninja->slash(victim);
             cout << "here3" << endl;
        }
        cout << "in team : c = " << c << endl;
    }
}

Character* Team::set_closest(Team* group){
    double min = std::numeric_limits<double>::max();
    double dist = 0;
    Character* answer  = leader;
    for(Character* member : group->team){
        if(member->getType()==1){//Cowboy
            if(this->leader != member && member->isAlive())
                dist = this->leader->distance(member);
                if(dist < min){
                    min = dist;
                    answer = member;
                }
        }
    }
    for(Character* member : group->team){
        if(member->getType()==0){//Ninja
            if(this->leader != member && member->isAlive())
                dist = this->leader->distance(member);
                if(dist < min){
                    min = dist;
                    answer = member;
                }
        }
    }
    return answer;
}

int Team::stillAlive(){
    int how_many_alive = 0;
    for(Character* member : team){
        if(member->getType()==1){//Cowboy
            if(member->isAlive()){
                how_many_alive++;
            }
        }
    }

    for(Character* member : team){
        if(member->getType()==0){//Ninja
            if(member->isAlive()){
                how_many_alive++;
            }
        }
    }

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