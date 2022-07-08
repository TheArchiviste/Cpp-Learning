#include <iostream>
#include <memory>
#include <string>

using namespace std;

class MyName {
    private:
        // No need for delete => the obj, in out case - example, will fall out of scope at the end of main
        // The destructor of the unique_ptr class is called and deletes it.
        unique_ptr<string> str;

    public:
        MyName()
        : str(new string()) {}

        MyName(const MyName & other)
        : str(new string(*other.str)) {}

        string * getStr() {
            return str.get();
        }

        void addToStr(const char c) {
            str->push_back(c);
        }

        void printStr() {
            cout << *str << endl;
        }
};

#if 1
int main() {
    MyName example;

    example.addToStr('I');
    example.addToStr('v');
    example.addToStr('a');
    example.addToStr('n');

    example.printStr();

    // The default copy constructor simply tried copy paste from left to right!!
    // Had to write ours.
    MyName example2 = example;

    cout << *(example.getStr()) << endl;

    return 0;
}
#endif