#include <iostream>
#include "mystring.h"
#include <vector>


using namespace std;

int main () {
    Mystring empty;
    Mystring ben {"Ben"};
    Mystring name {ben};

    vector<Mystring> names {ben};
    names.push_back(name);
    Mystring frank {"Frank"};
    names.push_back(frank);
    Mystring larry {"Larry"};
    names.push_back(larry);

    cout << larry << endl;
    larry = -larry;
    cout << larry << endl;
    larry++;
    cout << larry << endl;
    larry = "LaRRy";
    cout << larry << endl;
    ++larry;
    cout << larry << endl;
    
    cout << boolalpha;

    cout << (larry < ben) << endl;
    cout << (larry > ben) << endl;
    cout << (ben == name) << endl;
    cout << (name!=ben) << endl;

    names.clear();

    larry += " is a stooge.";
    cout << larry << endl;
    ben = ben + " is my name.";
    cout << ben << endl;
    name = name*3;
    cout << name << endl;
    name *= 3;
    cout << name << endl;
    larry += name;
    cout << larry << endl;

    Mystring a {"aac"};
    Mystring b {"aaaa"};
    Mystring c {"aa"};


    cout << "\nMystring class:" << endl;
    cout << "==========================" << endl;
    cout << a << " == " << b << (a==b) << endl;
    cout << a << " > " << b << (a>b) << endl;
    cout << b << " > " << a << (b>a) << endl;
    cout << b << " < " << a << (b<a) << endl;
    cout << a << " < " << b << (a<b) << endl;
    cout << a << " > " << c << (a>c) << endl;
    cout << c << " > " << a << (c>a) << endl;
    cout << a << " < " << c << (a<c) << endl;
    cout << c << " < " << a << (c<a) << endl;
    cout << a << " >= " << c << (a>=c) << endl;
    cout << c << " >= " << a << (c>=a) << endl;
    cout << a << " <= " << c << (a<=c) << endl;
    cout << c << " <= " << a << (c<=a) << endl;

 


    
}