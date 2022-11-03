#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


int main () {
    char first_name[20]{};
    char last_name[20]{};
    char full_name[50]{};
    char temperature[50]{};

    // cout << first_name;
    // cout << last_name;
    // cout << full_name;
    // cout << temperature;

    // cout << "Enter your first name: ";
    // cin >> first_name;
    // cout << "Enter your last namme: ";
    // cin >> last_name;

    // cout << "\n";
    // cout << "Hello " << first_name << " your first name has " << strlen(first_name) << " characters." << endl;
    // cout << "Your last name " << last_name << " has " << strlen(last_name) << " characters." << endl;
    // cout << "\n";

    // strcpy(full_name, first_name);
    // strcat(full_name, " ");
    // strcat(full_name, last_name);
    // cout << "Your full name is " << full_name << "." << endl;

    // Inputting long(multi word strings)

    // cout << "Please enter your full name: ";
    // cin >> full_name;

    // cout << "Your full name is " << full_name << "." << endl;

    cout << "Please enter your full name: ";
    cin.getline(full_name, 50);

    cout << "Your full name is " << full_name <<  "." << endl;

    return 0;
}