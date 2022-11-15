#include <iostream>

class DivideByZeroExeption {

};

class NegativeValueException {

};

int main () {
    int miles {};
    int gallons {};
    double miles_per_gallon {};

    std::cout << "Enter miles:";
    std::cin >> miles;
    std::cout << "Enter gallons:";
    std::cin >> gallons;
   
    try {
        if (gallons==0) {
            throw DivideByZeroExeption ();
        }
        if (gallons < 0 || miles < 0) {
            throw NegativeValueException ();
        }
        miles_per_gallon = miles/static_cast<double>(gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (const DivideByZeroExeption &exc) {
        std::cerr << "Can not divide by ZERO!!" << std::endl;
    }
    catch (const NegativeValueException &exc) {
        std::cerr << "Negative value error" << std::endl;
    }

    std::cout << "Bye" << std::endl;

    return 0;
}
