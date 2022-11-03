#include <iostream>
#include "account.h"
#include "account.cpp"


int main () {
    Account frank;

    frank.set_name("Frank");
    frank.set_balance(10000);

    frank.deposit(2300);
    frank.withdraw(500);
    frank.withdraw(20000);
    


    return 0;
}