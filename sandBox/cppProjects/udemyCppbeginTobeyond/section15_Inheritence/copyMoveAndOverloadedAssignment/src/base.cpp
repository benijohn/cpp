#include <iostream>
#include "base.hpp"

Base::Base ()
    : num {0} {
        std::cout <<  "Base no-args constructor" << std::endl;
    }

Base::Base (int val)
    : num {val} {
        std::cout << "Base int-arg constructor" << std::endl;
    }

Base::Base (const Base &source)
    : Base {source.num} {
        std::cout << "Base copy construcor" << std::endl;
    }

Base::~Base () {
    std::cout << "Base destructor" << std::endl;
}  

// copy assignment
Base &Base::operator= (const Base &rhs) {
    std::cout << "Base copy assignment" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    num = rhs.num;
    return *this;
}

void Base::display () {
    std::cout << num << std::endl;
}