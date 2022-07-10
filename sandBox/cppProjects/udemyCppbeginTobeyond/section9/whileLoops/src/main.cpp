#include <iostream>
#include <vector>
#include <numeric>
#include <string>



using namespace std;


int main () {
    char selection {};
    vector<int> choices (3);

    iota(choices.begin(), choices.end(), 1);

    do {
        cout << "\n=====================" << endl;
        for (int choice: choices) {
            cout << choice << ": Do case "<< choice << endl;
        }
        cout << "q/Q: Quit" << endl;
        cout << "Please enter your selection: ";
        cin >> selection;


        cout << selection << endl;

        switch (selection) { 
            case '1': {
                cout << "Doing the first thing." << endl;
                break;
            }
            case '2': {
                cout << "Doing the second thing." << endl;
                break;
            }
            case '3': {
                cout << "Doing the third thing." << endl;
                break;
            }
            case 'q':
            case 'Q' : {
                cout << "Qitting....." << endl;
                break;
            }
            default:
            cout << "Invalid selection please review the selections." << endl;
            break;
        }

    } while(selection != 'q' && selection != 'Q');

    return 0;
}