#include <iostream>

using namespace std;


int main() {
    int num1{},num2 {},num3{};

    int total {0};

    const int count {3};

    cout << "Please enter 3 integers:" << endl;

    cin >> num1 >> num2 >> num3;
    total = num1+num2+num3;
    double average {0.0};
    // static cast is preferred to the old C style of casting
    average = static_cast<double>(total)/count;

    cout << "The three numbers were: " << num1 << "," << num2 << "," << num3 << endl;
    cout << "The sum of the number is: " << total << endl;
    cout << "The average is: " << average << endl;

    return 0;
}