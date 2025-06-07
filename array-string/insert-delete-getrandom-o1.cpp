#include <bits/stdc++.h>
using namespace std;

// 🟢 Problem: Implement RandomizedSet with insert, remove, getRandom in O(1) average time

class RandomizedSet {
public:
    unordered_map<int, int> valToIndex; // Maps value -> index in 'values' vector
    vector<int> values;                  // Stores inserted values for O(1) access

    // Constructor: seed random once for getRandom
    RandomizedSet() {
        srand(time(0));
    }

    // 🟢 Insert val if not present, return true if inserted, false otherwise
    bool insert(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            values.push_back(val);
            valToIndex[val] = (int)values.size() - 1;
            return true;
        }
        return false;
    }

    // 🟢 Remove val if present, return true if removed, false otherwise
    // Uses swap-with-last and pop_back trick for O(1) deletion
    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end())
            return false;

        int index = valToIndex[val];
        int lastElement = values.back();

        values[index] = lastElement;            // Overwrite index with last element
        valToIndex[lastElement] = index;        // Update map for moved element

        values.pop_back();                       // Remove last element
        valToIndex.erase(val);                   // Erase val from map

        return true;
    }

    // 🟢 Return a random element from the current set
    int getRandom() {
        int randomizedIndex = rand() % (int)values.size();
        return values[randomizedIndex];
    }
};
