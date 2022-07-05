#include<iostream>
#include<string>

using namespace std;

class Coordinate {
    protected:
        int x;
        int y;
        string cordName;

    public:
        Coordinate(const int xIn, const int yIn, const string & cordNameIn)
            : x(xIn), y(yIn), cordName(cordNameIn){

            cout << "Made a Coordinate: " << cordName << endl;
        }

        int getX() const{
            return x;
        }

        int getY() const {
            return y;
        }

        const string & getcordName() const {
            return cordName;
        }

        void setX(int newX) {
            x = newX;
        }

        void setY(int newY) {
            y = newY;
        }

        bool operator==(Coordinate other) {
            return (x == other.x && y == other.y);
        }
};

void obtainCord(const Coordinate * cord) {
    cout << "The Coordinate: " << cord->getcordName() << "has x: " 
            << cord->getX() << " and y: " << cord->getY() << endl;
}

#if 0
int main() {
    Coordinate * a = new Coordinate(4, 3, "Tamsin");
    Coordinate * b = nullptr;
    
    cout << a->getY() << endl;

    // obtainCord(b);          // Generates segmantation error.                                      
    // obtainCord(a);

    obtainCord(a);
    // obtainCord(b);            // Still generates segmentation error, but run everything prior.

    return 0;
}
#endif

#if 0
int main() {
    Coordinate * a = new Coordinate(1, 2, "First");                                     // a    is a Coordinate
    Coordinate * b = new Coordinate(1, 2, "Second");                                    // * a  is a pointer to Coordinate
                                                                                        // *a   is a Coordinate             (Dereferencing)
    if (a == b) {
        cout << a->getcordName() << " is " << b->getcordName() << endl;
    }
    else {
        cout << "Wrong!" << endl;
    }

    if (*a == *b) {
        cout << a->getcordName() << " is " << b->getcordName() << endl;
    }
    else {
        cout << "Wrong!" << endl;
    }

    return 0;
}
#endif

#if 0
int main() {
    int i = 9;
    int * y = new int(99);

    cout << "To access i we only need i: > " << i << endl;
    cout << "To access y we need *y: > " << *y << endl;

    return 0;
}
#endif

#if 1
struct Coord
{
    int x=0;
    int y=0;
};

int main() {
    Coord * a = nullptr;
    
    a->x = 9;
    a->y = 3;

    cout << "To access a's x value we need: >" << a->x << endl;
    cout << "To access a's y value we need: >" << a->y << endl;

    return 0;
}
#endif

#if 0
struct Coord
{
    char x=0;
    char y=0;
};

int main() {
    Coord a (12, 34);
    Coord* p = &a;

    char v = p->x;  // v = 12
    char w = p->y;  // w = 34
    
    // alternative:
    char s = (*p).x;  // s = 12
    char t = (*p).y;  // t = 34

    return 0;
}
#endif