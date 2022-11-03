#include <iostream>

using namespace std;

class Player {
    private:
    string name;
    int health;
    int xp;

    public:

    Player ();
    Player (string name_val);
    Player (string name_val, int health_val, int xp_val);

};

// overloaded constructors
Player::Player (): Player {"none", 0, 0} {
    cout << "no args constructor" << endl;
};

Player::Player (string name_val): Player {name_val, 0, 0} {
    cout << "one args constructor" << endl;
};

Player::Player (string name_val, int health_val, int xp_val): name {name_val}, health {health_val}, xp {xp_val} {
    cout << "three args constructor" << endl;
};

int main () {
    Player empty;
    Player frank {"frank"};
    Player villian ("Villian", 150, 2000);


    return 0;
}