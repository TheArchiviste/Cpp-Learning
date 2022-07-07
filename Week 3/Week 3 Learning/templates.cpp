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

#if 1
int main() {
    template_array<int> a(10);
    template_array<double> b(5);

    return 0;
}
#endif
