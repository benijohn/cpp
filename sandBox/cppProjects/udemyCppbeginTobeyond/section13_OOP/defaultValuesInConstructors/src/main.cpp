#include <iostream>

using namespace std;

class Player {
    private:
    string name;
    int health;
    int xp;

    public:

    Player (string name_val = "None", int health_val = 0, int xp_val = 0);

};

Player::Player (string name_val, int health_val, int xp_val):
    name {name_val}, 
    health {health_val}, 
    xp {xp_val} {
    cout << "three args constructor" << endl;
    };

int main () {
    Player empty;
    Player frank {"frank"};
    Player hero {"hero", 100};
    Player villian ("Villian", 150, 2000);


    return 0;
}