#include "player.h"
#include "player.cpp"

void display_active_players() {
    std::cout << "The number of active players is: " << Player::get_num_players() << std::endl;
}


int main () {
    display_active_players();

    Player frank {"Frank"};

    display_active_players();

    Player *battle_bot;
    battle_bot = new Player {"bot"};

    display_active_players();

    delete battle_bot;

    display_active_players();


    return 0;
}