#include <iostream>
#include <memory>

class Base {
    public:
    void hello () const {
        std::cout << "Hello I am the base class" << std::endl;
    }

};

class Derived: public Base {
    public:
    void hello () const {
        std::cout << "Hello I am the drived class" << std::endl;
    }

};

void greetings (const Base &obj) {
    std::cout << "Greetings";
    obj.hello();
}

int main () {
    Base b;
    b.hello();

    Derived d;
    d.hello();

    greetings(b);
    greetings(d);

    Base *ptr;
    ptr = new Derived();
    ptr->hello();

    Derived *dptr = new Derived();
    dptr->hello();

    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->hello();


    return 0;
}