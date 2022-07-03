#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> vector1 (0);
    vector <int> vector2 (0);

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "The elements of vector 1 are: " << vector1.at(0) << ", " << vector1.at(1) << endl;
    cout << "The length of vector 1 is: " << vector1.size() <<  endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "The elements of vector 2 are: " << vector2.at(0) << ", " << vector2.at(1) << endl;
    cout << "The length of vector 2 is: " << vector2.size() <<  endl;

    vector <vector<int>> vector_2d (0);

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "The first element in the 2 dimensional vector is: " << vector_2d.at(0).at(0) << ", " << vector_2d.at(0).at(1) << endl;
    cout << "The second element in the 2 dimensional vector is: " << vector_2d.at(1).at(0) << ", " << vector_2d.at(1).at(1) << endl;
    cout << "The size of the 2 dimensional vector is: " << vector_2d.size() << endl;

    vector1.at(0) = 1000;

    cout << "The first element in the 2 dimensional vector is: " << vector_2d.at(0).at(0) << ", " << vector_2d.at(0).at(1) << endl;
    cout << "The second element in the 2 dimensional vector is: " << vector_2d.at(1).at(0) << ", " << vector_2d.at(1).at(1) << endl;
    cout << "The elements of vector 1 are: " << vector1.at(0) << ", " << vector1.at(1) << endl;


    return 0;
}