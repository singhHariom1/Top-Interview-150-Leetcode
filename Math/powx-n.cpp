#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach: Iterative Binary Exponentiation (Clean & Readable)
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Handles negative exponents and INT_MIN edge case using long long

class Solution {
    public:
        double myPow(double x, int n) {
            double ans = 1;
            long long N = n;
            if (N < 0) {
                x = 1 / x;
                N = -N;
            }
            while (N) {
                if (N & 1) {
                    ans *= x;
                    N -= 1;
                } else {
                    x *= x;
                    N >>= 1;
                }
            }
            return ans;
        }
};    