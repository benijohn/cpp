#include <iostream>

using namespace std;


void swap (int *a, int *b);


int main () {

    int i {5};
    while (i>0) {
        cout << i << endl;
        i--;
    }

    int num1 {}, num2 {};

    cout << "Please enter two integers to swap: ";
    cin >> num1 >> num2;

    cout << "\n----------------------"<< endl;
    cout << "The numbers " << num1 << " & " << num2 << " when swapped are ";
    swap(&num1, &num2);
    cout << num1 << " & " << num2 << endl;




    return 0;
}

void swap (int *a, int *b) {
    int temp {*a};
    *a = *b;
    *b = temp;
}