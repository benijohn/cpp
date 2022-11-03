#include <iostream>
#include "account.h"
#include "savings_account.h"


using namespace std;

class Base {
    // Friends of Base will have access to everything in Base
    public:
    int a {0};
    void display () {
        cout << a <<  "," <<  b <<  "," << c << endl; // member method has access to everything
    }

    protected:
    int b {0};

    private:
    int c {0};
};

class Derived: public Base {
    // Friends of Derived will only have access to what Derrived has access to.
    // a is public in Derived
    // b is protected in Derived
    // c has no access in Derived

    void access_base_members () {
        a = 100;
        b = 200;
        //c = 300;   // compiler error
    }

};

int main () {
    Base base;

    cout << "====== Base Member access from Base objects =======" << endl;
    base.a = 100;  // ok
    //base.b = 200;  // compiler error
    //base.c = 300;  // compiler error

    cout << "====== Base Member access from Derived objects =====" << endl;
    Derived d;
    d.a = 100;
    //d.b = 200;  // compiler error
    //d.c = 300;  // compiler error

    return 0;
}