#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force
// Time Complexity: O(√x)
// Space Complexity: O(1)

class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;
        while (i * i <= x) {
            i++;
        }
        return i - 1;
    }
};

// 🟡 Approach 2: Binary Search
// Time Complexity: O(log x)
// Space Complexity: O(1)

class Solution {
    public:
        int mySqrt(int x) {
            if (x < 2) return x;
            int left = 1, right = x, ans = 0;
    
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                if (mid * mid <= x) {
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return ans;
        }
};

// 🟢 Approach 3: Newton's Method (a.k.a. Babylonian Method)
// Time Complexity: O(log x) (converges fast)
// Space Complexity: O(1)

class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0) return 0;
            double guess = x;
            while (guess * guess > x) {
                guess = (guess + x / guess) / 2;
            }
            return (int)guess;
        }
};          