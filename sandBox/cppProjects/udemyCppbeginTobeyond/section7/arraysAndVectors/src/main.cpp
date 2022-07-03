/**********************************************************************
 * Udemy Class C++ Beginner to Beyond
 * Author: Benjamin Johnson
 * Date: 2022-06-26
 * 
 * *******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main () {
    char vowels_array [] {'a','e','i','o','u'}; // character array static size 
    vector <char> vowels_vector {'a','e','i','o','u'}; // same values but in vector form

    cout << "Vowel number 1 is " << vowels_array[0];
    cout << "Vowel number 5 is " << vowels_vector[4];

    vector <int> test_scores {34, 21, 65, 37, 83, 23}; // vector of ints dynamic in size

    cout << "Using array syntax" << endl;
    cout << "The test scores are:" << endl;
    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[2] << endl;
    cout << test_scores[3] << endl;
    cout << test_scores[4] << endl;

    cout << "Using vetor syntax" << endl;
    cout << "The test scores are:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;
    cout << test_scores.at(4) << endl;
    cout << "There are " << test_scores.size() << " scores in the vector" << endl;

    cout << "Please enter another test score" << endl;
    int score_to_add {0};
    cin >> score_to_add;
    test_scores.push_back(score_to_add);
    cout << "The size of the test scores vector is now " << test_scores.size() << "." << endl;

    vector <double> daily_temps (365, 23.1); // note the parenthesis, first value is size of vector second value is initial value of all elements
    // vectors in cpp are objects which means they have many built in helpful methods including the .at() method for accessing values in the vector
    // this will also perform out of bounds checking which is nice!

    return 0;
}