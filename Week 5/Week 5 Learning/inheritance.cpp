#include <iostream>

using namespace std;

// sizeof(typename) -> tells us how much memory is used for each obj.

class Coordinate {
    private:
        int x;
        int y;

    public:
        Coordinate(const int xIn, const int yIn)
        : x(xIn), y(yIn) {}

        const int & getX() const {
            return x;
        }

        const int & getY() const {
            return y;
        }        

        virtual void printDetails() {
            cout << "x: " << x << " y: " << y << endl;
        }

        // Abstract class function
        // Pure virtual function that has yet to be implemented.
        // virtual void printDetails() = 0;
};

class Bikes : public Coordinate {
    protected:
        int howMany;

    public:
        Bikes(const int xIn, const int yIn, const int howManyIn)
        : Coordinate(xIn, yIn), howMany(howManyIn) {}

        // Making it a virtual function => In the end it will use the
        virtual void printDetails() override {
            Coordinate :: printDetails();
            cout << ": " << howMany << " bikes." << endl;
        }
};

#if 1
int main() {
    Coordinate a(3,4);

    cout << &a << endl;             // Where is a starts from => it will be the same as the x due to that x is the first data about a stored in memory.
    cout << &(a.getX()) << endl;    // Where is x of a 
    cout << &(a.getY()) << endl;    // Where is y of a

    // Upon introducing the virtual functions x and a do not have the same memory
    // address. => The virtual table has been altered with the introduction of the
    // virtual functions.

    return 0;
}
#endif

#if 0
void printHelper(Coordinate & c) {
    c.printDetails();
    cout << endl;
}

int main() {
    Bikes strand(20,10,100);

    strand.printDetails(); cout << endl;

    // If not overrided it will only use the super class's print Function
    printHelper(strand);

    return 0;
}
#endif

// Make all destructors virtual !!!
