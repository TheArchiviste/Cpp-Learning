#include<iostream>

using namespace std;

class Car {
    protected:
        double speed;
        double range;

    public:
        Car(const double speedIn, const double rangeIn)
        : speed(speedIn), range(rangeIn) {}

        double getRange() const {
            return range;
        }

        // We can overload an operator only once !!!!
        bool operator<(const Car & other) const {
            return speed < other.speed;
        }
};

class LTByRange {
    public:

        bool operator()(const Car a, const Car b) {
            return a.getRange() < b.getRange();
        }
};

#if 0
int main() {
    Car a(123.00, 300);
    Car b(100.00, 400);

    LTByRange comp;

    if (comp(a,b)) {
        cout << "a has less range than b" << endl;
    }

    return 0;
}
#endif

#if 1
// Same behaviour as above one!!!
int main() {
    Car a(123.00, 300);
    Car b(100.00, 400);

    // Car highestRange = max(a, b, LTByRange());
    auto highestRange = max(a, b, LTByRange());

    return 0;
}
#endif