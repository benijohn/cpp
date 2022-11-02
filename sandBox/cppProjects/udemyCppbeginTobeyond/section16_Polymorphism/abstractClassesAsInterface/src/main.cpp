#include <iostream>

class Account {
    friend std::ostream &operator<< (std::ostream &os, const Account &acc);

    public:
    virtual void withdraw (double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }

    virtual ~Account () {};

};

std::ostream &operator<< (std::ostream &os, const Account &acc) {
        os << "Account display";
        return os;
    }

class Checking: public Account {
    friend std::ostream &operator<< (std::ostream &os, const Checking &acc);

    public:
    virtual void withdraw (double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    
    virtual ~Checking () {};

};

std::ostream &operator<< (std::ostream &os, const Checking &acc) {
        os << "Checking display";
        return os;
    }

class Savings: public Account {
    friend std::ostream &operator<< (std::ostream &os, const Savings &acc);

    public:
    virtual void withdraw (double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }

    virtual ~Savings () {};

}; 

std::ostream &operator<< (std::ostream &os, const Savings &acc) {
    os << "Savings display";
    return os;
}

int main () {
    // this works, but it is clunky we have to override the instertion operator for every class... there must be a better way. go to interfaces complete!!

    return 0;
}