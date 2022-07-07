#include<iostream>
#include<utility>
#include<map>
#include<string>

using namespace std;

#if 1
int main() {
    map<int, string> idToName;
    // If a key is already taken, it wont override the value with another!!!

    // First way of inserting an element.
    // idToName.emplace(3241, string()).first->second;      Calls the default constructor for the value.
    // Same as the above one 
    // We can ONLY use it if there is a default constructor for the value obj!!!
    idToName[1234] = "Ivan";
    // Second way.
    idToName.insert(pair<int, string>(4321, "James"));
    // Third way.
    idToName.emplace(3241, "Homes");

    for (auto & elem : idToName) {
        cout << "key = " << elem.first << " value = " << elem.second << endl;
    }

    // Returns itr.
    pair<map<int, string> :: iterator, bool> insResult = idToName.emplace(1234, "Kiki");

    if (insResult.second) {
        cout << "Data was inserted!" << endl;
    }
    else {
        cout << "Data was NOT inserted" << endl;
    }

    // Force change the value!!!
    auto mapItr = insResult.first;
    // (*mapItr).second = "Kiki";
    mapItr->second = "Kiki";

    for (auto & elem : idToName) {
        cout << "key = " << elem.first << " value = " << elem.second << endl;
    }

    auto lookup = idToName.find(4321);

    if (lookup == idToName.end()) {
        cout << "Nothing :/" << endl;
    }
    else {
        cout << "Key = " << lookup->first << ", Value = " << lookup->second << endl;
        idToName.erase(lookup);
    }

    for (auto & elem : idToName) {
        cout << "key = " << elem.first << " value = " << elem.second << endl;
    }

    return 0;
}
#endif