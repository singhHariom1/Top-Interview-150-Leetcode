#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force (TLE)
// Time Complexity: O(right - left)
// Space Complexity: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = left;
        for (int i = left + 1; i <= right; ++i) {
            result &= i;
            if (result == 0) break;
        }
        return result;
    }
};

// 🟢 Approach 2: Bit Manipulation - Common Prefix
// Time Complexity: O(1) (max 32 shifts)
// Space Complexity: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // Find common prefix
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};

// 🟢 Approach 3: Brian Kernighan's Trick
// Time Complexity: O(logN) — number of set bits in `right`
// Space Complexity: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};
