#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<map>

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

#if 0
int main() {
    vector<int> a {2,4,6,8};

    // Same as all the code for the iterator + while loop above!!!
    for (int & element : a) {
        cout << element << endl;
    }

    return 0;
}
#endif

#if 0
int main() {
    list<int> a {1,2,3,4};

    auto itr = a.begin();   // First thing

    ++itr;      // Second     Same as auto itr = a.begin() + 2;
    ++itr;      // Third

    for (int & element : a) {
        cout << element << endl;
    }

    // Inserts it at the third postion, due to that the iterator was there at the time!!!
    auto newItr = a.insert(itr, 10);

    for (int & element : a) {
        cout << element << endl;
    }

    ++itr;

    auto newItr1 = a.erase(itr);

    for (int & element : a) {
        cout << element << endl;
    }

    return 0;
}
#endif

#if 0
int main() {
    set<int> a {1,2,3,4};

    // If not match was found returns end()
    auto itr = a.find(7);

    if (itr == a.end()) {
        cout << "7 was not found!" << endl;
    }
    else {
        cout << "We found it :D" << endl;
        a.erase(itr);
    }

    return 0;
}
#endif

#if 1
// Already in built!!!
template<typename T>
class Less {
    public:

        bool operator() (const T & lhs, const T & rhs) {
            return (lhs < rhs);
        }
};

int main() {
    // Builds a binary search tree.
    map<int, string> kNums;

    kNums[12345] = "Annie";
    kNums[54321] = "Ivan";

    for (auto & elem : kNums) {
        cout << "k: " << elem.first << " = " << elem.second << endl;
    }

    auto itr = kNums.find(12345);

    if (itr == kNums.end()) {
        cout << "Not found!" << endl;
    }
    else {
        cout << "Found it: " << (*itr).first << " is " << (*itr).second << endl;
    }

    return 0;
}
#endif