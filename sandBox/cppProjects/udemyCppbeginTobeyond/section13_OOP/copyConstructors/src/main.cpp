#include <iostream>
#include <string>
#include <vector>


class Player {
    private:
    std::string name;
    int health;
    int xp;

    public:
    // methods
    std::string get_name() {return name;}
    int get_health() {return health;}
    int get_xp() {return xp;}
    // constructors
    Player(std::string name_val = "None", int health_val = 100, int xp_val = 0);
    // copy constructor
    Player (const Player &source);
    ~Player () {std::cout << "destructor called for " + name << std::endl;}
};

Player::Player (std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
        std::cout << "Three args constructor called for " + name << std::endl;
    }

Player::Player (const Player &source)
    : name {source.name}, health {source.health}, xp {source.xp} {
        std::cout << "copy constructor called: copies made for:" << source.name << std::endl;
}    

void display_player (Player p) {
    std::cout << "Name: " << p.get_name() <<  std::endl;
    std::cout << "Health: " << p.get_health() << std::endl;
    std::cout << "XP: " << p.get_xp() << std::endl;
}

int main () {
    Player empty {"xxxx", 234, 43};

    Player copy_player {empty};

    display_player (empty);

    Player frank {"Franke"};
    Player hero {"Hero", 150, 35};
    Player villian {"Villian", 200, 40};



}