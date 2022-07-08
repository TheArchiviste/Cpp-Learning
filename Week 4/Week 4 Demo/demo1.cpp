#include <iostream>

using namespace std;

#if 0
// const if there not gonna be any changes
// no const if there will be and so that we do not
// create tons of temporary var to store information in.
void someFun(const int & x) {
    // ++x;     // Contradiction
    cout << x << endl;
}

// Returns a tempo var
int getThree() {
    return 3;
}

int main() {
    int x = 42;
    int & y = x;

    // int & z = x + 4;     // Temporary var only last until the end of the line of code!!!!
                            // Then fall out of scope.
    int z = x + 4;

    someFun(x);
    someFun(y);

    someFun(3);          // Temporary => 3 = x
    // The compiler wants to prevent loss of information !!

    someFun(getThree());

    return 0;
}
#endif

#if 1
class JustOneNum {
    private:
        int three;

    public:
        JustOneNum() : three(3) {}

        // For good practice => Will arise the above problem
        // However it guards it, nontheless.
        const int & getThree() const {
            return three;
        }
};

void someFun(const int & x) {
    cout << x << endl;
}

int main() {
    JustOneNum a;

    // Get a reference to a member variable !!!
    someFun(a.getThree());

    return 0;
}
#endif