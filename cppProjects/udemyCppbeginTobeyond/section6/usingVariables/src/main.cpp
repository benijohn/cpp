/**************************************************************************
 * Udemy course: C++ Beginner to Beyond - Section 6
 * Author: Benjamin Johnson
 * Date: 2022-06-25
 * 
 * ***********************************************************************/

#include <iostream>

using namespace std;

/* 
a program that calculates the area of a room
*/
int main () {



    cout << "Please enter the width then length of the room separated by a space:" << endl;
    double room_width {0}, room_length {0};
    cin >> room_width >> room_length;
    cout << "The area of the room is " << room_width*room_length << " ft^2." << endl;



    return 0;
}