#include <iostream>

using namespace std;

uint64_t factorial(uint64_t n);
uint64_t fibonacci(uint64_t n);

int main (){
    uint64_t num {0};

    cout << "enter a number to calculate factorial: ";
    cin >> num;

    uint64_t fact {};
    fact = factorial(num);

    cout << "The factorial of " << num << " is: " << fact << endl;

    cout << "\n Now enter a number to fibonacci erize: ";
    cin >> num;
    cout << "The fibonacci of " << num << " is : " << fibonacci(num) << endl;

    return 0;
}

uint64_t factorial(uint64_t n) {
    if (n != 0) {
        return n*factorial(n-1);
    }
    else {
        return 1;
    }
}

uint64_t fibonacci(uint64_t n) {
    if (n > 1) {
        return fibonacci(n-2) + fibonacci(n-1);
    }
    else {
        return n;
    }
}