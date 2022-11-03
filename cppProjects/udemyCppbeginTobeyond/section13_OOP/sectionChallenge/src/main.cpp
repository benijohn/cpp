#include "Movies.cpp" 

using namespace std;

int main () {
    Movies favorites {};

    favorites.display();
    favorites.set_class_name("Favorites");

    favorites.add("StarWars", "R", "One of the best!", 15, 4.7);
    favorites.add("Indiana Jones", "PG-13", "I hate snakes", 12, 4.4);
    favorites.add("Shrek", "PG", "A classic", 3, 4.3);
    
    favorites.display();

    favorites.increment("StarWars");
    favorites.increment("Mando");

    favorites.display();


    favorites.add("Shrek");
    favorites.get_watched_count("Shrek");

    favorites.display("Shrek");

    favorites.set_watched_count("Shrek", 37);
    favorites.display("Shrek");
    favorites.set_notes("Shrek", "Lord Farkwad you imbecil!");
    favorites.display("Shrek");


    return 0;
}