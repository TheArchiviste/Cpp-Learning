/* 

The price of a given commodity, can be represented by a vector of prices -- each corresponding to the price at some point in time. 
For instance:

vector<int> prices {28, 18, 20, 26, 24};

To maximise profit, we would want to buy low and sell high -- in this case, buy at time 1 (when the cost is 18), 
sell at time 3 (when the cost is 26), to give a profit of 8.

Implement a function bestProfit that takes a vector of prices and returns the best profit that can be made.  
For instance, when given the input above, it should return the value 8.

*/

#include <iostream>
#include <vector>

using namespace std;

// Solution 1
#if 0
int bestProfit(vector<int> v) {
    int m = v.front(); // buying
    int n = v.front(); // selling
    unsigned int result = 0;
    
    for(int i=0; i < v.size(); ++i) {      // for loop with double variable inside the condition!!!
        if(n > v[i]) {
            n = v[i];
            v.erase(v.begin());
            m = v.front();
            break;
        }
    }
    for(int j=0; j < v.size(); ++j) {
        if(m < v[j]) {
            m = v[j];
        }
    }
    
    result = m - n;
    
    return result;
}

int main() {
    vector<int> prices {28, 18, 20, 26, 24};

    cout << bestProfit(prices) << endl;

    return 0;
}
#endif

// Solution 2
#if 1
int bestProfit(vector<int> v) {
    
}

int main() {
    vector<int> prices {28, 18, 20, 26, 24};

    cout << bestProfit(prices) << endl;

    return 0;
}
#endif