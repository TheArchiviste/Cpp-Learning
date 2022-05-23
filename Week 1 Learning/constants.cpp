#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Important Notes:
/* 
    1 - Const == Read only
*/

class Coordinate {
    protected:
        int x;
        int y;

    public:
        Coordinate(int xIn, int yIn) // Constructor, where the variables are initialised before the brackets.
            : x(xIn), y(yIn) {
        }

        int getX() const{       // We are making a flag to the compiler that this class function can be
            return x;           // compatible/used with const. Also this makes a requirement to outsider 
        }                       // function also to bear the key word const.

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

#if 0
void printCoordinateX(Coordinate & in) {
    cout << in.getX() << endl;
    in.setX(0);
    cout << in.getX() << endl;
}

void printConstCoordinateX(const Coordinate & in) {     // const protects the fields of being mutated by the function.
    cout << in.getX() << endl;
}

int main() {
    Coordinate a(5, 8);

    printCoordinateX(a);
    printConstCoordinateX(a);

    return 0;
}
#endif

class Journey {
    protected:
        Coordinate start;
        Coordinate end;

    public:
        Journey(Coordinate startIn, Coordinate endIn) // Used when the member variable has no default constructor.
            : start(startIn), end(endIn) {
        }

        const Coordinate & getStart() {     // Returns the value of start as a reference to Coordinate, which is const safe.
            return start;                   // Whatever the return values is, is read only.
        }
};

#if 1
int main() {
    Journey j(Coordinate(1, 1), Coordinate(10, 3));

    Coordinate a =j.getStart();             // Correct!
    // Coordinate & b = j.getStart();       // Wrong! 
    const Coordinate & c = j.getStart();    // Correct!
    const Coordinate d = j.getStart();      // Correct!

    return 0;
}
#endif