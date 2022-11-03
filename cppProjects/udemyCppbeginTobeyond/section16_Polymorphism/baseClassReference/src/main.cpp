#include <iostream>

using namespace std;

class Account {
    private:
    double balance;

    protected:
    static constexpr double def_balance = 5000;

    public:
    Account () 
        : balance {def_balance} {

        }
    virtual bool withdraw (double amount) {
        if (balance-amount > 0) {
            balance -= amount;
            cout << "Account::withdraw :" << amount << endl;
            return true;
        }
        else {
            return false;
        }
    }

    virtual ~Account () {};


};

class Checking: public Account {
    private:
    double balance;

    protected:
    static constexpr double def_balance = 5000;
    static constexpr double withdrawl_fee = 3.5;

    public:
    Checking () 
        :balance {def_balance} {

        }
    virtual bool withdraw (double amount) {
        amount += withdrawl_fee;
        if (balance - amount > 0) {
            balance -= amount;
            cout << "Checking::withdraw :" << amount << endl;
            return true;
        }
        else {
            return false;
        }
    }

    virtual ~Checking () {};

};

class Savings: public Account {
    private:
    double balance;

    protected:
    static constexpr double def_balance = 10000;

    public:
    Savings () 
        :balance {def_balance} {

        }
    virtual bool withdraw (double amount) {
        if (balance-amount > 0) {
            balance -= amount;
            cout << "Savings::withdraw :" << amount << endl;
            return true;
        }
        else {
            return false;
        }
    }

    virtual ~Savings () {};

};

class Trust: public Account {
    private:
    double balance;
    int withdrawls;

    protected:
    static constexpr double def_balance = 50000;
    static constexpr int max_withdrawls = 3;

    public:
    Trust () 
        : balance {def_balance}, withdrawls {0} {

        }
    virtual bool withdraw (double amount) {
        if (balance-amount > 0 && withdrawls < max_withdrawls) {
            withdrawls++;
            balance -= amount;
            cout << "Trust::withdraw :" << amount << endl;
            return true;
        }
        else {
            return false;
        }
    }

    virtual ~Trust () {};

};

void do_withdrawl (Account &acc, double amount) {
    acc.withdraw(amount);
}

int main () {
    Account a {};
    Checking c {};
    Savings s {};
    Trust t {};
    
    Account &ref1 = a;
    Account &ref2 = t;

    ref1.withdraw(10);
    ref2.withdraw(20);

    do_withdrawl(a, 100);
    do_withdrawl(c, 200);
    do_withdrawl(s, 300);
    do_withdrawl(t, 400);




    return 0;
}