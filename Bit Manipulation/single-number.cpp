#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach: Bit Manipulation using XOR
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // cancel out pairs
        }
        return result;
    }
};