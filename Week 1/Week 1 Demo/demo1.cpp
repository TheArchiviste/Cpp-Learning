#include <iostream>
#include <vector>

using namespace std;

// Compute the value of the vector multiplied by itself.
int selfDotProduct(vector<int> n) {
    int sum = 0;

    for (int i=0; i < n.size(); ++i) {
        sum += n[i] * n[i];
    }

    return sum;
}

#if 0 
int main() {
    vector<int> numbers(5);

    numbers[0] = 42;
    numbers[1] = 17;

    for (int i=0; i < numbers.size(); ++i) {
        numbers[i] = i;
    }

    for (int i=0; i < numbers.size(); ++i) {
        cout << "i = " << numbers[i] << endl;
    }

    cout << "Self product = " << selfDotProduct(numbers) << endl;
    
    return 0;
}
#endif

#if 1
int main() {
    vector<int> presetNumbers{41, 17, 1, 0, 12};

    for (int i=0; i < presetNumbers.size(); ++i) {
        cout << "i = " << presetNumbers[i] << endl;
    }

    cout << "Self product = " << selfDotProduct(presetNumbers) << endl;
    
    return 0;
}
#endif
