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
    cout << "----------set_closest------------" << endl;
    double min = std::numeric_limits<double>::max();
    double dist = 0;
    Character* answer  = nullptr;
    for(Character* member : group->team){
        if(this->leader != member && member->isAlive()){
        cout << member->print() << endl;
            dist = this->leader->distance(member);
            if(dist < min){
                min = dist;
                answer = member;
            }
        }
    }
    cout << "answer : " << answer->print() << endl;
    cout << "----------out of set_closest------------" << endl;
    return answer;
}

void Team2::attack(Team* enemy_team)
{
    cout << "\n-------------team2---------------\n" <<endl;
    cout << "----------attacker stats---------" << endl;
    this->print();
    cout << "----------defender stats---------" << endl;
    if(enemy_team != nullptr)
    enemy_team->print();


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
        cout << "\n leader is dead \n" << endl;
        leader = this->set_closest(this);
        cout << "new leader is : " << leader->print() << endl;
    }
    Character* victim = this->set_closest(enemy_team);
    for(Character* member : team){
        cout << "in for" << endl;
        if(member->isAlive()){
            cout << "attacker is : " << member->print() << endl;
            cout << "victim is : " << victim->print() << endl;
            if(enemy_team->stillAlive() == 0){
                return;
            }
            cout << "1" << endl;
            if(!victim->isAlive()){
                cout << "victim is dead" << endl;
                victim = this->set_closest(enemy_team);
                if(victim == nullptr){
                    return;
                }
            }
            cout << "2" << endl;
            if(member->getType()==0){//The Character is a Ninja
                Ninja* tmp_ninja = static_cast<Ninja*>(member);//My friend "Yuval yurzd" helped me with it.
                if(tmp_ninja->distance(victim)<1){
                    tmp_ninja->slash(victim);
                }
                else{
                    tmp_ninja->move(victim);
                }
            }
            else{//The Character is a Cowboy
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

}
void Team2::print() 
{
    for(Character* member : team){
        if(member->getType() == 0){//Ninja
            Ninja* tmp_ninja = static_cast<Ninja*>(member);
            cout <<tmp_ninja->print() << endl;
        }
        else{
            Cowboy* tmp_cowboy = static_cast<Cowboy*>(member);
            cout << tmp_cowboy->print() << endl;
        }
    }

}