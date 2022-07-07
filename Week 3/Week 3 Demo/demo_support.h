#ifndef DEMOSUPPORT_H
#define DEMOSUPPORT_H

template<typename T>
class SimpleVector {
    private:
        T * elements;
        int sVSize;

    public:
        SimpleVector(const int n) 
        : elements(new T[n]), sVSize(n) {}

        ~SimpleVector() { delete [] elements; s}

        int size() const {
            return sVSize;
        }

        // Use reference due to that we do not know what we will have in the vectro.
        // It can be really large obj => might have a problem.
        T & operator[](const int i) {
            return elements[i];
        }
};

#endif