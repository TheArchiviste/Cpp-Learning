#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Important Notes:
/* 
    1 - Class are visible if they are in the unit of compilation. 
        If you can see a class you can access its objects and use it.
    
    2 - Constructors:
        a - If there is no written constructor the compiler creates a default one.
        b - There can be more than one compiler, however, they need to be different in terms of intake (order, number of parameters, est.).
        c - Variables must always go through a constructor to be initialised properly.
        d - Insisting on the constructor's functionality diminishes the chances of Null Pointer Exceptions.
*/

class Coordinate {
    protected:
        int x;
        int y;

    public:
        Coordinate(int xIn, int yIn) // Constructor, where the variables are initialised before the brackets.
            : x(xIn), y(yIn) {
        }

/*      Coordinate(int xIn, int yIn) { // Construcor, where the variables are initialised whitin the brackets.
            x = xIn;
            y = yIn;
        } 
*/

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        int setX(int newX) {
            return x = newX;
        }

        int setY(int newY) {
            return y = newY;
        }

        // Quality operator - used for compring non-primitive objects.
        bool operator==(Coordinate other) {
            return (x == other.x && y == other.y);
        }
};

#if 0
int main() {
    Coordinate a(4, -3);
    Coordinate b = a;   // Creates another objects that copies the values of object a. Using a copy constructor.

    cout << a.getX() << endl;
    cout << b.getX() << endl;

    a.setX(8);      // b will not change its value after a changes it.

    cout << a.getX() << endl;
    cout << b.getX() << endl;

    return 0;
}
#endif

/*
    Unless the following syntax is used, we cannot creat a vector
    holding Coordinate objects. The compiler will not be able to bind the 
    normal vector initialisation to any existing constructor in the class.
*/
#if 0
int main() {
    vector<Coordinate> coords;      // Initialises an empty vector.

    coords.push_back(Coordinate(4, -2));  // The push_back function pushes an object at the end of the vector.
    coords.push_back(Coordinate(3, 17));

    for (int i=0; i < coords.size(); ++i) {
        cout << "x = " << coords[i].getX() << endl;
        cout << "y = " << coords[i].getY() << endl;
    }

    return 0;
}
#endif

// Comparing objects that are not primitive -> Use quality operator.
#if 1
int main() {
    Coordinate a(4, -2);
    Coordinate b(4, -2);
    Coordinate c(5, 2);



    return 0;
}
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////

class Journey {
    protected:
        Coordinate start;
        Coordinate end;

    public:
        Journey(Coordinate startIn, Coordinate endIn) // Used when the member variable has no default constructor.
            : start(startIn), end(endIn) {
            }

/*      
    This will not compile due to that cpp requires to have all objects
    that the language is going to work with before it executes the first 
    line after the {} brackets.

        Journey(Coordinate startIn, Coordinate endIn) {
            start = startIn;
            end = endIn;
        } 
*/
};

//////////////////////////////////////////////////////////////////////////////////////////////////

// Using the string class.

void printLength(string a)  {
    cout << "The length is: "
        << a.size() << endl;
}

#if 0
int main() {
    string str = "Hello";
    string str2 = NULL;

    printLength(str);
    printLength(str2); // It will not raise exception. The constructor of the string class guarantees that it has length of at least 0.
}
#endif