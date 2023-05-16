#include "Team.hpp"

using namespace ariel;

Team::Team(Character* char_leader){

}

Team::Team(const Team& other) : team(other.team), leader(other.leader)
{
    // Copy constructor implementation
    // You can add any necessary additional copying logic here
}

Team::Team(Team&& other) noexcept : team(std::move(other.team)), leader(other.leader)
{
    other.leader = nullptr;
    // Move constructor implementation
    // You can add any necessary additional moving logic here
}

Team& Team::operator=(const Team& other)
{
    if (this != &other) {
        team = other.team;
        leader = other.leader;
        // Copy assignment operator implementation
        // You can add any necessary additional copying logic here
    }
    return *this;
}

Team& Team::operator=(Team&& other) noexcept
{
    if (this != &other) {
        team = std::move(other.team);
        leader = other.leader;
        other.leader = nullptr;
        // Move assignment operator implementation
        // You can add any necessary additional moving logic here
    }
    return *this;
}
Team::~Team(){

}
void Team::add(Character* new_char){

}
void Team::attack(Team* enemy_team){

}
int Team::stillAlive(){
    return 0;
}
void Team::print(){
    
}