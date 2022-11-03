#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    // int score {100};
    // int *score_ptr {&score};

    // cout << "\nvalue of score is: " << score << endl;
    // cout << "value pointed to by score_ptr is: " <<  *score_ptr << endl;

    // *score_ptr = 105; // extra credit!!
    // cout << "\n the value of score is now: " << score << endl;

    // double high_temp {100.4};
    // double low_temp {23.5};
    // double *temp_ptr {&high_temp};

    // cout << "\n" << *temp_ptr << endl;
    // temp_ptr = &low_temp;
    // cout << *temp_ptr << endl;

    string name {"Benjamin"};
    string *name_ptr {&name};

    cout << "\n" << *name_ptr << endl;
    name = "Johnson";
    cout << *name_ptr << endl;

    cout << "\n========================================" << endl;

    vector<string> stooges {"larry", "curly", "mo"};
    vector<string> *stooges_ptr {&stooges};

    cout << "\nThe first stooge is: " << (*stooges_ptr).at(0) << endl;

    for (auto stooge: *stooges_ptr) {
        cout << stooge << " ";
    }
    cout << endl;

    return 0;
}