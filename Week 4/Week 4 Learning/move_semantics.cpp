#include <iostream>
#include <vector>

using namespace std;

class Example {
    private:
        int * myArr;

    public:
        Example() {
            myArr = new int[2500000];

            for(int i=0; i < 2500000; ++i) {
                cout << "ctor: " << myArr << endl;
            }
        }

        Example(const Example & other) {
            myArr = other.myArr;

            cout << "CPY other Arr from: " << other.myArr << " to Arr " << myArr << endl;
        }

        Example(Example && other) {
            myArr = other.myArr;
            other.myArr = nullptr;

            cout << "MOVE other Arr from: " << other.myArr << " to Arr" << myArr << endl;
        }
};

Example MakeExample() {
    Example myExample;

    return myExample;
}

// The goal of the move semantics is to get the value of the temp variable
// without the need to copy 
int main() {
    auto thisExample = move(MakeExample());

    return 0;
}