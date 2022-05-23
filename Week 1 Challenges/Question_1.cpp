/* 

Write a function printVector that takes a vector of ints, and prints the values one after the other to screen, with commas in between the values.

For instance,

vector<int> numbers{0,3,9};
printVector(numbers);

...should print out:

0,3,9 

*/

#include <iostream>
#include <vector>

using namespace std;

// Solution 1
#if 1
void printVector(vector<int> v) {
    for(int i=0; i < v.size(); ++i) {
        if(i == v.size() - 1) {
            cout << v[i];
        }
        else {
            cout << v[i] << ",";
        }
    }
}

int main() {
    vector<int> nums {0, 3, 9};

    printVector(nums);

    return 0;
}
#endif
