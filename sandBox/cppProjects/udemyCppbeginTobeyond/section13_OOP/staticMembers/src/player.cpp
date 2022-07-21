#include "player.h"

int Player::num_players = 0;

int Player::get_num_players() {
    return num_players;
}

Player::Player (std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
        num_players++;
        std::cout << "Three args constructor called for " + name << std::endl;
    }

Player::Player (const Player &source)
    : name {source.name}, health {source.health}, xp {source.xp} {
        std::cout << "copy constructor called: copies made for:" << source.name << std::endl;
} 

Player::~Player() {
    num_players--;
    std::cout << "destructor called for " + name << std::endl;
}