#include <iostream>
#include <string>

using namespace std;

class Account {
    private:
    string name {};
    int balance {};
    

    public:
    void set_balance(double amount) {
        balance += amount;
    }
    double get_balance() {
        return balance;
    }

    void set_name(string n);
    string get_name() {
        return name;
    }
    bool deposit (double amount);
    bool withdraw (double amount);

};

void Account::set_name (string n) {
    name = n;
}

bool Account::deposit (double amount) {
    balance += amount;
    return true;
}

bool Account::withdraw (double amount) {
    if (balance-amount > 0){
        balance -= amount;
        return true;
    }
    else {
        cout << "Insufficient funds, your current balance is " << balance << endl;
        return false;
    }    
}


int main () {
    Account frank;
    frank.set_name("Frank");
    frank.set_balance(10000);

    frank.deposit(2300);
    frank.withdraw(500);
    frank.withdraw(20000);


    return 0;
}