#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account {
    // attributes
    private:
    std::string name {};
    int balance {};
    
    // methods
    public:
    void set_balance(double amount);
    double get_balance();

    void set_name(std::string n);
    std::string get_name();
    bool deposit (double amount);
    bool withdraw (double amount);

};



#endif