#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main() {

    string s0;
    string s1 {"Apple"};
    string s2 {"Banana"};
    string s3 {"Kiwi"};
    string s4 {"apple"};
    string s5 {s1};
    string s6 {s1, 0, 3};
    string s7 (10, 'X');

    // cout << s0 << endl;
    // cout << s0.length() << endl;

    // cout << "\nInitialization" << "\n-------------------------------" << endl;
    // cout << "s1 is initialized to: " << s1 << endl;
    // cout << "s2 is initialized to: " << s2 << endl;
    // cout << "s3 is initialized to: " << s3 << endl;
    // cout << "s4 is initialized to: " << s4 << endl;
    // cout << "s5 is initialized to: " << s5 << endl;
    // cout << "s6 is initialized to: " << s6 << endl;
    // cout << "s7 is initialized to: " << s7 << endl;

    // cout << "\nComparison" << "\n-------------------------" << endl;
    // cout << boolalpha;

    // cout << s1 << "==" << s5 << ":" << (s1==s5) << endl;
    // cout << s1 << "==" << s2 << ":" << (s1==s2) << endl;
    // cout << s1 << "!=" << s2 << ":" << (s1!=s2) << endl;
    // cout << s1 << "<" << s2 << ":" << (s1<s2) << endl;
    // cout << s2 << ">" << s1 << ":" << (s2>s1) << endl;
    // cout << s4 << "<" << s5 << ":" << (s4<s5) << endl;
    // cout << s1 << "==" << "Apple" << ":" << (s1=="Apple") << endl;

    s1 = "Watermelon";
    cout << "s1 is now: " << s1 << endl;

    s2 = s1;
    cout << "s2 is now: " << s2 << endl;

    s3 = "benjamin";
    cout << "s3 is now: " << s3 << endl;

    s3[1] = 'o';
    cout << "now your name is: " << s3 << endl;

    s3.at(6) = 'm';
    cout << s3 << endl;


    s3 = s5 + " and " + s5 + " juice";
    cout << s3 << endl;

    s1 = "This is a test";
    cout << s1.substr(0, 4) << endl;

    s1.erase(0, 4);
    cout << s1 << endl;

    cout <<  "\n\nPlease enter your full name" << endl;
    getline(cin, s1);
    cout << s1 << endl;

    cout << s1.find("j") << endl;





    return 0;
}