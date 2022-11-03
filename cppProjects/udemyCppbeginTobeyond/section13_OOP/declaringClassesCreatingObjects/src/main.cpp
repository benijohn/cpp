#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
    // atributes
    string name;
    int health;
    int xp;

    // methods
    void talk (string s);
    bool isDead ();
};

int main () {
    Player frank;
    Player hero;

    Player players [] {frank, hero};
    
    vector<Player> player_vec {frank};
    player_vec.push_back(hero);

    Player *enemy {};
    enemy = new Player;

    delete enemy;

    return 0;
}