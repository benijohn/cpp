 #include <iostream>
#include "mystring.h"

using namespace std;

int main () {
    MyString larry {"Larry"};
    MyString curly {"Curly"};
    MyString moe {"Moe"};
    MyString new_stooge {larry};
    
    cout << boolalpha;

    cout << (larry==curly) << endl;
    cout << (larry==new_stooge) << endl;

    larry.display();
    larry = -larry;
    larry.display();

    MyString stooges = larry + " Moe";
    stooges.display();

    MyString two_stooges = moe + " " + "Larry";
    two_stooges.display();

    MyString three_stooges = larry + " " + "Curly" + " " + moe;
    three_stooges.display();


    return 0;
}