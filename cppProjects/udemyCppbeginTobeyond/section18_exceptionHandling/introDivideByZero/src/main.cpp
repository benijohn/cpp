#include <iostream>

int main () {
    int miles {};
    int gallons {};
    double miles_per_gallon {};

    std::cout << "Enter miles:";
    std::cin >> miles;
    std::cout << "Enter gallons:";
    std::cin >> gallons;

    // if (gallons != 0) {
    //     miles_per_gallon = miles/static_cast<double>(gallons);
    //     std::cout << "Result:" << miles_per_gallon << std::endl;
    // }
    // else {
    //     std::cerr << "Can not divide by ZERO!!!" << std::endl;
    // }    
    try {
        if (gallons==0) {
            throw 0;
        }
        miles_per_gallon = miles/static_cast<double>(gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (int &exc) {
        std::cerr << "Can not divide by ZERO!!" << std::endl;
    }


    return 0;
}