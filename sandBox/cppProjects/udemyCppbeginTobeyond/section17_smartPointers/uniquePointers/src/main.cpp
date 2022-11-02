
#include <vector>
#include <iostream>
#include <memory>

#include "account.h"
#include "savingsAccount.h"
#include "checkingAccount.h"
#include "trustAccount.h"
#include "accountUtils.h"

using namespace std;

class Test {
    private:
    int data;

    public:
    Test (): data {0} {cout << "Test constructor (" << data << ")" << endl; };
    Test (int data): data {data} {cout << "Test constructor (" << data << ")" << endl;};
    int get_data() const {return data;};
    ~ Test () {cout << "Test destructor (" << data << ")" << endl;};

};

int main () {
    // Test t1 {1000};
    // Test *t2 = new Test {2000};

    // std::unique_ptr<Test> t3 {new Test {3000}};
    // std::unique_ptr<Test> t4 = std::make_unique<Test> (4000);
    // std::unique_ptr<Test> t5;
    // t5 = make_unique<Test> (5000);
    // std::unique_ptr<Test> t6;
    // t6 = std::move(t3);
    // if (t3 == nullptr) {
    //     cout << "t3 is nullptr" << endl;
    // }
    // delete t2;

    std::unique_ptr<Account> a1 = std::make_unique<Checking> ("Napoleon", 500000);
    cout << *a1 << endl;
    std::unique_ptr<Account> a2;
    a2 = std::move(a1);

    //cout << *a1 << endl;

    vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(std::move(a2));
    accounts.push_back(make_unique<Savings> ("Neptune", 340000));
    accounts.push_back(make_unique<Trust> ("Melissa", 500000000, 20));

    for (const auto &acc: accounts) {
        cout << *acc << endl;
    }
 
    return 0;
}