#include <iostream>
#include <memory>

using namespace std;

class B;

class A {
    std::shared_ptr<B> b_ptr;

    public:
    void set_B(std::shared_ptr<B> &b) {
        b_ptr = b;
    }
    A() {
        cout << "A constructor" << endl;
    }
    ~A() {
        cout << "A destructor" << endl;
    };

};

class B {
    //std::shared_ptr<A> a_ptr;
    std::weak_ptr<A> a_ptr;

    public:
    void set_A(std::shared_ptr<A> &a) {
        a_ptr = a;
    }
    B() {
        cout << "B constructor" << endl;
    }
    ~B() { 
        cout << "B destructor" << endl;
    }
};

int main () {
    // this will cause a memory leak because when a,b go out of scope, they can not destroy the A,B objects being referenced by each other.
    // to fix this make B objects ptr a weak ptr.
    std::shared_ptr<A> a = std::make_shared<A> ();
    std::shared_ptr<B> b = std::make_shared<B> ();

    a->set_B(b);
    b->set_A(a); 

    return 0;
}