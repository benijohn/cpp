#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Deep {
    private:
    int *data;

    public:
    void set_data_value (int d) {*data = d;}
    int get_data_value () {return *data;}
    Deep (int d);
    Deep (const Deep &source);

    ~Deep();
};

Deep::Deep (int d) {
    data = new int;
    *data = d;
};

/// This is the important part! It must be done for classes with raw pointers!!
Deep::Deep (const Deep &source) {
    data = new int;
    *data = *source.data;
    cout << "copy constructor" << endl;
    }

Deep::~Deep() {
    delete data;
    cout << "destructor called" << endl;
}

void display_Deep(Deep d) {
    cout << d.get_data_value() << endl;
}
int main () {
    Deep obj1 {100};
    display_Deep (obj1);

    Deep obj2 {obj1};
    obj2.set_data_value (1000);


    return 0;
}