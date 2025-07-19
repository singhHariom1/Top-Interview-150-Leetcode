#include <bits/stdc++.h>
using namespace std;

// 🟢 Optimal Approach: Simulate Addition from Right to Left
// Time Complexity: O(n)
// Space Complexity: O(1) auxiliary, O(n) for output

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }

        // If we reached here, all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
