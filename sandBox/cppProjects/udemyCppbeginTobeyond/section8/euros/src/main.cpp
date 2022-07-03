#include <iostream>

using namespace std;

int main () {
    const double usd_per_eur {1.19};

    cout << "Welcome to the EUR to USD converter!" << endl;
    cout << "Please enter the number of EUR to convert." << endl;

    double euros {0.0};
    cin >> euros;
    
    double dollars {0.0};
    dollars = euros*usd_per_eur;

    cout << "€" << euros <<  " = " << "$" << dollars << endl;


    return 0;
}