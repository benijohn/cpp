/*******************************************************
 * Udemy Course: C++ Beginner to Beyond - Section 6 - primitive types
 * Author: Benjamin Johnson
 * Date: 2022-06-25
 * 
 * ******************************************************/

#include <iostream>

using namespace std;

int main () {
    // Character types
    char middle_initial {'I'};
    cout << "My middle initial is " << middle_initial << "." << endl;

    // Int types
    unsigned short int exam_score {55};
    cout << "My exam score was " << exam_score << " yikes!" << endl;

    int countries_represented {65};
    cout << "There are more than " << countries_represented << " countries on earth today." << endl;

    long people_in_florida {23494521};
    cout << "There are about " << people_in_florida << " people in Florida." << endl;

    long people_on_earth {7'700'000'000'000'000'000};
    cout << "There are " << people_on_earth << " people on earth." << endl;

    long long int distance_to_alpha_centauri {9'461'000'000'000};
    cout << "The distance to Alpha Centauri is " << distance_to_alpha_centauri << " kilometers." << endl;

    // Float types
    float car_payment {568.32};
    cout << "My car payment of $" << car_payment << " is far too large." << endl;

    double big_floater {32.50923418342845};
    cout << "Look at how many sig figs are in this number " << big_floater << " holy moly." << endl;

    long double big_number {234.12e52};
    cout << big_number << " is a big number." << endl;

    // Bool types
    bool cpp_is_fun {true};
    cout << "Yes it is " << cpp_is_fun << " that learning new languages is fun." << endl;

    // example of overflow
    // short num1 {30000};
    // short num2 {1000};


    return 0;
}