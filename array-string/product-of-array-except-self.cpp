#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Prefix and Suffix Arrays (Extra Space)
// Time Complexity: O(n)
// Space Complexity: O(n) - Two extra arrays

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixArray(n), suffixArray(n), result(n);
        int prefix = 1, suffix = 1;

        for (int i = 0; i < n; i++) {
            prefixArray[i] = prefix;
            prefix *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            suffixArray[i] = suffix;
            suffix *= nums[i];
        }

        for (int i = 0; i < n; i++) {
            result[i] = prefixArray[i] * suffixArray[i];
        }

        return result;
    }
};

// 🟢 Approach 2: Optimal In-Place (Using Prefix in result[] and a Suffix Variable)
// Time Complexity: O(n)
// Space Complexity: O(1) - Ignoring the output array

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int prefix = 1, suffix = 1;

        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};
