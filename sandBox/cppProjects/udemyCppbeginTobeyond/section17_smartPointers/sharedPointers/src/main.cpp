
#include <vector>
#include <iostream>
#include <memory>

#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"
#include "trustAccount.h"
#include "accountUtils.h"


class Test {
    private:
    int data;

    public:
    Test (): data {0} {std::cout << "Test constructor (" << data << ")" << std::endl; };
    Test (int data): data {data} {std::cout << "Test constructor (" << data << ")" << std::endl;};
    int get_data() const {return data;};
    ~ Test () {std::cout << "Test destructor (" << data << ")" << std::endl;};

};

void func(std::shared_ptr<Test> ptr) {
    std::cout << ptr.use_count() << std::endl;
}

int main () {
    std::shared_ptr<int> p1 (new int {100});
    std::cout << p1.use_count() << std::endl;

    std::shared_ptr<int> p2;
    p2 = p1;
    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;

    std::shared_ptr<int> p3 {p2};
    p2.reset();

    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;
    std::cout << p3.use_count() << std::endl;

    std::cout << "\n=========================\n" << std::endl;
    std::shared_ptr<Test> ptr = std::make_shared<Test> (100);
    std::cout << ptr.use_count() << std::endl;
    func(ptr);

    {
        std::shared_ptr<Test> ptr1 = ptr;
        std::cout << ptr.use_count() << std::endl;
        {
            std::shared_ptr<Test> ptr2 = ptr;
            std::cout << ptr.use_count() << std::endl;
            ptr.reset();
        }
        std::cout << ptr.use_count() << std::endl;
    }
    std::cout << ptr.use_count() << std::endl;

    std::cout << "\n=====================\n" << std::endl;
    std::shared_ptr<Account> acc1 = std::make_shared<Savings> ("Neptune", 100);
    std::shared_ptr<Account> acc2 = std::make_shared<Checking> ("Napoleon", 200);
    std::shared_ptr<Account> acc3 = std::make_shared<Trust> ("Melissa", 500, 15);

    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);

    for (const auto &acc: accounts) {
        std::cout << *acc << std::endl;
        std::cout << acc.use_count() << std::endl;
    }

 
    return 0;
}