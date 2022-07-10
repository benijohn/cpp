#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec) {
    cout << "[ ";
    for (int num: vec) {
        cout << num << " ";
    }
    cout << "]" << endl;
    return;
}

double getMean(vector<int> vec) {
    double mean {}, sum{};
    for (int num: vec) {
        sum = sum+num;
    }
    mean = double(sum)/vec.size();
    return mean;
}

int findLargest(vector<int> vec) {
    int largest {};
    largest = vec.at(0);
    for (int num: vec) {
        (num > largest) ? largest = num: largest=largest;
    }
    return largest;
}

int findSmallest(vector<int> vec) {
    int smallest {};
    smallest = vec.at(0);
    for (int num: vec) {
        (num < smallest) ? smallest = num: smallest=smallest;
    }
    return smallest;
}

int main () {
    char input {};
    int vectorSize {};

    vector<int> vec {};

    do {
        vectorSize = int(vec.size());

        cout << "Welcome to the number finding progam!" << endl;

        cout << "P - Print Numbers" << endl;
        cout << "A - Add number to list" << endl;
        cout << "M - Find mean value of list" << endl;
        cout << "S - Find smallest value in list" << endl;
        cout << "L - Find largest value in list" << endl;
        cout << "C - Clear list" << endl;
        cout << "Q - Quit" << endl;

        cin >> input;

        switch (input) {
            case 'P':
            case 'p': {
                if (vectorSize < 1) {
                    cout << "The list is empty, consider adding some numbers to it using the add functionality." << endl;
                }
                else {
                    cout << "Print numbers:" << endl;
                    printVector(vec);
                }    
                break;
            }
            case 'A':
            case 'a': {
                int new_number {};
                cout << "Please enter an integer to add: " << endl;
                cin >> new_number;
                vec.push_back(new_number);
                printVector(vec);
                break;
            }
            case 'M':
            case 'm': {
                if (vectorSize < 1) {
                    cout << "The list is empty, consider adding some numbers to it using the add functionality." << endl;
                }
                else {
                    double mean{};
                    mean = getMean(vec);
                    cout << "Mean number: " << mean << endl;
                }    
                break;
            }
            case 'S':
            case 's': {
                if (vectorSize < 1) {
                    cout << "The list is empty, consider adding some numbers to it using the add functionality." << endl;
                }
                else {
                    int smallest {};
                    smallest = findSmallest(vec);
                    cout << "Smallest number: " << smallest << endl;
                }    
                break;
            }
            case 'L':
            case 'l': {
                if (vectorSize < 1) {
                    cout << "The list is empty, consider adding some numbers to it using the add functionality." << endl;
                }
                else {
                    int largest {};
                    largest = findLargest(vec);
                    cout << "Largest number: " << largest << endl;
                }    
                break;
            }
            case 'Q':
            case 'q': {
                cout << "Quitting now, Goodbye!" << endl;
                break;
            }
            case 'C':
            case 'c': {
                char sure {};
                do {
                    cout << "Are you sure you want to clear the list? (Y/N): " ;
                    cin >> sure;
                    if (sure == 'Y' || sure == 'y') {
                        cout << "Clearing list" << endl;
                        vec.clear();
                    }
                    else if (sure == 'N' || sure == 'n') {
                        cout << "Ok good! " << endl;
                    }
                    else {
                        cout << "Invalid answer - hint try reading the prompt \n" << endl;
                    }
                } while (sure != 'Y' && sure != 'y' && sure != 'N' && sure != 'n');    
                break;
            }
            default: 
            cout << "\nInvalid selection - please review the input options\n\n" << endl;
        }


    } while (input != 'q' && input != 'Q');

    return 0;
}