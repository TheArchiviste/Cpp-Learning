#include <iostream>

using namespace std;

// Different usage of the << operator.
#if 0
int main() {
    int i = 1;

    i = i << 3;     // Used to shitf bit in an int.
    
    cout << "i is now: " << i << endl;

    return 0;
}
#endif

/* 
    Binary          Decimal
    0000 0001         1     Initial
    0000 0010         2     1st shift
    0000 0100         4     2nd shift
    0000 1000         8     3rd shift
 */

class Coordinate {
    protected:
        int x;
        int y;

    public:
        Coordinate(int xIn, int yIn) // Constructor, where the variables are initialised before the brackets.
            : x(xIn), y(yIn) {
        }

        const int & getX() const {
            return x;
        }

        const int & getY() const {
            return y;
        }

        void setX(int newX) {
            x = newX;
        }

        void setY(int newY) {
            y = newY;
        }

/*      // Quality operator - used for compring non-primitive objects.
        // It is now made const safe.
        bool operator==(const Coordinate & other) const{
            return (x == other.x && y == other.y);
        } 
*/

        // Overloading arithmetic operators.
        Coordinate operator+(Coordinate other) {
            return Coordinate(x + other.x, y + other.y);
        }

        // Over loading the << operator.
        // Used to avoid writing geters, however, it requires to change the operator<< overload function!
        void write(ostream & o) const {
            o << x << ", " << y;
        }
 };

// Functions can live outside of the class.
// This will be used if there is no definition of the operator inside the class.
bool operator==(const Coordinate & lhs, const Coordinate & rhs) {
    return (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY());
}

// Overloading the << operator to be able to display datatypes that we have created.
ostream & operator<<(ostream & o, const Coordinate & rhs) {
    o << rhs.getX() << "," << rhs.getY();
    return o;
}

// Version that ignores writing geters in the class.
/* 

ostream & operator<<(ostream & o, const Coordinate & rhs) {
    ths.write(o);
    return o;
} 

*/

// Using the new notation for overloading ==
#if 0
int main() {
    Coordinate a(1, 6);
    Coordinate b(5, 3);
    Coordinate c(1, 6);

    if (a == b) {
        cout << "a = b" << endl;
    }

    if (a == c) {
        cout << "a = c" << endl;
    }

    return 0;
}
#endif

// Using the << to display a bespoke datatype -> not primitive type/ object we have created
// The << does not know how to treat them. 
#if 1
int main() {
    Coordinate a(1, 6);
    
    cout << "It is at " << a << endl;

    return 0;
}
#endif