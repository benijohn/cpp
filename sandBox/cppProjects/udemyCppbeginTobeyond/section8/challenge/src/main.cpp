/*  Section Challenge
Change calculator, determine which coins to return as change to keep the number of coins to a mininum
*/

#include <iostream>

using namespace std;

int main() {
    cout << "Please enter a number of cents: " << endl;

    int16_t total {};
    cin >> total;

    const int dollar {100};
    const int quarter {25};
    const int dime {10};
    const int nickle {5};
    const int penny {1};

    int number_of_dollars {};
    int number_of_quarters {};
    int number_of_dimes {};
    int number_of_nickles {};
    int number_of_pennies {};

    int remainder {};

    number_of_dollars = total/dollar;
    remainder = total%dollar;

    number_of_quarters = remainder/quarter;
    remainder = remainder%quarter;

    number_of_dimes = remainder/dime;
    remainder = remainder%dime;

    number_of_nickles = remainder/nickle;
    number_of_pennies = remainder%nickle;

    cout << "You should return the change as:" << endl;
    cout << "Dollars:\t\t" << number_of_dollars << endl;
    cout << "Quarters:\t\t" << number_of_quarters << endl;
    cout << "Dimes:\t\t\t" << number_of_dimes << endl;
    cout << "Nickles:\t\t" << number_of_nickles << endl;
    cout << "Pennies:\t\t" << number_of_pennies << endl;


    return 0;
}