#include <iostream>
#include <utility>
#include <memory>
#include <vector>

using namespace std;

// Already in built!!
template<typename T>
class Unique_Ptr
{
    private:
        T * d;

    public:
        Unique_Ptr(T * dIn)
        : d(dIn) {}

        Unique_Ptr()
        : d(nullptr) {}

        // Move constructor ->
        Unique_Ptr(Unique_Ptr && other)
        : d(other.d) {
            other.d = nullptr;
        }

        ~Unique_Ptr() {
            delete d;
        }

        Unique_Ptr(const Unique_Ptr & other) = delete;

        T * get() {
            return d;       // If you need the pointer for sth.
        }                   // We do not own it => when it falls out of scope it gets deleted.

        T * reset(T * newD) {
            delete d;
            d = newD;       //  Make it point to sth else.
        }

        T * release() {
            T * toReturn = d;
            d = nullptr;    // the unique ptr no longer owns d.

            return toReturn;
        }

        // Unique_Ptr & operator=(const Unique_Ptr & other) = delete;

        Unique_Ptr & operator=(Unique_Ptr && other) {       // R-value reference!!
            delete d;
            d = other.d;
            other.d = nullptr;

            return *this;
        }

        // Makes so that the unique_ptr can be treated as a boolean.
        operator bool() {
            return d != nullptr;
        }
};

class Coordinate
{
    private:
        int x;
        int y;

    public:
        Coordinate(int xIn, int yIn)
        : x(xIn), y(yIn) {} 
};

unique_ptr<Coordinate> sFun() {
    return unique_ptr<Coordinate>(new Coordinate(3,4));
}

#if 0
int main() {
    unique_ptr<Coordinate> a;

    a = sFun();

    return 0;
}
#endif

// Unique pointers help us move data from one obj to another
// and at the same time avoid copying r-values that are about to
// get deleted. Also improves efficiency.


// Forcing a movement!!!
#if 1
int main() {
    vector<int> nums(1000000);
    vector<int> a(move(nums));

    cout << nums.size() << endl;
    cout << a.size() << endl;

    return 0;
}
#endif