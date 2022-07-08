#include<iostream>

using namespace std;

#if 0
int main() {
    int a = 3;      // Left -> a, Right -> 3
    int b = a + 7;  // Left -> b, Right -> a + 7

    // Wrong!!
    // 3 = a * c;
    // a * c = 3;
}
#endif

#if 0
int someFun() {
    int a = 3; int b = 4;
    return a + b;
}

int main() {
    int x = 14;
    int & z = x;

    // Works because it is supplying y with a copy!!!
    int y = someFun();

    // Wrong
    // Cannot assign a reference to a temporary value!!!
    // int & y = someFun();

    return 0;
}
#endif

#if 0
// L-value references !!!
int main() {
    int a = 7;

    int & b = a;    // reference to a l-value
    int & c = b;
    // As soon as a falls out of scope b and c will also
    // be deleted.

    return 0;
}
#endif

#if 1
// Must be const to work out!!!
// Therefore contradiction !!!
void increment(double & d) {
    d += 1;
}

int main() {
    int x = 7;

    // Int to a Double function, thus
    // The compiler coppies the int into a temporary variable.
    // However, taking the reference to the temp var will not work!!!

    // increment(x);

    cout << x << endl;

    return 0;
}
#endif