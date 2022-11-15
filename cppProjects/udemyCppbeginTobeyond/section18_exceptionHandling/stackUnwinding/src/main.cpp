#include <iostream>

void func_a();
void func_b();
void func_c();
void func_d();

void func_a() {
    std::cout << "Starting function a" << std::endl;
    func_b();
    std::cout << "Cleaning function a" << std::endl;
}

void func_b() {
    std::cout << "Starting function b" << std::endl;
    try {
        func_c();
    }
    catch (int &exc) {
        std::cerr << "Caught error in func_b" << std::endl;
    }
    std::cout << "Cleaning function b" << std::endl;
}

void func_c() {
    std::cout << "Starting function c" << std::endl;
    func_d();
    std::cout << "Cleaning function c" << std::endl;
}

void func_d() {
    std::cout << "Starting function d" << std::endl;
    throw 100;
    std::cout << "Cleaning function d" << std::endl;
}

int main () {
    try {
        func_a();
    }
    catch (int &exc) {
        std::cout << "Caught error in main" << std::endl;
    }

    std::cout << "All done!" << std::endl;

    return 0;
}