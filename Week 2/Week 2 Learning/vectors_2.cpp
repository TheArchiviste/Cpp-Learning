#include<iostream>
#include<vector>

using namespace std;

#if 0
int addNums(const vector<int> & toAdd) {
    int answer = 0;

    for (int i = 0; i < toAdd.size(); ++i) {
        answer += toAdd[i];
    }

    return answer;
}

int main() {
    cout << addNums({1,2,3,4,5,6}) << endl;

    return 0; 
}
#endif

#if 1
int main() {
    vector<int> nums {1,2,3,4,5};

    // Operator overloading on the [] operator!
    nums[0] += 1;

    for(int i=0; i < nums.size(); ++i) {
        nums[i] += 1;
        cout << nums[i] << endl;
    }

    return 0;
}
#endif
