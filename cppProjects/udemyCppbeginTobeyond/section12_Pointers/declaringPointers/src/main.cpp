#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    int num {10};

    // cout << "Value of num is: " << num << endl;
    // cout << "Size of num is: " << sizeof(num) << endl;
    // cout << "Address of num is: " << &num << endl;

    // int *p;

    // cout << "Value of p is: " << p << endl;
    // cout << "Size of p is: " << sizeof(&p) << endl;
    // cout << "Address of p is: " << &p << endl;

    // p = nullptr;
    // cout << "Value of p is: " << p << endl;

    int *p1 {};
    double *p2 {nullptr};
    uint64_t *p3 {};
    vector<int> *p4 {};
    vector<string> *p5 {};
    string *p6 {};

    cout << "\nThe size of p1 is: " << sizeof(p1) << endl;
    cout << "The size of p2 is: " << sizeof(p2) << endl;
    cout << "The size of p3 is: " << sizeof(p3) << endl;
    cout << "The size of p4 is: " << sizeof(p4) << endl;
    cout << "The size of p5 is: " << sizeof(p5) << endl;
    cout << "The size of p6 is: " << sizeof(p6) << endl;

    int score {10};
    double high_temp {103.4};

    int *score_ptr {};
    score_ptr = &score;

    cout << "\nValue of score is: " << score << endl;
    cout << "Address of score is: " << &score << endl;
    cout << "Value of score_ptr is: " << score_ptr << endl;

    // score_ptr = &high_temp // compiler error don't do stupid things!!!

    

    return 0;
}