#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"
#include "trustAccount.h"
#include "i_printable.h"
#include <vector>

// Standard account utils
void print (const std::vector<Account *> &accounts);
void deposit (std::vector<Account *> &accounts, double amount);
void withdraw (std::vector<Account *> &accounts, double amount);

