#include <iostream>
#include <string>

using namespace std;

// Normal string
#if 0
int main() {
    string a = "The";
    string b = "Archiviste";
    string c = a + b; // String concatanation.

    cout << c << endl;

    c[3] = 'B'; // Changes the character of the string at position 3/ cell 4.

    cout << c << endl;

    return 0;
}
#endif

// Character manipulation
#if 1
int main() {
    char a = 'A'; // Must use '' instead of "" when making the assignment.
    char b = 65;  

    cout << a << endl;
    cout << b << endl;
    cout << (a == b) << endl; // (a == b) represent an if statement

    // Both have the same output.
    
    string c = "xyz";

    c[1] = a;

    cout << c << endl;

    c += b; // Add the value of b at the end of c.

    cout << c <<endl;
    
    return 0;
}
#endif