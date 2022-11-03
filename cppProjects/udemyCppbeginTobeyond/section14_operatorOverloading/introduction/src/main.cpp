#include <iostream>
#include "mystring.h"

using namespace std;

int main () {
    MyString empty;
    MyString name {"Ben"};
    MyString copy {name};


    copy.display();
    cout << copy.get_str() << endl;
    name.display();
    empty.display();

    return 0;
}