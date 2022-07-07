#include<iostream>
#include<utility>

#include<demo.h>

using namespace std;

int main() {
    SimpleVector<int> nums(10);

    for (int i = 0; i < nums.size(); ++i) {
        nums[i] = 3 * i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }

    SimpleVector<pair<int, double>> pairs(7);

    pairs[0] = pair<int, double> (3, 4.2);

    return 0;
}
