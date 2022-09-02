#pragma once
#include "base.hpp"

class Derived: public Base {
    public:
    Derived ();
    Derived (int val);
    Derived (const Derived &source);
    //Derived (Derived &&source);
    ~Derived ();

    Derived &operator= (const Derived &rhs);

    void display ();

    private:
    int num2;
};