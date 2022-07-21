#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
    private:
    string name {};
    int health {};
    int xp {};

    public:
    void talk(string s) {
        cout << name << " says: " << s << endl;
    }
    bool is_dead();

};




int main () {
    Player frank;
    //frank.name = "Frank"; compiler error inaccessible member
    frank.talk("Hello there.");

    return 0;
}