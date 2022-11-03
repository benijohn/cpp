#include <iostream>
#include <climits>

using namespace std;

int main () {
    cout << "Size of various variables:" << endl;
    cout << "===========================" << endl;

    cout << "char:" << sizeof(char) << " bytes." << endl;
    cout << "int:" << sizeof(int) << " bytes." << endl;
    cout << "unsigned int:" << sizeof(unsigned int) << " bytes." << endl;
    cout << "short:" << sizeof(short) << " bytes." << endl;
    cout << "long:" << sizeof(long) << " bytes." << endl;
    cout << "long long:" << sizeof(long long) << " bytes." << endl;
    cout << "uint8_t:" << sizeof(uint8_t) << " bytes." << endl;
    cout << "uint16:" << sizeof(uint16_t) << " bytes." << endl;
    cout << "uint32_t:" << sizeof(uint32_t) << " bytes." << endl;
    cout << "uint64_t:" << sizeof(uint64_t) << " bytes." << endl;
    cout << "int8_t:" << sizeof(int8_t) << " bytes." << endl;
    cout << "int16_t:" << sizeof(int16_t) << " bytes." << endl;
    cout << "int32_t:" << sizeof(int32_t) << " bytes." << endl;
    cout << "int64_t:" << sizeof(int64_t) << " bytes." << endl;

    cout << "float:" << sizeof(float) << " bytes." << endl;
    cout << "double:" << sizeof(double) << " bytes." << endl;
    cout << "long double:" << sizeof(long double) << " bytes." << endl;
    return 0;
}
