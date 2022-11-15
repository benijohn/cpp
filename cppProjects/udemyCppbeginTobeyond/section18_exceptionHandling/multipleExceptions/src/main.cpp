#include <iostream>
#include <string>

double calculate_average(int sum, int total) {
    double avg;
    if (total == 0) {
        throw 0;
    }
    if (sum < 0 || total < 0) {
        throw std::string {"negative value error"};
    }
    avg = sum/static_cast<double>(total);
    return avg;
}

int main () {
    int sum;
    int total;
    double average;

    std::cout << "Enter the sum: ";
    std::cin >> sum;
    std::cout << "Enter the total: ";
    std::cin >> total;

    try {
        average = calculate_average(sum, total);
        std::cout << "Average: " << average << std::endl;
    }
    catch (int &exc) {
        std::cerr << "Divide by zero" << std::endl;
    }   
    catch (std::string &exc) {
        std::cerr << exc << std::endl;
    } 

    return 0;
}