#include <iostream>

using namespace std;

class Base {
    public:
    virtual void say_hello () const {
        cout << "Hello I am a base class." << endl;
    }

    virtual ~Base () {};
};

class Derived: public Base {
    public:
    virtual void say_hello() const override{
        cout << "Hello I am a derived class" << endl;
    }

    virtual ~Derived () {};
};

int main () {
    Base *b = new Base {};
    Derived *d = new Derived{};
    Base *bd = new Derived {};

    b->say_hello();
    d->say_hello();
    bd->say_hello();


    delete b;
    delete d;
    delete bd;

    return 0;
}