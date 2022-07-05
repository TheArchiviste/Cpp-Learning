#include<iostream>
#include<string>

using namespace std;

#if 0
int main() {
    string c("Dave");               // c    is a string
                                    // &c   is a pointer to c - its adress in memory

    // We have stored the adress of c in both a and b.
    string * a = &c;
    string * b = &c;

    if (a == b) {                       // Equating the adresses not the CONTENTS !!!
        cout << "Dave is Dave" << endl;
    }
    else {
        cout << "Wrong!" << endl;
    }

    cout << "a is: > " << a << " and b is: > " << b << endl;
}
#endif

#if 1
int main() {
    string a("Hello");
    string * b = new string("Hello");

    string c = a;
    cout << c << endl;

    // string d = b;

    // string * e = a;

    string f = *b;
    cout << f << endl;

    string * g = b;
    cout << g << endl;

    string * h = &a;
    cout << h << endl;
}
#endif
