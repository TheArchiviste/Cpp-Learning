#include<iostream>
#include<list>
#include<set>

using namespace std;

#if 0
int main() {
    list<int> nums;

    nums.push_back(17);
    nums.push_back(12);
    nums.push_back(3);

    for (int n : nums) {
        cout << n << endl;
    }

    // Cannot obtain a particular element from the list without iterator!!!
    auto itr = nums.begin();

    cout << *itr << endl;

    ++itr;

    auto justIns = nums.insert(itr, 42);

    for (int n : nums) {
        cout << n << endl;
    }

    cout << *justIns << endl;

    auto thirdElem = nums.begin();

    nums.erase(thirdElem);

    for (int n : nums) {
        cout << n << endl;
    }

    return 0;
}
#endif

#if 1
int main() {
    set<int> uniqueNums;
    // We are not concerned where to put them.
    // they are sorted in acending order.
    // Ignores duplicates !!!!
    uniqueNums.insert(2);
    uniqueNums.insert(25);
    uniqueNums.insert(21);
    uniqueNums.insert(7);

    for (int elem : uniqueNums) {
        cout << elem << endl;
    }

    auto itr = uniqueNums.find(25);

    if (itr == uniqueNums.end()) {
        cout << "Not Found!" << endl;
    }
    else {
        cout << "Found it! " << *itr << endl;
        uniqueNums.erase(itr);
    }

    for (int elem : uniqueNums) {
        cout << elem << endl;
    }

    return 0;
}
#endif