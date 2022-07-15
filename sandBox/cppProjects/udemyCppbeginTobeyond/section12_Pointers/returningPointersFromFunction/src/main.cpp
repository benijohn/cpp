#include <iostream>

using namespace std;

int *returnLargest (int *a, int *b);
int *newDynamicArray(size_t size, int init_value = 0);
void display (const int *const array, size_t size);


int main () {
    int a {100};
    int b {200};
    int c {300};

    int *largest {};

    largest = returnLargest(&a, &c);
    cout << *largest << endl;

    cout << "\n---------------------" << endl;
    cout << "Please enter the size of the array you would like to create: ";
    size_t size {};
    int init_value {};

    cin >> size;

    cout << "\nThank you, and what value would you like your array initialized to?";
    cin >> init_value;

    cout << endl;

    int *my_array {};
    cout << my_array << endl;

    my_array = newDynamicArray(size, init_value);
    cout << my_array << endl;

    display(my_array, size);

    delete [] my_array;



    return 0;
}

int *returnLargest(int *a, int *b) {
    if (*b > *a) {
        return b;
    }
    else {
        return a;
    }
}

int *newDynamicArray(size_t size, int init_value) {
    int *new_array {};

    new_array = new int [size] {0};
    for (size_t i {0}; i<size; i++) {
        new_array[i] = init_value;
    }
    return new_array;
}

void display (const int *const array, size_t size) {
    for (size_t i{0}; i<size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}