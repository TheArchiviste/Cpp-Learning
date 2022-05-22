#include <iostream>

using namespace std;

/* 
    Variables do not have default values. Therefore the value,
    assigned to the not initialised variable will be something that
    is currently being stored in the RAM
*/

int main() {
    int i;
    int y = 0;

    cout << "i+1 = " << i+1 << endl;
    cout << "y+1 = " << y+1 << endl;

    return 0;
}