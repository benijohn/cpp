#include <iostream>


using namespace std;

int main () {

    for (int i {1}; i<= 100; ++i) {
        cout << "\t" << i << ((i%10 == 0) ? "\n" : " "); 
    }

    for (auto val: {"string1", "benjamin", "c++ is fun", "lets go Sweden!"}) {
        cout << val << endl;
    }

    return 0;
}