#include "account.hpp"
#include "savingsAccount.hpp"

using namespace std;

int main () {
    Account acc {1000};
    cout << acc << endl;

    acc.deposit(500);
    cout << acc << endl;

    acc.withdraw(1000);
    cout << acc << endl;

    acc.withdraw(5000);
    cout << acc << endl;


    SavingsAccount sacc {1000, 7.5};
    cout << sacc << endl;

    sacc.deposit(1000);
    cout << sacc << endl;

    sacc.withdraw(2000);
    cout << sacc << endl;

    sacc.withdraw(2000);
    cout << sacc << endl;  


}