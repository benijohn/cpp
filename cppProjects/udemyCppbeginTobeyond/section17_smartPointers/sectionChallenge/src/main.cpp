#include <memory>
#include <iostream>
#include <vector>

class Test {
    private:
        int data;
    public:
    Test () : data{0} {std::cout << "Test default constructor (" << data << ")" << std::endl;};
    Test (int data) : data{data} {std::cout << "Test int construcor (" << data << ")" << std::endl;};
    ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl;};

    int get_data() const {return data;};    
};

//std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
auto make();
void fill (std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);


//std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
auto make () {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> ptr = std::make_unique<std::vector<std::shared_ptr<Test>>>();
    return ptr;
}

int main () {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many points do you want to enter? :  ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);


    return 0;
}


void fill (std::vector<std::shared_ptr<Test>> &vec, int num) {
    for (int i=0; i<num; i++) {
        std::cout << "Please enter your data: ";
        int data;
        std::cin >> data;
        vec.push_back(std::make_shared<Test> (data));
        std::cout << "\n" << std::endl;
    } 
}

void display(const std::vector<std::shared_ptr<Test>> &vec) {
    for (const auto &t: vec) {
        std::cout << t->get_data() << std::endl;
        // these both work 
       // std::cout << t.get()->get_data() << std::endl; 
    }
}


