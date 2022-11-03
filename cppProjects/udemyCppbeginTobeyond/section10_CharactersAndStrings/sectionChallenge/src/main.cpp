#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

int main () {
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ "};
    string key {"ZYXWVUTSRQPONMLKJIHGFEDCBA zyxwvutsrqponmlkjihgfedcba"};

    string message {};
    string encrypted_message {};
    string decrypted_message {};

    cout << "Type a letter to find in the strings: " << endl;
    getline(cin, message);

    for (char letter: message) {
        cout << alphabet.find(letter) << endl;
        encrypted_message += key.at(alphabet.find(letter));
    }

    cout << encrypted_message << endl;

    for (char letter: encrypted_message) {
        decrypted_message += alphabet.at(key.find(letter));
    }

    cout << decrypted_message << endl;



    return 0;
}