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
    void set_name (std::string name_val) {
        name = name_val;
    }
    std::string get_name() const {return name;}
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

void display_player_name (const Player &p) {
    std::cout << p.get_name() << std::endl;
}

int main () {
    const Player villian {"Villian", 100, 150};
    Player hero {"Hero", 100, 45};

    //villian.set_name("Super Villian");
    villian.get_name();
    display_player_name(hero);
    display_player_name(villian);


}