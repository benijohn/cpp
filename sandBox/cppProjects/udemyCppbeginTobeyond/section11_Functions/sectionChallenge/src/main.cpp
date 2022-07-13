#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &vec); 
void addToVector(vector<int> &vec);
double getMean(const vector<int> &vec);
int findLargest(const vector<int> &vec);
int findSmallest(const vector<int> &vec);
void displayMenu();
char upperInput();
void clearVector(vector<int> &vec);
void emptyListMessage();
bool checkNumber(string str);
void meanVector(const vector<int> &vec);
void smallestVector(const vector<int> &vec);
void largestVector(const vector<int> &vec);


int main () {
    char input {};
    vector<int> vec {};

    do {
        displayMenu();
        input = upperInput();

        switch (input) {
            case 'P':{
                printVector(vec);   
                break;
            }
            case 'A':{
                addToVector(vec);
                break;
            }
            case 'M':{
                meanVector(vec);   
                break;
            }
            case 'S':{
                smallestVector(vec);    
                break;
            }
            case 'L':{
                largestVector(vec);   
                break;
            }
            case 'Q':{
                cout << "Quitting now, Goodbye!" << endl;
                break;
            }
            case 'C': {
                clearVector(vec);    
                break;
            }
            default: 
            cout << "\nInvalid selection - please review the input options\n\n" << endl;
        }


    } while (input != 'q' && input != 'Q');

    return 0;
}

void displayMenu() {
    cout << "\n\nWelcome to the number finding progam!" << endl;

    cout << "P - Print Numbers" << endl;
    cout << "A - Add number to list" << endl;
    cout << "M - Find mean value of list" << endl;
    cout << "S - Find smallest value in list" << endl;
    cout << "L - Find largest value in list" << endl;
    cout << "C - Clear list" << endl;
    cout << "Q - Quit" << endl;

}

char upperInput() {
    char input {};
    cin >> input;
    return toupper(input);
}

void clearVector(vector<int> &vec) {
    char sure {};
    do {
        cout << "\nAre you sure you want to clear the list? (Y/N): " ;
        sure = upperInput();
        if (sure == 'Y') {
            cout << "\nClearing list" << endl;
            vec.clear();
        }
        else if (sure == 'N') {
            cout << "\nOk good! " << endl;
        }
        else {
            cout << "\nInvalid answer - hint try reading the prompt \n" << endl;
        }
    } while (sure != 'Y' && sure != 'N');

}

void printVector(const vector<int> &vec) {
    if (vec.size() < 1) {
        emptyListMessage();
    }
    else {
        cout << "\nPrint numbers:" << endl;
        cout << "[ ";
        for (int num: vec) {
        cout << num << " ";
        }
        cout << "]\n" << endl;
    } 
    return;
}

double getMean(const vector<int> &vec) {
    double mean {}, sum{};
    for (int num: vec) {
        sum = sum+num;
    }
    mean = double(sum)/vec.size();
    return mean;
}

int findLargest(const vector<int> &vec) {
    int largest {};
    largest = vec.at(0);
    for (int num: vec) {
        (num > largest) ? largest = num: largest=largest;
    }
    return largest;
}

int findSmallest(const vector<int> &vec) {
    int smallest {};
    smallest = vec.at(0);
    for (int num: vec) {
        (num < smallest) ? smallest = num: smallest=smallest;
    }
    return smallest;
}

void addToVector(vector<int> &vec) {
    string input {};
    int new_number {};
    cout << "\nPlease enter an integer to add: " << endl;
    cin >> input;
    if (checkNumber(input)){
        new_number = stoi(input);
        vec.push_back(new_number);
    }
    else {
        cout << "\nInvalid Input" << endl;
    }
    printVector(vec);
}

void emptyListMessage() {
    cout << "\nThe list is empty, consider adding some numbers to it using the add functionality." << endl;
}

bool checkNumber(string str) {
   for (char c: str)
   if (isdigit(c) == false && c != '-')
      return false;
      return true;
}

void meanVector(const vector<int> &vec) {
    if (vec.size() < 1) {
        emptyListMessage();
    }
    else {
        double mean{};
        mean = getMean(vec);
        cout << "\nMean number: " << mean << endl;
    }
}

void smallestVector(const vector<int> &vec) {
    if (vec.size() < 1) {
        emptyListMessage();
    }
    else {
        int smallest {};
        smallest = findSmallest(vec);
        cout << "\nSmallest number: " << smallest << endl;
    } 
}

void largestVector(const vector<int> &vec) {
    if (vec.size() < 1) {
        emptyListMessage();
    }
    else {
        int largest {};
        largest = findLargest(vec);
        cout << "\nLargest number: " << largest << endl;
    }

}