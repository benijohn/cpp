#include <iostream>

using namespace std;

int *applyAll (int *array1, size_t size1, int *array2, size_t size2);
void print(const int *const array, size_t size);

int main () {
    int array1 [] {1, 2, 3, 4, 5};
    int array2 [] {10, 20, 30, 40, 50};
    const size_t size1 {sizeof(array1)/sizeof(array1[0])};
    const size_t size2 {sizeof(array2)/sizeof(array2[0])};

    cout << "\n---------------------" << endl;
    cout << "array1: ";
    print(array1, size1);
    cout << "array2: ";
    print(array2, size2);
    cout << endl;

    int *big_array {};
    big_array = applyAll(array1, size1, array2, size2);
    print(big_array, size1*size2);

    delete [] big_array;

    return 0;
}

void print (const int *const array, size_t size) {
    cout << "[ ";
    for (size_t i {0}; i< size; i++) {
        cout << array[i] << " ";
    }
    cout << "]";
    cout << endl;
}

int *applyAll (int *array1, size_t size1, int *array2, size_t size2) {
    int *new_array {};

    new_array = new int [size1*size2] {0};
    size_t idx {0};
    for (size_t i {0}; i < size2; i++){
        for (size_t j {0}; j < size1; j++) {
            new_array[idx] = array2[i]*array1[j];
            idx++;
        }
    }
    return new_array;
}