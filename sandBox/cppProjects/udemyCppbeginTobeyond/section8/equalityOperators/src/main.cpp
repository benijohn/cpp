#include <iostream>

using namespace std;

int main () {
    bool equal_result{false};
    bool not_equal_result{false};

    int num1{},num2{};

    cout << "Please enter two integers separated by a space:" << endl;

    cin >> num1 >> num2;

    equal_result = (num1 == num2);
    not_equal_result = (num1 != num2);

    cout << "equality: " << equal_result << endl;
    cout << "inequality: " << not_equal_result << endl;

    cout << boolalpha;

    cout << "equality: " << equal_result << endl;
    cout << "inequality: " << not_equal_result << endl;



    return 0;
}