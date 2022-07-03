#include <iostream>
#include <vector>

using namespace std;

// Important Notes:
/* 
    1 - Do not read off the bound of the vector! No exception will be raised.
*/

// Normal vector

#if 0
int main() {
    vector<int> numbers(10);
    for (int i=0; i < 10; ++i) {
        numbers[i] = i; // numbers[i] accesses an element of the vector at position i.
        cout << i << endl;
    }

    return 0;
}
#endif

#if 0
int main() {
    vector<int> numbers(10);
    numbers.resize(20); // Function used to resize the vector.
    for (int i=0; i < numbers.size(); ++i) { // Function used to obtain the size of the vector.
        numbers[i] = i;
        cout << i << endl;
    }

    return 0;
}
#endif

// Vector inside vector

#if 0
int main() {
    vector<vector<int>> nums 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i=0; i < nums.size(); i++) {
        for(int j=0; j < nums[i].size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#endif

#if 1
int main() {
    vector<vector<int>> nums 
    {
        {1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11,12}
    };

    for (int i=0; i < nums.size(); i++) {
        for(int j=0; j < nums[i].size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#endif