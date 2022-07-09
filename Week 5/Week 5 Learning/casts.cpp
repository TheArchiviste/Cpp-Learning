#include <iostream>
#include <memory>

using namespace std;

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
};

class Bikes : public Coordinate {
    protected:
        int howMany;

    public:
        Bikes(const int xIn, const int yIn, const int howManyIn)
        : Coordinate(xIn, yIn), howMany(howManyIn) {}

        virtual void printDetails() override {
            Coordinate :: printDetails();
            cout << ": " << howMany << " bikes." << endl;
        }

        // Dynamic casts = instanceof + cast
        // Provides a check whether 
        void sFun1(Coordinate * c) {
            Bikes * b = dynamic_cast<Bikes*>(c);
            if (b) {
                cout << b->howMany << endl;
            }
            else {
                cout << "It isnt not a bikes obj!!!";
            }
        }            
};

void printHelper(Coordinate & c) {
    c.printDetails();
    cout << endl;
}

// Will only compile if it is the right type
void sFun(Coordinate * c) {
    // Checks that Bikes is a sub-class of Coordinate
    // at compile time.
    Bikes * b = static_cast<Bikes*>(c);
}

// Checks it's the right type at runtime, returns nullptr if it is not
void sFun2(Coordinate * c) {
    // Checks at runtime. It compare the V-table pointer
    // of c with the one for Bikes obj.
    Bikes * b = dynamic_cast<Bikes*>(c);
}

// How to dynamically cast sth into reference.
void sFun3(Coordinate & c) {
    try {
        Bikes & b = dynamic_cast<Bikes&>(c);
    }
    catch (const bad_cast & e) {}
}

// reinterpret_cast => Does no checks

// const_cost => Use only when you have no write access to the code
//               and there is const put in the wrong place.


// Statics casts / Compile time casts.
#if 0
int main() {
    int a = 7;

    double b = (double) a;

    unique_ptr<int> c(new int(7));

    // Refers to the .operator bool() function in the unique_ptr
    // class => How we define function which we can then cast to.
    bool d = (bool) c;

    return 0;
}
#endif

// Statics casts / Compile time casts.
#if 1
int main() {
    int a = 7;

    // Makes a temporary double (R-value) that is a
    // copy of a
    double b = static_cast<double>(a);

    unique_ptr<int> c(new int(7));

    bool d = static_cast<bool>(c);

    return 0;
}
#endif