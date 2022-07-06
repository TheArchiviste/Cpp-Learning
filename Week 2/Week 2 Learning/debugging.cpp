#include <iostream>
#include <vector>

using namespace std;

#if 0
int main() {
    vector<int> nums{1,2,3,4,5};

    for(int i=0; i < 5; ++i) {          // If we use "<=" instead there will be a bug.
        cout << nums[i] << endl;        // There is nothing that stops you to keep iterating even after the end of the vector.
    }                                   // It will get any junk value that is in memory at that time and return it.
}                                       // Alwats end 1 before the end of the vector.
#endif

#if 1
int main() {
    vector<int> nums{1,2,3,4,5};                                        // It may result in a segmentation fault = code has crashed.
                                                                        // Using the GDB debugger - gdb ./filename - run - bt for backtracking
    for(int i=0; i < 10; ++i) {
        if (nums[i] > 100) {
            cout << "Entry: " << i << " is really big number" << endl;  // If there is no crash -> Valgrin
        }

        cout << nums[i] << endl;
    }
}
#endif