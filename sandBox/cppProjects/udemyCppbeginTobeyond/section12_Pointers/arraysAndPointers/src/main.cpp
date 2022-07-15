#include <iostream>


using namespace std;

int main () {
    int scores [] {93, 98, 84, 90, 72, 92};
    int *scores_ptr {scores};

    // cout << scores << endl;
    // cout << *scores << endl;

    cout << "\nArray subscript notatioin:" << endl;
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;

    cout << "\nArray addresses:" << endl;
    cout << scores << endl;
    cout << scores+1 << endl;
    cout << scores+2 << endl;

    cout << "\nArray name dereferencing (offset notation):" << endl;
    cout << *scores << endl;
    cout << *(scores+1) << endl;
    cout << *(scores+2) << endl;

    cout << "\nArray p ointer subscript notatioin:" << endl;
    cout << scores_ptr[0] << endl;
    cout << scores_ptr[1] << endl;
    cout << scores_ptr[2] << endl;

    cout << "\nArray pointer addresses: " << endl;
    cout << scores_ptr << endl;
    cout << scores_ptr+1 << endl;
    cout << scores_ptr+2 << endl;


    cout << "\nArray pointer dereferencing (offset notation):" << endl;
    cout << *scores_ptr << endl;
    cout << *(scores_ptr+1) << endl;
    cout << *(scores_ptr+2) << endl;



    return 0;
}