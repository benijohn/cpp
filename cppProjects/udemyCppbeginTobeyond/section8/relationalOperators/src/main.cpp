#include <iostream>

using namespace std;

int main () {
    int num1{},num2{};

    cout << "Please enter two integers separated by a space:" << endl;
    cin >> num1 >> num2;

    cout << boolalpha;
    cout << num1 << ">" << num2 << " : " << (num1>num2) << endl;

    return 0;
}