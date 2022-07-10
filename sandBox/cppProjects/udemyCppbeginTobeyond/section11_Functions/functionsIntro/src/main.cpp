#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {
    //double num {};

    // cout << "Please enter a number to manipulate: " << endl;

    // cin >> num;

    // cout << "The square root of " << num << " = " << sqrt(num) << endl;

    // cout << "The cube root of " << num << " = " << cbrt(num) << endl;

    // cout << "The sine of " << num << " = " << sin(num*M_PI/180) << endl;

    // cout << "The cosine root of " << num << " = " << cos(num*M_PI/180) << endl;


    // cout << num << " cubed = " << pow(num, 3) << endl;

    // cout << "The ciel of " << num << " = " << ceil(num) << endl;
    // cout << "The floor of " << num << " = " << floor(num) << endl;

    int random_num {};

    size_t count {10};
    int min {1};
    int max {6};

    cout << "RAND MAX on my system is: " << RAND_MAX << endl;

    srand(time(nullptr));

    for (size_t i {1}; i < count; i++) {
        random_num = rand() % max+min;
        cout << random_num << endl;
    }






    return 0;
}