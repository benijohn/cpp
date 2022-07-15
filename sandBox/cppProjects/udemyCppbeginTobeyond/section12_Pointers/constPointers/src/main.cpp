#include <iostream>

using namespace std;

int main () {
    const int num_const {100};
    int num {50};

    const int *pointer_to_const {&num_const};
   // int *another_pointer_to_const {&num_const}; const cannot be used to initialize a non const pointer
   int *normal_pointer {&num};
   const int *pointer_to_const_2 {&num};
   const int *const const_pointer_to_const {&num_const};
   int *const const_pointer_to_non_const {&num};



    return 0;
}