#include <iostream>

using namespace std;

int main () {
    cout << "Hello, welcome Frank's carpet cleaning service\n" << endl;
    cout << "How many rooms would you like to have cleaned?" << endl;

    int number_of_rooms {0};
    cin >> number_of_rooms;

    cout << "\nEstimate for carpet cleaning service:" << endl;
    cout << "========================================" << endl;
    cout << "Number of rooms:" << number_of_rooms << endl;
    const double price_per_room {30};
    cout << "Price per room $" << price_per_room << endl;
    cout << "\tCost:\t$" << number_of_rooms*price_per_room << endl;
    const double sales_tax {0.06};
    cout << "+\tTax:\t$" << number_of_rooms*price_per_room*sales_tax << endl;
    cout << "=========================================" << endl;
    cout << "\tTotal:\t$" << number_of_rooms*price_per_room + number_of_rooms*price_per_room*sales_tax << endl;
    const int estimate_validity {60};
    cout << "Estimate is valid for " << estimate_validity << " days" << endl;

    // display cost
    // display tax
    // display total
    // display quote valid for...
}