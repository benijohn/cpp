#pragma once
#include <string>

class Account {
    public:
    // attributes
    double balance;
    std::string name;
    // methods
    void deposit (double amount);
    void deposit ();
    void withdraw (double amount);
    void withdraw ();
    // constructors/destructor
    Account ();
    ~Account ();

};