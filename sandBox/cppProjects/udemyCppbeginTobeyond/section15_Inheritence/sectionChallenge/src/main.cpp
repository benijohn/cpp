#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"
#include "trustAccount.h"
#include "accountUtils.h"
#include <vector>

using namespace std;

int main () {
    vector<Account> accounts;
    vector<SavingsAccount> sav_accounts;
    vector<CheckingAccount> check_accounts;
    vector<TrustAccount> trust_accounts;

    accounts.push_back(Account {});
    accounts.push_back(Account {"Ben"});
    accounts.push_back(Account {"Joe", 3000});
    accounts.push_back(Account {"Nep", 6000});

    sav_accounts.push_back(SavingsAccount {});
    sav_accounts.push_back(SavingsAccount {"Ben"});
    sav_accounts.push_back(SavingsAccount {"Joe", 3000});
    sav_accounts.push_back(SavingsAccount {"Nep", 6000, 20});

    check_accounts.push_back(CheckingAccount {});
    check_accounts.push_back(CheckingAccount {"Ben"});
    check_accounts.push_back(CheckingAccount {"Joe", 3000});
    check_accounts.push_back(CheckingAccount {"Nep", 6000});

    trust_accounts.push_back(TrustAccount {});
    trust_accounts.push_back(TrustAccount {"Ben"});
    trust_accounts.push_back(TrustAccount {"Joe", 3000});
    trust_accounts.push_back(TrustAccount {"Nep", 6000, 20});

    display(accounts);
    display(sav_accounts);
    display(check_accounts);
    display(trust_accounts);

    withdraw(accounts, 4000);
    withdraw(sav_accounts, 4000);
    withdraw(check_accounts, 4000);
    withdraw(trust_accounts, 4000);

    withdraw(trust_accounts, 4);
    withdraw(trust_accounts, 4);
    withdraw(trust_accounts, 4);
    withdraw(trust_accounts, 4);


    return 0;
}