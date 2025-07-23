#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach: Bitwise reversal (32 steps)
// Time Complexity: O(32)
// Space Complexity: O(1)

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++) {
            res = (res << 1) | (n & 1);  // Add last bit of n to result
            n >>= 1;                    // Right shift input to process next bit
        }
        return res;
    }
};