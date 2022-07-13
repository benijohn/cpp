#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_value_1(int num);
void pass_by_value_2(string s);
void pass_by_value_3(vector<string> v);
void print_vector(vector<string> v);

void pass_by_value_1(int num) {
    num = 1000;
}

void pass_by_value_2 (string s) {
    s = "Changed";
}

void pass_by_value_3 (vector<string> v) {
    v.clear();
}

void print_vector (vector<string> v) {
    for (auto s: v) {
        cout << s << " ";
    }
    cout << endl;
}

int main () {
    int num {10};
    int another_num {20};

    cout << "num before calling pass_by_value_1 " << num << endl;
    pass_by_value_1(num);
    cout << "num after calling pass_by_value_1 " << num << endl;

    cout << "\nanother_num before calling pass_by_value_1 " << another_num << endl;
    pass_by_value_1(another_num);
    cout << "another_num after calling pass_by_value_1 " << another_num << endl;

    string name {"Frank"};
    cout << "\nThe name before PBV2 is: " << name << endl;
    pass_by_value_2(name);
    cout << "The name after PBV2 is: " << name << endl;

    vector<string> stooges {"larry", "curly", "mo"};
    cout << "\nThe stooges before PBV3 is: ";
    print_vector(stooges);
    pass_by_value_3(stooges);
    cout << "The stooges after PBV3 is: ";
    print_vector(stooges);


    return 0;
}