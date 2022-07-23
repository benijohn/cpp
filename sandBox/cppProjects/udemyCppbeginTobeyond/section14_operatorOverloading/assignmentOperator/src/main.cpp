#include <iostream>
#include "mystring.h"


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


    


    return 0;
}