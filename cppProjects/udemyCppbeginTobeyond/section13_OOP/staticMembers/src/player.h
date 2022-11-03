#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>

class Player {
    private:
    static int num_players;
    std::string name;
    int health;
    int xp;

    public:
    // methods
    static int get_num_players(); 
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
    ~Player ();
};


#endif