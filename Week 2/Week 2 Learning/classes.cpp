#include<iostream>

using namespace std;

class SomeClass {
    private:
        int x;
        int y;
    
    public:
        SomeClass() = default;      // Default constructor, that the language would have written for us.

        SomeClass(const SomeClass & other)      // Default constructor that the language provides for us!!! 
            : x(other.x), y(other.y) {}         // It does not create a copy but references to the other obj!!!

        SomeClass(const int xIn, const int yIn)
            : x(xIn), y(yIn) {}

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }
};

#if 1
int main() {
    SomeClass a(4,7);
    SomeClass b;        // Initialized throught the default one.

    SomeClass c = a;    // Uses the Copy Constructor to initialize the object.

    SomeClass d(1,2);

    d = a;              // d becomes the same obj as a!!!

    cout << "For a: x = " << a.getX() << " y = " << a.getY() << endl;
    cout << "For b: x = " << b.getX() << " y = " << b.getY() << endl;
    cout << "For c: x = " << c.getX() << " y = " << c.getY() << endl;
    cout << "For d: x = " << d.getX() << " y = " << d.getY() << endl;

    SomeClass e(3,4);

    a = d = e;      // = is right associative!!! same as a = (d = e)

    cout << "For a: x = " << a.getX() << " y = " << a.getY() << endl;
}
#endif

// Standard recipe for an assignment operator.
// It returns dereferenced actual obj of other!!
/*
    Someclass & operator=(const SomeClass & other)      // 1st -> & -> used to not return a copy but the actual object
    {
        x = other.x;
        y = other.y;

        return *this;   
    }
 */