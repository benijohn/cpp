#include <iostream>

using namespace std;

class Base {
    private:
    int num;

    public:
    Base () : num {0} {cout << "Base no-args constructor" << endl;};
    Base (int n) : num {n} {cout << "Base overloaded(int) constructor" << endl;};
    ~Base () {cout << "Base desctructor" << endl;};
};

class Derived : public Base {
    private:
    int doubled_value;

    public:
    Derived () : Base {}, doubled_value {0} {cout << "Derived no-args constructor" << endl;};
    Derived (int n) : Base(n), doubled_value {2*n} {cout << "Derived overloaded(int) constructor" << endl;};
    ~Derived () {cout << "Derived destructor" << endl;};
};


int main () {
    Base b;

    Derived d;

    Derived d2 {3};

    return 0;
}