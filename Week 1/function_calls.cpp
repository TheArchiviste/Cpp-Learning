#include <iostream>

using namespace std;

// Normal function call

#if 0
void printAnswer(int x) {
    cout << "The number " << x << " is stored as a variable in the fuction." << endl;
}

int main() {
    printAnswer(42);

    return 0;
}
#endif

// Function Prototyping

#if 1
void printAnswer(int x) {
    cout << "The number " << x << " is stored as a variable in the fuction." << endl;
}

int answer(); // It promises the compiler that the function is written somewhere down the file.

int main() {
    printAnswer(answer());

    return 0;
}

int answer() {
    return 36;
}
#endif