#include <iostream>

using namespace std;

int num {130};

void local_example(int x) {
    int num {100};
    cout << "Local num is: " << num << " in local example." << endl;
    num += x;
    cout << "Locat num is now: " << num << " pretty neat!" << endl;
}

void global_example() {
    cout << "Global num is: " << num << endl;
    num += 100;
    cout << "Now global num is :" <<  num << endl;

}

void static_local() {
    static int num {3333};
    cout << "Static local num is: " << num << " holy moly." << endl;
    num += 1000;
    cout << "Static local num is now going to be: " << num << endl;
}

int main () {
    int num {100};
    int num1 {500};

    {
        int num {200};
        cout << "Local to block statement, num is: " << num << endl;
        cout << "However, inside here, num1 is: " << num1 << endl;
    }

    cout << "Local to main scope, num is: " << num << endl;
    cout << "and also in here, num1 is: " << num1 << endl;


    local_example(23);
    local_example(41);

    global_example();
    global_example();
    global_example();

    static_local();
    static_local();
    static_local();


    return 0;
}