#include<iostream>
#include<string>

using namespace std;

// Every NEW must be parid with DELETE!
// If we do not delete our pointers => results in memory leaks.
// The heap will be overcrowded with useless data.
#if 0
int main() {
    string * s = new string("Hello");

    cout << *s << endl;

    delete s;
}
#endif

// We have to delete out pointer at every possible snenario!!!
void myFun(const string & a) {
    string * b = new string("Hello");

    if (a == *b) {
        cout << "Input string was: Hello" << endl;
        delete b;   //
        return;
    }

    cout << "Input string was not Hello!" << endl;
    delete b;   //
}
