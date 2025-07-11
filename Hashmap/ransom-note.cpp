#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force (Erase characters from magazine string)
// Time Complexity: O(m * n)
// Space Complexity: O(1)

class BruteForceSolution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (char ch : ransomNote) {
            size_t pos = magazine.find(ch);
            if (pos == string::npos) return false;
            magazine.erase(pos, 1); // Remove the used character
        }
        return true;
    }
};

// 🟢 Approach 2: Frequency Count using Array
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class OptimalSolution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);  // Only lowercase letters

        for (char ch : magazine) {
            freq[ch - 'a']++;
        }

        for (char ch : ransomNote) {
            if (--freq[ch - 'a'] < 0)
                return false; // Not enough characters
        }

        return true;
    }
};
