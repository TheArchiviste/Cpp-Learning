#include<iostream>
#include<string>

using namespace std;

class IHazStringPtr {
    private:
        string * str;

    public: 
        IHazStringPtr() : str(new string()) {}

        // Default copy constructor.
        // Copying the pointer!!!
        // IHazStringPtr(const IHazStringPtr & other)
        //     : str(other.str) {}

        // // Second version.
        // // Deep copy -> copying the content!!!
        // IHazStringPtr(const IHazStringPtr & other) {
        //     if (other.str == nullptr) {
        //         str = nullptr;
        //     } else {
        //         str = new string(*(other.str));
        //     }
        // }

        // Third version - using ternary operator.
        // Same functionality as second.
        IHazStringPtr(const IHazStringPtr & other)
            : str(other.str == nullptr
                ? nullptr
                : new string(*(other.str))) {}

        void addCharacter(const char c) {
            str->push_back(c);
        }

        void printIt() const {
            cout << *str << endl;
        }

        // Standard overloading of the assignment operator.
        // IHazStringPtr & operator=(const IHazStringPtr & other) {
        //     str = other.str;

        //     return *this;
        // }

        // Second version - deep copy notion.
        IHazStringPtr & operator=(const IHazStringPtr & other) {
            if (str) {                                                          // Check whether this already points to somewhere!!!!
                delete str;
            }

            if (other.str) {
                str = new string(*(other.str));
            }
            else {
                str = nullptr;
            }

            return *this;
        }

        // DESTRUCTOR!!!
        ~IHazStringPtr() {
            cout << "The pointer is destroyed!" << endl;
            delete str;
        }
};

#if 1
int main() {
    IHazStringPtr a;
    // IHazStringPtr b;
    IHazStringPtr b = a;

    a.addCharacter('a');
    b.addCharacter('b');

    a.printIt();
    b.printIt();

    return 0;
}
#endif