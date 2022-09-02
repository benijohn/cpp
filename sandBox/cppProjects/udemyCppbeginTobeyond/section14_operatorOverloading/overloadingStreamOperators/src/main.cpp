 #include <iostream>
#include "mystring.h"

using namespace std;

int main () {
    MyString larry {"Larry"};
    MyString moe {"Moe"};
    MyString curly;
    
    cout << boolalpha;

    cout << "Stooge 1: " << larry << endl;
    cout << "Stooge 2: " << moe << endl;

    cout << "Enter the third stooges name: ";
    cin >> curly;

    cout << "You have name the third stooge: " << curly << endl;
    cout << "\n\nTogether the three stooges are " << larry << " and " << curly << " and " << moe << endl;

    cout << "Enter all the stooges names, separated by a space: ";
    cin >> larry >> curly >> moe;

    cout << "\n\nEven now, they together are called: " << larry << " and " << curly << " and " << moe << endl;
    





    return 0;
}