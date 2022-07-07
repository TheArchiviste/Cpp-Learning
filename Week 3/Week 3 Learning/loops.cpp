#include<iostream>
#include<vector>

using namespace std;

// Range for loop
void printIt(const vector<int> & p){
    // Has to match!!!
    for (const int & item : p) {
        cout << item << endl;
    }
}

// Using deduction to determine the type that is passed.
void printIt2(const vector<int> & p) {
    for (auto & item : p) {
        cout << item << endl;
    }
}

#if 1
int main() {
    int a = 7;
    auto b = a + 2;

    const string c = "Hello";
    auto & d = c;

    cout << b << endl;
    cout << d << endl;

    return 0;
}
#endif