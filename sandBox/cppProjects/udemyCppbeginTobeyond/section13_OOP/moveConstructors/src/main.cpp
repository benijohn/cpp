#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Move {
    private:
    int *data;

    public:
    void set_data_value (int d) {*data = d;}
    int get_data_value () {return *data;}
    Move (int d);
    Move (const Move &source);
    Move (Move &&source);

    ~Move();
};

Move::Move (int d) {
    data = new int;
    *data = d;
    cout << "constructor called for " << *data << endl;
};

/// This is the important part! It must be done for classes with raw pointers!!
Move::Move (const Move &source) 
    : Move {*source.data} {
    // data = new int;
    // *data = *source.data;
    cout << "copy constructor call for " << *data << endl;
    }

Move::Move (Move &&source)
    : data {source.data} {
        source.data = nullptr;
        cout << "move constructor call for " << *data << endl;
    }

Move::~Move() {
    if (data != nullptr) {
        cout << "destrucor called for " << *data << endl;
    }
    else {
        cout << "destructor called for nullptr" << endl;
    }
    delete data;
}

void display_Move(Move d) {
    cout << d.get_data_value() << endl;
}
int main () {
    vector<Move> vec {};

    vec.push_back(Move {10});

    vec.push_back(Move {20});
    vec.push_back(Move {30});
    vec.push_back(Move {40});
    vec.push_back(Move {50});
    vec.push_back(Move {60});
    vec.push_back(Move {70});
    vec.push_back(Move {80});
    vec.push_back(Move {90});

    return 0;
}