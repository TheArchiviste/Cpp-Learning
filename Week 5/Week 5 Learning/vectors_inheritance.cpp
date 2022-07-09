#include <iostream>
#include <memory>
#include <vector>

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
};

void printHelper(Coordinate & c) {
    c.printDetails();
    cout << endl;
}

#if 1
int main() {
    Coordinate c = Bikes(3,4,20);
    // Same as what it happens in the above.
    // If we want to use pointers instead.
    unique_ptr<Coordinate> a(new Bikes(5,6,10));

    // If we want to also store obj of type Bikes in the
    // Coordinate vector (subclasses of the super)
    vector<unique_ptr<Coordinate>> b;
    b.emplace_back(new Bikes(7,8,5));

    // We do not use push_back due to that it requires a
    // unique_ptr obj that in this case we do not have.

    // emplace_back => make a new unique_ptr at the end of
    // the vector and pass what is in the () to its constructor.
}
#endif