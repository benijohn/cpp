#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main () {
    vector<string> stooges {"Larry", "Curly", "Moe"};


    for (auto str: stooges) {
        str = "funny";
    }

    for (auto str: stooges) {
        cout << str <<  " ";
    }
    cout << endl;

    for (auto &str: stooges) {
        str = "funny";
    }


    // using a reference is more efficient
    for (auto const &str: stooges) {
        cout << str <<  " ";
    }
    cout << endl;

    cout << "\n======================" << endl;

    int num {100};
    int &ref {num};

    cout << num << endl;
    cout << ref << endl;

    ref = 300;

    cout << num << endl;
    cout << ref << endl;

    // reference to pointer

    double temp {23.12};
    double *temp_ptr {&temp};

    double &ptr_ref {*temp_ptr};

    cout << "\n---------------------" << endl;
    cout << temp << endl;
    cout << temp_ptr << endl;
    cout << *temp_ptr << endl;
    cout << ptr_ref << endl;



    return 0;
}