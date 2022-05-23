#include <iostream>

using namespace std;

// Different usage of the << operator.
#if 1
int main() {
    int i = 1;

    i = i << 3;     // Used to shitf bit in an int.
    
    cout << "i is now: " << i << endl;

    return 0;
}
#endif

/* 
    Binary          Decimal
    0000 0001         1     Initial
    0000 0010         2     1st shift
    0000 0100         4     2nd shift
    0000 1000         8     3rd shift
 */