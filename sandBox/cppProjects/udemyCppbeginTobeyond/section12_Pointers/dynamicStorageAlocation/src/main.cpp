#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    int *dynamic_int_ptr {};

    dynamic_int_ptr = new int;

    cout << *dynamic_int_ptr << endl;
    cout <<  dynamic_int_ptr << endl;

    delete dynamic_int_ptr;

    dynamic_int_ptr = new int {100};
    cout << *dynamic_int_ptr << endl;
    delete dynamic_int_ptr;

    double *temp_ptr {};
    int size {};

    cout << "enter an array size to initialize: ";
    cin >> size;

    temp_ptr = new double [size];

    delete [] temp_ptr;

    cout << endl;
    return 0;
}