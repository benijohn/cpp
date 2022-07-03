#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num{};
    const int upper{20}, lower{10};

    cout << boolalpha;

    // logical heierarchy:
    //  logical not >> logical and >> logical or
    //  logical not is unary, logical and/or are binary

    // short circuit evaluation
    // exp1 && exp2 && exp3   if first one is false it will stop evaluation since entire expression is false
    // exp1 || exp2 || exp3   same thing but if one is true it stops

    cout << "Please enter an integer number, the bounds are " << lower << " and " << upper << "." << endl;
    cin >> num;

    bool within_bounds{false};

    within_bounds = (num>lower && num<upper);
    cout << "Number is between bounds: " << within_bounds << endl;

    bool outside_bounds{false};
    outside_bounds = (num<lower || num>upper);
    cout << "Number is outside bounds: " << outside_bounds << endl;
 
    bool on_bounds{false};
    on_bounds = (num==lower || num==upper);
    cout << "Number is on bounds: " << on_bounds << endl;

    uint num2 {100};
    uint num3 {100};

    num2 <<= 5;
    num3 = num3*pow(2,5);
    cout << num2 << endl;
    cout << num3 << endl;
    num2 >>= 2;
    num3 = num3/pow(2,2);
    cout << num2 << endl;
    cout << num3 << endl;


    return 0;
}