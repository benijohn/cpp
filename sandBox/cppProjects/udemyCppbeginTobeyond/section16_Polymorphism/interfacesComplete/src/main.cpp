#include <iostream>
#include <vector>

class Printable {
    friend std::ostream &operator<< (std::ostream &os, const Printable &obj);
    public:
    virtual void display (std::ostream &os) const = 0;

    virtual ~Printable () {};

};

std::ostream &operator<< (std::ostream &os, const Printable &obj) {
    obj.display(os);
    return os;
}

class Account: public Printable {
    public:
    virtual void withdraw (double amount) = 0;
    virtual void display (std::ostream &os) const override {
        os << "Account display";
    }

    virtual ~Account () {};

};


class Checking: public Account {
    public:
    virtual void withdraw (double amount) override {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual void display (std::ostream &os) const override {
        os << "Checking display";
    }
    
    virtual ~Checking () {};

};


class Savings: public Account {
    public:
    virtual void withdraw (double amount) override {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual void display (std::ostream &os) const override {
        os << "Savings display";
    }

    virtual ~Savings () {};

}; 


class Trust: public Account {

    public:
    virtual void withdraw (double amount) override {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void display (std::ostream &os) const override {
        os << "Trust display";
    }

    virtual ~Trust () {};

};

class Dog: public Printable {
    public:
    virtual void display (std::ostream &os) const override {
        os << "Woof woof";
    }

    virtual ~Dog () {};

};

void print (const Printable &obj) {
    std::cout << obj << std::endl;
}

int main () {
    Dog *dog = new Dog {};
    Account *a2 = new Checking {};
    Account *a3 = new Savings {};
    Account *a4 = new Trust {};

    std::vector<Account *> accounts;

    //accounts.push_back(dog);
    accounts.push_back(a2);
    accounts.push_back(a3);
    accounts.push_back(a4);

    for (const auto account: accounts) {
        std::cout << *account << std::endl;
    }

    print(*dog);
    std::cout << *dog << std::endl;

    delete dog;
    delete a2;
    delete a3;
    delete a4;

    return 0;
}