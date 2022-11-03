#include <iostream>
#include <string>

using namespace std;

int main () {
    string pyramid_string {};
    string reverse_pyramid {};
    string pyramid_copy {};
    string spaces {};

    cout <<  "Please enter a string to turn into a pyramid: " << endl;

    getline(cin, pyramid_string);

    for (char c: pyramid_string) {
        if (c == ' ') {
            continue;
        }
        else {
            reverse_pyramid.insert(0,1,c);
            pyramid_copy.push_back(c);
        }
    }
    spaces.insert(0, pyramid_copy.length(), ' ');

    for (int i {}; i < reverse_pyramid.length(); i++) {
        if (i == 0) {
            spaces.pop_back();
            cout << spaces << pyramid_copy.at(i) << endl;
        }
        else {
            spaces.pop_back();
            cout << spaces << pyramid_copy.substr(0, i+1) << reverse_pyramid.substr(reverse_pyramid.length() - i) << endl;
        }
    }

    return 0;
}