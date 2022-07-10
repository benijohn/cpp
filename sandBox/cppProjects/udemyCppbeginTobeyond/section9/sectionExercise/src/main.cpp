#include <vector>
#include <iostream>

using namespace std;

int calculate_pairs(vector<int> vec) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    int result{}, index{1}, minSize{2}, vecSize{};
    
    vecSize = int(vec.size());
    
    if (vecSize < minSize) {
        result = 0;
    }
    else {
        for (int num1: vec) {
            cout << num1 << "#########" << endl;
            if (index < vecSize){
                for (int i{index}; i<vecSize; i++) {
                    cout << "i is = " << i << endl;
                    result = result + num1*vec.at(i);
                    cout << result << endl;
                }
                index++;
            }
        }
    }
    

    
     
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return result;
}

int main() {
    vector<int> vec {1,2,3};

    calculate_pairs(vec);

    return 0;
}