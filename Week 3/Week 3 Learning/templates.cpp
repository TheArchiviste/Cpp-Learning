#include<iostream>

using namespace std;

template<typename T>
// An array of (nearly) anything.
class template_array {
    private:
        T * elements;
        int arraySize;

    public:
        template_array(const int s)
        : elements(new T[s]), arraySize(s) {}

        ~template_array() { delete [] elements; }

        T & operator[](const int idx) { return elements[idx]; }

        int size() const { return arraySize; }
};

template<typename T>
const T & max1(const T & a, const T & b) {
    if (a < b) {
        return b;
    }
    else {
        return a;
    }
}

template<typename T, typename Comp>
const T & max2(const T & a, const T & b, Comp comp) {
    if (a < b) {
        return b;
    }
    else {
        return a;
    }
}

// auto + templates
template<typename T>
void printIt(const T & p) {
    for (auto & next : p) {
        cout << next << endl;
    }
}

#if 1
int main() {
    template_array<int> a(10);
    template_array<double> b(5);

    int c = 10;
    int d = 5;

    int biggest = max1<int>(c, d);

    cout << biggest << endl;

    return 0;
}
#endif
