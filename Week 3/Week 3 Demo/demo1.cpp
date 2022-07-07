#include<iostream>
#include<utility>
#include<vector>

#include<demo.h>

using namespace std;

template<typename T>
// No const in front of T due to that the being and end functions are not const usable
// They should not be const usable because we want to use the iterator to also apply changes.
void printIt(T & toPrint) {
    for (auto & element : toPrint) {
        cout << element << endl;
    }
}

int main() {
    SimpleVector<int> nums(10);

    for (int i = 0; i < nums.size(); ++i) {
        nums[i] = 3 * i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }

    for (int someNums : nums) {
        cout << someNums << endl;
    }

    printIt(nums);

    SimpleVector<pair<int, double>> pairs(7);

    pairs[0] = make_pair(3, 4.2);

    return 0;
}
