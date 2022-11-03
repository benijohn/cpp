/**************************************************************************
 * Section 5 - Basic IO
 * Author: Benjamin Johnson
 * Date: 2022-06-25
 * Udemy Beginning C++ Programming - Beginner to Beyond
 * ***********************************************************************/

#include <iostream>

using namespace std;

int main () {
    //cout << "Hello World" << endl;

    // cout << "Hello";
    // cout << " world" << endl;

    // cout << "Hello world!" << endl;
    // cout << "Hello" << " world!" << endl;
    // cout << "Hello" << " world!" << "\n";
    // cout << "Hello\nOut\nThere\n";

    int num1;
    int num2;
    double num3;

    // cout << "Please enter an integer:" << endl;
    // cin >> num1;
    // cout << "You entered " << num1 << endl;

    // cout << "enter a first integer:" << endl;
    // cin >> num1;
    // cout << "enter a second integer:";
    // cin >> num2;
    // cout << "You entered " << num1 << " and " << num2 << endl;

    //cout << "Enter two integers separated by a space:" << endl;
    // cin >> num1 >> num2;
    // cout << "You entered " << num1 << " and " << num2 << endl;

    // cout <<  "enter a float:" <<  endl;
    // cin >> num3;
    // cout << "You entered " << num3 << endl;

    cout << "Please enter and integer:" << endl;
    cin >> num1;
    cout << "Please enter a float:" << endl;
    cin >> num3;
    cout << "The integer is " << num1 << endl;
    cout << "The float is " << num3 << endl;


    return 0;
}