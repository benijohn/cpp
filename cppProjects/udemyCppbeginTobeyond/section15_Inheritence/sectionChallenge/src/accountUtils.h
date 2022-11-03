#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"
#include "trustAccount.h"

// Standard account utils
void display (const std::vector<Account> &accounts);
void deposit (std::vector<Account> &accounts, double amount);
void withdraw (std::vector<Account> &accounts, double amount);

// Savings account utils
void display (const std::vector<SavingsAccount> &accounts);
void deposit (std::vector<SavingsAccount> &accounts, double amount);
void withdraw (std::vector<SavingsAccount> &accounts, double amount);

// Checking account utils
void display (const std::vector<CheckingAccount> &accounts);
void deposit (std::vector<CheckingAccount> &accounts, double amount);
void withdraw (std::vector<CheckingAccount> &accounts, double amount);

// Trust account utils
void display (const std::vector<TrustAccount> &accounts);
void deposit (std::vector<TrustAccount> &accounts, double amount);
void withdraw (std::vector<TrustAccount> &accounts, double amount);

