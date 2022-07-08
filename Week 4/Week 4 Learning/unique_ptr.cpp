#include <iostream>
#include <utility>
#include <memory>

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

        ~Unique_Ptr() {
            delete d;
        }

        Unique_Ptr(const Unique_Ptr & other) = delete;

        Unique_Ptr & operator=(const Unique_Ptr & other) = delete;
};

class Coordinate
{
    private:
        int x;
        int y;

    public:
        Coordinate(const int xIn, const int yIn)
        : x(xIn), y(yIn) {} 
};

unique_ptr<Coordinate> sFun() {
    return unique_ptr<Coordinate>(new Coordinate(3,4));
}

#if 1
int main() {
    unique_ptr<Coordinate> a;

    a = sFun();

    return 0;
}
#endif