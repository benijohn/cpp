#include <iostream>

using namespace std;

int main () {
    int num1 {10};
    int num2 {20};
    // in C++ there is this concept of l-value and r-value think left and right,
    // r-value is the variable contents, and l-value is the location or address

    // reassigning the contents  of num1
    num1 = 100;

    // this type of chaining is also legal and the assignment moves from right to left
    num1 = num2 = 1000;

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;



    return 0;
}