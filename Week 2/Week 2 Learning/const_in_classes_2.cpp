#include<iostream>

using namespace std;

class Demo {
    private:
        int x;
        int y;

    public:
        Demo() = default;
                                        // The second const ->
        int const & getX() const {      // The function is not allowed to change 
            return x;                   // the private memeber variables of the class.
        }                               // The first const ->
                                        // Protects the reference from being changed.
        int getY() const {
            return y;
        }
};

// Until we add & to the getter function the compiler is fine.
// The above functions with & return a copy so there is no way of 
// the private variable being changed.

// const in this function if the above one has been secure in both ways
// is not necessary due to that changes are blocked at the base level.
// However it leaves open space for error on sth that hasnt been guarded at the base level.
void playWithVars(Demo d) {
    cout << "The x value is: " << d.getX() << " and the y value is: " << d.getY() << endl;
}