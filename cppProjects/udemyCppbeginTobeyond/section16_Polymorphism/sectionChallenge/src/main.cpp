#include "i_printable.h"
#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"
#include "trustAccount.h"
#include "accountUtils.h"
#include <vector>

using namespace std;

int main () {
    Savings ben {"Ben", 10000, 5};
    Checking melissa {"Melissa", 245000};
    Trust napoleon {"Napoleon", 432000, 17.8};

    Account *a1 = new Savings {"Neppy", 45000, 6};
    Account *a2 = new Checking {"Everyday Expenses", 3475};
    Account *a3 = new Trust {"College Savings", 25000, 11.4};
    Account *a4 = &ben;


    cout << a1 << endl;
    cout << *a1 << endl;
    cout << ben << endl;
    cout << *a4 << endl;

    vector<Account *> accounts;
    accounts.push_back(a1);
    accounts.push_back(a2);
    accounts.push_back(a3);

    for (const auto acc: accounts) {
        cout << *acc << endl;
    }

    cout << "\n==========================\n" << endl;
    print(accounts);

    deposit(accounts, 10000);
    withdraw(accounts, 500);

    delete a1;
    delete a2;
    delete a3;

    return 0;
}