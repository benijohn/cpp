#include "accountUtils.h"

// Standard account utils
void display (const std::vector<Account> &accounts) {
    std::cout << "====List of Accounts===============" << std::endl;
    for (const auto &acc: accounts) {
        std::cout << acc << std::endl;
    }
}
void deposit (std::vector<Account> &accounts, double amount) {
    for (auto &acc: accounts) {
        if (acc.deposit(amount)) {
            std::cout << "Successfully deposited $" << amount << " to account: " << acc << std::endl;
        }
        else {
            std::cout << "Deposit failed for account: " << acc << std::endl;
        }
    }
}
void withdraw (std::vector<Account> &accounts, double amount) {
    for (auto &acc: accounts) {
        if (acc.withdraw(amount)) {
            std::cout << "Successfully withdrew $" << amount << " from account: " << acc << std::endl;
        } 
        else {
            std::cout << "Withdraw failed for account: " << acc << std::endl;
        }
    }
}

// Savings account utils
void display (const std::vector<SavingsAccount> &accounts) {
    std::cout << "====List of Savings Accounts===============" << std::endl;
    for (const auto &acc: accounts) {
        std::cout << acc << std::endl;
    }
}
void deposit (std::vector<SavingsAccount> &accounts, double amount) {
    for (auto &acc: accounts) {
        if (acc.deposit(amount)) {
            std::cout << "Successfully deposited $" << amount << " to account: " << acc << std::endl;
        }
        else {
            std::cout << "Deposit failed for account: " << acc << std::endl;
        }
    }
}
void withdraw (std::vector<SavingsAccount> &accounts, double amount) {
    for (auto &acc: accounts) {
        if (acc.withdraw(amount)) {
            std::cout << "Successfully withdrew $" << amount << " from account: " << acc << std::endl;
        } 
        else {
            std::cout << "Withdraw failed for account: " << acc << std::endl;
        }
    }
}

// Checking account utils
void display (const std::vector<CheckingAccount> &accounts) {
    std::cout << "====List of Checking Accounts===============" << std::endl;
    for (const auto &acc: accounts) {
        std::cout << acc << std::endl;
    }
}
void deposit (std::vector<CheckingAccount> &accounts, double amount) {
    for (auto &acc: accounts) {
        if (acc.deposit(amount)) {
            std::cout << "Successfully deposited $" << amount << " to account: " << acc << std::endl;
        }
        else {
            std::cout << "Deposit failed for account: " << acc << std::endl;
        }
    }
}
void withdraw (std::vector<CheckingAccount> &accounts, double amount) {
    for (auto &acc: accounts) {
        if (acc.withdraw(amount)) {
            std::cout << "Successfully withdrew $" << amount << " from account: " << acc << std::endl;
        } 
        else {
            std::cout << "Withdraw failed for account: " << acc << std::endl;
        }
    }
}

// Trust account utils
void display (const std::vector<TrustAccount> &accounts) {
    std::cout << "====List of Trust Accounts===============" << std::endl;
    for (const auto &acc: accounts) {
        std::cout << acc << std::endl;
    }
}
void deposit (std::vector<TrustAccount> &accounts, double amount) {
    for (auto &acc: accounts) {
        if (acc.deposit(amount)) {
            std::cout << "Successfully deposited $" << amount << " to account: " << acc << std::endl;
        }
        else {
            std::cout << "Deposit failed for account: " << acc << std::endl;
        }
    }
}
void withdraw (std::vector<TrustAccount> &accounts, double amount) {
    for (auto &acc: accounts) {
        if (acc.withdraw(amount)) {
            std::cout << "Successfully withdrew $" << amount << " from account: " << acc << std::endl;
        } 
        else {
            std::cout << "Withdraw failed for account: " << acc << std::endl;
        }
    }
}