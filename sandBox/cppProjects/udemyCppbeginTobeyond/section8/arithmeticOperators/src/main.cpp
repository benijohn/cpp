#include <iostream>

using namespace std;

int main () {
    int num1 {200};
    int num2 {100};

    int result {0};

    result = num1+num2;
    cout << num1 << "+" << num2 << "=" << result << endl;

    result = num1-num2;
    cout << num1 << "-" << num2 << "=" << result << endl;

    result = num1*num2;
    cout << num1 << "*" << num2 << "=" << result << endl;

    result = num1/num2;
    cout << num1 << "/" << num2 << "=" << result << endl;

    // note for integer division will not carry the remainder YOU MUST USE DOUBLES!!!
    result = num2/num1;
    cout << num2 << "/" << num1 << "=" << result << endl;

    // modulo gives only the remainder
    result = num1%num2;
    cout << "Modulo operator" << endl;
    cout << num1 << "%" << num2 << "=" << result << endl;

    num1 = 10;
    num2 = 3;

    result = num1%num2;
    cout << "Modulo operator" << endl;
    cout << num1 << "%" << num2 << "=" << result << endl;

    result = num1*10+num2;
    cout << "10*" << num1 << " + " << num2 << " = " << result << endl;

    cout << "Integer Division(5/10): " << 5/10 << endl;
    cout << "Double Division(5.0/10.0): " << 5.0/10.0 << endl;



    return 0;
}