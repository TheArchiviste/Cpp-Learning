#include<iostream>

#include<demo_support.h>

using namespace std;

int main() {
    SimpleVector<int> nums(10);

    for (int i = 0; i < nums.size(); ++i) {
        nums[i] = 3 * i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }

    return 0;
}
