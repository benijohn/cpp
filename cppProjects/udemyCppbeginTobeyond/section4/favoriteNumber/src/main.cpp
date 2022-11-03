#include <iostream>

int main() {
    int favoriteNumber;

    std::cout << "Please enter your favorite number between 1 and 100:" << std::endl;
    std::cin >> favoriteNumber;
    std::cout << "No way! " << favoriteNumber << " is my favorite number too!" << std::endl;
}