#include<iostream>
#include<utility>
#include<vector>

using namespace std;

pair<double, double> getMinAndMax(const vector<double> & n) {
    double min = n[0];
     double max = n[0];

    for (int i = 0; i < n.size(); ++i) {
            
    } 

    return pair<double, double> (min, max);
}

#if 1
int main() {

    return 0;
}
#endif

// if we need more than 2 variable -> tuple

// Other useful containers.
// std::list -> doubly-linked-list
// std::set -> set  (in Java -> TreeSet)
// std::unordered_set -> a hash set
// std::deque -> a double-ended queue