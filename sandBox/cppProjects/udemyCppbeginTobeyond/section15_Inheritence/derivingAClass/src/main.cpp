#include <iostream>
#include "account.h"
#include "savings_account.h"


using namespace std;

int main () {
    cout << "\n====Account==========================" << endl;
    Account acc {};
    acc.deposit();
    acc.withdraw();


    Account *pcc = new Account {};
    pcc->deposit();
    pcc->withdraw();

    delete pcc;
    cout << "=======================================" << endl;

    cout << "\n\n====SavingsAccount===================" << endl;
    SavingsAccount sacc {};
    sacc.deposit();
    sacc.withdraw();

    SavingsAccount *psacc = new SavingsAccount {};
    psacc->deposit();
    psacc->withdraw();
    delete psacc;
    cout << "========================================" << endl;

    return 0;
}