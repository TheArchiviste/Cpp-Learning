#ifndef DEMO_H
#define DEMO_H

template<typename T>
class SimpleVector {
    private:
        T * elements;
        int sVSize;

    public:
        SimpleVector(const int n) 
        : elements(new T[n]), sVSize(n) {}

        SimpleVector(const SimpleVector & other)
        : elements(new T[other.sVSize]), sVSize(OTHER.sVSize) {

            for (int i = 0; i < sVSize; ++i) {
                elements[i] = other.elements[i];
            }
        }

        ~SimpleVector() { delete [] elements;}

        int size() const {
            return sVSize;
        }

        // Use reference due to that we do not know what we will have in the vectro.
        // It can be really large obj => might have a problem.
        T & operator[](const int i) {
            return elements[i];
        }

        // Protects the content of being altered.
        const T & operator[](const int i) const{
            return elements[i];
        }

        SimpleVector & operator=(const SimpleVector & other) {
            delete [] elements;

            elements = new T[other.elements];
            sVSize = other.sVSize;

            for (int i = 0; i < sVSize; ++i) {
                elements[i] = other.elements[i];
            }

            return *this;
        }
};

#endif