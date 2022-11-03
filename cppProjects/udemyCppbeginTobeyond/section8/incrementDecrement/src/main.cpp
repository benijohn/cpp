/**********************************************************************************
 * Udemy course: C++ Beginner to Beyond
 * Author: Benjamin Johnson
 * Date: 2022-06-27
 * 
 * Increment/Decrement Operators
 * ++ 
 * --
 * 
 * Prefix ++i
 * Postfix i++
 * 
 * ********************************************************************************/

#include <iostream>


using namespace std;

int main () {
    int counter {10};
    int result {0};

    cout << "Counter: " << counter << endl;

    counter = counter + 1;
    cout << "Counter: " << counter << endl;

    counter++;
    cout << "Counter: " << counter << endl;

    ++counter;
    cout << "Counter: " << counter << endl;


    counter = 10;
    result = 0;

    cout << "Counter: " << counter << endl;

    result = ++counter;
    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl;

    counter = 10;
    result = 0;

    result = counter++;
    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl;
    
    
    return 0;
}