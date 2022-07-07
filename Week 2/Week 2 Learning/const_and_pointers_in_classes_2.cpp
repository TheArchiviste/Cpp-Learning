#include<iostream>

using namespace std;

class Demo {
    private:
        int x;
        int *y;

    public:
        int const & getX() const {
            return x;
        }

        // 2nd -> the pointer is const, 
        // 1st -> the piece of data it points to is const
        int const * const getY() const {
            return y;
        }
};

void playWithVars(Demo d) {
    cout << "The x value is: " << d.getX() << " and the y value is: " << endl;

    cout << (*d.getY()) << endl;
}

#if 1
int main() {
    Demo a;

    playWithVars(a);

    return 0;
}
#endif