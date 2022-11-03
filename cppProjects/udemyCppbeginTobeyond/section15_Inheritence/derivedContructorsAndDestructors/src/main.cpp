#include <iostream>

using namespace std;

class Base {
    private:
    int num;

    public:
    Base () : num {0} {cout << "Base No-Args constructor" << endl;};
    Base (int val) : num {val} {cout << "Base Overloaded (int) constructor" << endl;};
    ~Base() {cout << "Base Destructor" << endl;};
};

class Derived : public Base {
    private:
    int doubled_val;
    public:
    // Derived () : doubled_val {0} {cout << "Derived No Args Constructor" << endl;};
    // Derived (int x) : doubled_val {2*x} {cout << "Derived Overloaded (int) constructor" << endl;};
    // ~Derived () {cout << "Derived Destructor" << endl;};
};

int main () {
    Base b;

    return 0;
}