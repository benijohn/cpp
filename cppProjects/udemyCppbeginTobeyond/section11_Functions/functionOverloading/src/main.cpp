#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>);

int calc_area(int side_length);
int sq_area(int side_length);
double calc_area(double length, double width);
double rec_area(double length, double width);


int main() {
    print(5);
    print('a');
    print(23.4);
    print(23.4F);

    print("Hello!");
    print("Hello", "World");

    vector<string> v {"Ben", "is", "learning", "C++"};
    print(v);

    cout << "square overload: " << calc_area(3) << endl;
    cout << "rec overload: " << calc_area(2.3, 4.5) << endl;
    cout << "square: " << sq_area(2) << endl;
    cout << "rec: " << rec_area(2.3, 4.5) << endl;


    return 0;
}

void print(int num) {
    cout << "printing int: " << num << endl;
}

void print(double num) {
    cout << "printing double: " << num << endl;
}

void print(string s) { 
    cout << "printing string: " << s << endl;
}

void print(string s, string t) {
    cout << "printing 2 strings: " << s <<  " & " << t << endl;
}

void print(vector<string> v) {
    cout << "printing vector of strings: ";
    for (auto s: v) {
        cout << s << " ";
    }
    cout << endl;
}

int calc_area(int side_length) {
    return pow(side_length, 2);
}

double calc_area(double length, double width) {
    return length*width;
}

int sq_area(int side_length) {
    return pow(side_length, 2);
}

double rec_area(double width, double length) {
    return length*width;
}