#include <iostream>

using namespace std;

class Player {
    private:
    string name;
    int age;
    int health;
    int xp;

    public:
    void set_name(string n) {
        name = n;
    }

    
    Player() {
        cout << "no args constructor called" << endl;
    }
    Player(string name_val) {
        name = name_val;
        cout << "name arg constructor called" << endl;
    }
    Player(string name_val, int age_val, int health_val, int xp_val) {
        name = name_val;
        age = age_val;
        health = health_val;
        xp = xp_val;
        cout << "four args called" << endl;
    }
    ~Player() {
        cout << "destructor called for " << name << endl;
    }

};

int main () {
    {
        Player slayer;
        slayer.set_name("slayer");
    }

    {
        Player frank;
        frank.set_name("Frank");
        Player hero {"hero"};
        hero.set_name("hero");
        Player villain {"Villian", 34, 100, 150};
        villain.set_name("Villain");
    }

    Player *enemy = new Player {"Final Boss", 28, 110, 1000};
    delete enemy;


    return 0;
}
