#include<iostream>
#include<vector>

using namespace std;

class VectorIntIterator {
    public:
        int * position;

        VectorIntIterator(int * data)
        : position(data) {}

        int & operator*() {
            return *position;
        }

        void operator++() {
            ++position;
        }
};

#if 0
int main() {
    vector<int> a {2,4,6,8};

    vector<int> :: iterator itr = a.begin();
    // Trap!!!!!
    // However the .end() returns a pointer to one beyond the end of the vector

    int first = *itr;

    ++itr;
    int second = *itr;

    ++itr;
    int third = *itr;

    cout << first << endl;
    cout << second << endl;
    cout << third << endl;

    return 0;
}
#endif

#if 0
int main() {
    vector<int> a {2,4,6,8};

    vector<int> :: iterator itr = a.begin();
    const vector<int> :: iterator itrEnd = a.end();

    // while (itr != itrEnd) {
    //     cout << *itr << endl;
    //     ++itr;
    // }

    for (; itr != itrEnd; ++itr) {
        cout << *itr << endl;
    }

    return 0;
}
#endif

#if 0
int main() {
    vector<int> a {2,4,6,8};

    auto itr = a.begin();           // Less code same outcome!!!
    const auto itrEnd = a.end();

    while (itr != itrEnd) {
        cout << *itr << endl;
        ++itr;
    }

    return 0;
}
#endif

#if 1
int main() {
    vector<int> a {2,4,6,8};

    // Same as all the code for the iterator + while loop above!!!
    for (int & element : a) {
        cout << element << endl;
    }

    return 0;
}
#endif