#include <iostream>
#include "derived.hpp"

Derived::Derived ()
    : Base {}, num2 {0} {
        std::cout << "Derived no-args constructor" << std::endl;
    }

Derived::Derived (int val) 
    : Base {val},  num2 {2*val} {
        std::cout << "Derived int-arg constructor" << std::endl;
    }

Derived::Derived (const Derived &source) 
    : Base {source}, num2 {source.num2} {
        std::cout << "Derived copy constructor" << std::endl;
    }      

Derived::~Derived () {
    std::cout << "Derived destructor" << std::endl;
}    

Derived &Derived::operator= (const Derived &rhs) {
    std::cout << "Derived copy assignment" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    Base::operator= (rhs);
    num2 = rhs.num2;
    return *this;
}


void Derived::display () {
    std::cout << num2 << std::endl;
}