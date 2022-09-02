#pragma once

class Base {
    public:
    Base ();
    Base (int val);
    Base (const Base &source);
    //Base (Base &&source);
    ~Base ();

    Base &operator= (const Base &rhs);
    //Base &operator= (Base &&rhs); only necessary if we have pointers in the class
    
    void display ();

    private:
    int num;
};