#include <iostream>


using namespace std;

int main () {
    // int array [] {1, 2, 3, 4, 5, 10, 9, 8, 7, -1};
    // int *array_ptr {array};

    // while (*array_ptr != -1) {
    //     cout << *array_ptr << endl;
    //     ++array_ptr;
    // }

    // cout << "\n======================" << endl;
    // array_ptr = array;
    // while (*array_ptr != -1) {
    //     cout << *array_ptr << endl;
    // }

    string s1 {"Benjamin"};
    string s2 {"Benjamin"};
    string s3 {"Johnson"};

    string *p1 {&s1};
    string *p2 {&s2};
    string *p3 {&s1};

    cout << boolalpha;

    cout << p1 << "==" << p2 << ":" << (p1==p2) << endl;
    cout << p1 << "==" << p3 << ":" << (p1==p3) << endl;

    cout << *p1 << "==" << *p2 << ":" << (*p1==*p2) << endl;
    cout << *p1 << "==" << *p3 << ":" << (*p1==*p3) << endl;

    p3 = &s3;
    cout << *p1 << "==" << *p3 << ":" << (*p1==*p3) << endl;

    cout << "\n===========================" << endl;
    char name[] {"Frank"};

    char *char_ptr_1 {};
    char *char_ptr_2 {};

    char_ptr_1 = &name[0];
    char_ptr_2 = &name[3];

    cout << "In the string " << name << " " << *char_ptr_2 << " is " << char_ptr_2-char_ptr_1 << " characters away from " << *char_ptr_1 << endl;





    return 0;
}