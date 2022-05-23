#include <iostream>

using namespace std;

class Coordinate {
    protected:
        int x;
        int y;

    public:
        Coordinate(int xIn, int yIn) // Constructor, where the variables are initialised before the brackets.
            : x(xIn), y(yIn) {
        }

        int getX() {                // Returns a copy of x.
            return x;
        }

        int & getXReference() {     // Returns a reference to x.
            return x;
        }

        int getY() {
            return y;
        }

        void setX(int newX) {
            x = newX;
        }

        void setY(int newY) {
            y = newY;
        }
};

class Journey {
    protected:
        Coordinate start;
        Coordinate end;

    public:
        Journey(Coordinate startIn, Coordinate endIn) // Used when the member variable has no default constructor.
            : start(startIn), end(endIn) {
        }

        Coordinate getStartCopy() {     // Returns a copy of the object.
            return start;
        }

        Coordinate & getStartReference() {      // Returns a reference to the actual object.
            return start;                       // Any changes will now affect the actual referenced object.
        }
};


// Makes a copy of the object.
#if 0
void moveXToZero(Coordinate in) {   // The function is only given the value of the object => creates a copy with this value.
    in.setX(0);
}

int main() {
    Coordinate a(4, -3);
    moveXToZero(a);

    cout << a.getX() << endl;   // The change is done on the copy of the object, which exists only
}                               // within the scope of moveXToZero function.
#endif

#if 1
int main() {
    Journey j(Coordinate(1, 1), Coordinate(10, 3));

    Coordinate a = j.getStartReference();       // We are assigning the returned reference value to "a". 
    a.setX(0);                                  // What happens is, the compiler creates a copyy of the reference.

    cout << j.getStartReference().getX() << endl;
}
#endif

// Makes a reference to the object.

// Important Notes:
/* 
    1 - The name cannot be assigned to any other object
        within that function.
    2 - Aliases cannot be null.
    3 - Becomes useful when we need to use object that are excessively large.
        Instead of copying the whole object, we will be making changes directly onto it.
    4 - Through reference we allow private variables to mutate => prone to errors
*/
#if 0
void moveXToZero(Coordinate & in) {     // "in" becomes an alias of the object, meaning just another name for the already existing object.
    in.setX(0);                         // Changes will persist and will be assigned to the referenced object.
}

int main() {
    Coordinate a(4, -3);
    moveXToZero(a);

    cout << a.getX() << endl;
}
#endif

#if 0
int main() {
    Journey j(Coordinate(1, 1), Coordinate(10, 3));

    Coordinate & a = j.getStartReference();     // A reference of the "start" of "j" is sotred in "a", which is
    a.setX(0);                                  // reference to Coordinate. => a becomes another name for j.getStartReference()

    cout << j.getStartReference().getX() << endl;
}
#endif