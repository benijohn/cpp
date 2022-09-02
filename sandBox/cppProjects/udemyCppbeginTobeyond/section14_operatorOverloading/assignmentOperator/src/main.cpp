#include <iostream>
#include <vector>
#include "mystring.h"

using namespace std;

int main () {
    // copy assignment (before move assignement was implemented)
    // MyString empty;
    // MyString hi {"Hello"};

    // empty.display();
    // empty = hi;
    // empty.display();

    // empty = "A Big Ole String";
    // empty.display();

    // move assignement code
    MyString a {"Hello"};
    a = MyString {"Move Assignment String"};
    a = " we got strings moving all over the place!! ";


    MyString empty;
    MyString larry {"Larry"};
    MyString stooge {larry};
    MyString stooges;

    empty = stooge;

    empty = "Funny";
    
    empty.display();
    larry.display();
    stooge.display();
    empty.display();

    stooges = "Larry, Moe, and Curly";
    stooges.display();

    vector<MyString> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");

    cout << "====Loop 1===============" << endl;
    for (const MyString &s: stooges_vec) {
        s.display();
    }


    cout << "====Loop 2===============" << endl;
    for (MyString &s: stooges_vec) {
        s = "Changed";
    }

    cout << "====Loop 3===============" << endl;
    for (const MyString &s: stooges_vec) {
        s.display();
    }



    return 0;
}