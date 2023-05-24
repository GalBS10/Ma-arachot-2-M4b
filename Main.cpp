#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/Team2.hpp"
#include "sources/smartTeam.hpp"

using namespace ariel;

int main() {
    // Create characters dynamically
    Cowboy* cowboy1 = new Cowboy("John", Point(0, 0));
    Cowboy* cowboy2 = new Cowboy("Mike", Point(100, 100));
    Cowboy* cowboy3 = new Cowboy("David", Point(200, 200));

    OldNinja* ninja1 = new OldNinja("Hanzo", Point(500, 500));
    OldNinja* ninja2 = new OldNinja("Ryu", Point(600, 600));
    OldNinja* ninja3 = new OldNinja("Ken", Point(700, 700));

    YoungNinja* ninja4 = new YoungNinja("Sasuke", Point(1000, 1000));
    YoungNinja* ninja5 = new YoungNinja("Naruto", Point(1100, 1100));
    YoungNinja* ninja6 = new YoungNinja("Sakura", Point(1200, 1200));

    TrainedNinja* ninja7 = new TrainedNinja("Kakashi", Point(1500, 1500));
    TrainedNinja* ninja8 = new TrainedNinja("Itachi", Point(1600, 1600));
    TrainedNinja* ninja9 = new TrainedNinja("mo", Point(1700, 1700));

    // Create teams
    Team2 team2(ninja4);
    team2.add(ninja5);
    team2.add(cowboy3);
    team2.add(ninja1);
    team2.add(ninja2);
    team2.add(ninja3);

    smartTeam smartTeam(cowboy1);
    smartTeam.add(cowboy2);
    smartTeam.add(ninja6);
    smartTeam.add(ninja7);
    smartTeam.add(ninja8);
    smartTeam.add(ninja9);
    
    // Simulate the battle until one team is defeated
    while (team2.stillAlive() > 0 && smartTeam.stillAlive() > 0) {
        team2.attack(&smartTeam);
        smartTeam.attack(&team2);
    }
    cout << "-----smart stat-----" << endl;
    smartTeam.print();
    cout << "----- end ------" << endl;
    cout << "------team2 stat-------" << endl;
    team2.print();
    cout << "----- end ------" << endl;
    // Print the winner
    if (team2.stillAlive() > 0) {
        cout << "Team2 wins!" << endl;
    } else {
        cout << "smartTeam wins!" << endl;
    }


    return 0;
}

