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
#if 0
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

// Comparing strings
#if 0
int main() {
    // These are not references to the objects in the memory. They are the actual objects.
    string a = "Dave"; 
    string b = "Dave";
    
    // Therefore, we can compare them like this:
    // Works only with primitive objects and strings!!!
    if (a == b) {
        cout << "Dave is Dave" << endl;
    }

    return 0;
}
#endif

#if 1
int main() {
    string a = "1234";

    cout << stoi(a) << endl;

    return 0;
}
#endif