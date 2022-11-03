#include <iostream>
#include <vector>
#include <string>


using namespace std;

void double_data(int *num);
void swap (int *num1, int *num2);
void display(const vector<string> *const v);
void display(const int *array, int sentinel);

int main () {
    int num {};
    int *num_ptr {&num};
    

    cout << "Please enter an integer to double: ";
    cin >> num;

    cout << "The number " << num <<  " when doubled is ";
    double_data(num_ptr);
    cout << num << endl;

    cout <<  "\n--------------------------" << endl;
    cout << "Please enter two integers separated by a space: ";
    int num1 {}, num2 {};
    cin >> num1 >> num2;

    cout << "num1 is: " << num1 << endl;
    cout << "num2 is: " << num2 << endl;
    cout << "\nCommencing with number swap...." << endl;
    swap(&num1, &num2);
    cout << "num1 is: " << num1 << endl;
    cout << "num2 is: " << num2 << endl;

    // section 3 
    cout <<  "\n--------------------------" << endl;
    vector<string> stooges {"larry", "curly", "mo"};

    display(&stooges);


    cout <<  "\n--------------------------" << endl;
    const int temps [] {21, 23, 22, 30, 28, 31, 34, 20, 18, 19, -1};

    display(temps, -1);
    




    return 0;
}


void double_data(int *num) {
    *num *= 2;
}

void swap (int *num1, int *num2) {
    int temp_val = *num2;
    *num2 = *num1;
    *num1 = temp_val;
}

void display (const vector<string> *const v) {
    for (auto str: *v) {
        cout << str << " ";

    }
    cout << endl;
}

void display (const int *array, int sentinel) {
    while(*array != sentinel) {
        cout << *array++ << " ";
    }
    cout << endl;
}