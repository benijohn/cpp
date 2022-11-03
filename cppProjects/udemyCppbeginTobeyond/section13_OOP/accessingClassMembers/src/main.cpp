#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
    public:
    string name {};
    int health {};
    int xp {};


    void talk(string s) {
        cout << name << " says: " << s << endl;
    }
    bool is_dead();

};

class Account {
    public:
    string name {};
    double balance {};


    bool deposit(double amount) {
        balance += amount;
        return true;
    }
    bool withdraw(double amount){
        balance -= amount;
        return true;
    }
};


int main () {
    Account frank_account;
    frank_account.name = "Frank's accont";
    frank_account.balance = 5000.0;
    frank_account.deposit(1300);
    frank_account.withdraw(80);


    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    
    frank.talk("How are you doing today?");

    Player *enemy = new Player;
    (*enemy).name = "Josh";
    enemy->xp = 15;
    enemy->talk("You better look out Frank!!");

    delete enemy; 



    return 0;
}