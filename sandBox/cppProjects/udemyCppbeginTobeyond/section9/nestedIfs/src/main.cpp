#include <iostream>

using namespace std;

int main () {
    int score {};

    int a_plus {95};
    int a {90};
    int b {80};
    int c {70};
    int d {60};

    int max {100};
    int min {0};

    char letter_grade {};

    int run {1};
    while(run) {
        cout << "Enter your score: " << endl;
        cin >> score;

        if (score <= 100 && score >= 0) {
            if (score >= 90) {
                letter_grade = 'A';
            }
            else if (score >= 80) {
                letter_grade = 'B';
            }
            else if (score >= 70) {
                letter_grade = 'C';
            }
            else if (score >= 60) {
                letter_grade = 'D';
            }
            else {
                letter_grade = 'F';
            }

            if (letter_grade == 'F') {
                cout << "Sorry, your score is F. You need to repeat the course" << endl;
            }
            else {
                cout << "Your score is " << letter_grade << " hooray!" << endl;
            }

            run = 0;
        }
        else {
            cout << "Please enter a valid score between 0-100" << endl;
        };
    }

    return 0;
}