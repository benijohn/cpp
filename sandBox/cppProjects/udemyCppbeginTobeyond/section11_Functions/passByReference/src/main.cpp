#include <iostream>
#include <vector>
#include <string>

using namespace std;

void pass_by_ref_1(int &num);
void pass_by_ref_2(string &s);
void pass_by_ref_3(vector<string> &v);
void print_vector(const vector<string> &v);

void pass_by_ref_1(int &num) {
    num = 1000;
}

void pass_by_ref_2(string &s) {
    s = "Changed";
}

void pass_by_ref_3(vector<string> &v) {
    v.clear();
}

void print_vector(const vector<string> &v) {
    for (string s: v) {
        cout << s;
    }
    cout << endl;
}



int main() {
    int num {100};
    string name {"Benjamin"};
    vector<string> stooges{"larry", "curly", "mo"};

    cout << num << endl;
    pass_by_ref_1(num);
    cout << num << endl;


    print_vector(stooges);
    pass_by_ref_3(stooges);
    print_vector(stooges);
    


    return 0;
}