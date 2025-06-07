#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Manual Subtraction Check (If-Else Conditions)
// Time Complexity: O(n)
// Space Complexity: O(1)
/*
🔍 Idea:
- Subtract when you detect one of the 6 special subtractive cases:
  I before V or X
  X before L or C
  C before D or M
- To avoid double-counting, use 'continue;' after subtraction
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbolToValue = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int value = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (i + 1 < s.length()) {
                if ((ch == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
                    (ch == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
                    (ch == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))) {
                    value -= symbolToValue[ch];
                    continue;
                }
            }
            value += symbolToValue[ch];
        }

        return value;
    }
};

// 🟢 Approach 2: Right-to-Left Traversal with Value Comparison
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
🔍 Intuition:
- Normally, Roman numerals are additive (e.g., VI = 5 + 1).
- But in special cases (like IV, IX, etc.), the smaller value before a larger one means subtraction.
- So we process the string from **right to left**:
   - If the current value is **less than** the previous one → subtract it.
   - Else → add it.
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int n = s.size();
        int result = romanMap[s[n - 1]];  // Start with the last value
        for (int i = n - 2; i >= 0; i--) {
            if (romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            } else {
                result += romanMap[s[i]];
            }
        }

        return result;
    }
};
