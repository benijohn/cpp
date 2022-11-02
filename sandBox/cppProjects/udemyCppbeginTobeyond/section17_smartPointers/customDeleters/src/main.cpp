#include <iostream>
#include <memory>

class Test {
    private:
    int data;

    public:
    Test () : data {0} { std::cout << "Test constructor ( " << data << " )" << std::endl;};
    Test (int data) : data {data} { std::cout << "Test contsructor ( " << data << " )" << std::endl;};
    ~Test() { std::cout << "Test destructor ( " << data << " )" << std::endl;};

    int get_data() const { return data; };

};

void my_deleter(Test *ptr) {
    std::cout << "Using my custom deleter function" << std::endl;
    delete ptr;
}

int main () {

    {
        std::shared_ptr<Test> ptr1 {new Test {100}, my_deleter};
    }

    std::cout << "\n===============================\n" << std::endl;
    std::cout << "Using lambda expression" << std::endl;

    std::shared_ptr<Test> ptr2 {new Test{400},
    [] (Test *ptr) {
        std::cout << "Using my lambda deleter" << std::endl;
        delete ptr;
    }};



    return 0;
}