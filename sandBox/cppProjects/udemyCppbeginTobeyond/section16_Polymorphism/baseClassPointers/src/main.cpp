#include <iostream>
#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"
#include "trustAccount.h"

using namespace std;

int main () {
    cout << "\n========== Pointers ==========" << endl;

    Account *p1 = new Account;
    Account *p2 = new SavingsAccount;
    Account *p3 = new CheckingAccount;
    Account *p4 = new TrustAccount;

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    Account *array [] = {p1,p2,p3,p4};

    //for (auto acc: array)


    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}