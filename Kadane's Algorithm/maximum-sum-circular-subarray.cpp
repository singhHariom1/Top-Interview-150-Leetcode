#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------
// 🟠 Approach 1: Brute Force (Nested loops)
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Not suitable for large arrays (TLE)
// ------------------------------------------

class BruteForceSolution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];

        for (int i = 0; i < n; ++i) {
            int currSum = 0;
            for (int j = 0; j < n; ++j) {
                currSum += nums[(i + j) % n];
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum;
    }
};



// ----------------------------------------------------
// 🟡 Approach 2: Kadane’s for Non-Circular Only
// Time Complexity: O(n)
// Space Complexity: O(1)
// Limitation: Misses circular contributions
// ----------------------------------------------------

class KadaneOnlySolution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], curr = 0;

        for (int n : nums) {
            curr = max(n, curr + n);
            maxSum = max(maxSum, curr);
        }

        return maxSum;
    }
};



// -------------------------------------------------------------------------------------
// 🟢 Approach 3: Optimal – Kadane's for Max + Min Subarray
// Time Complexity: O(n)
// Space Complexity: O(1)
// Works for circular case using: max(normal kadane, total - min kadane)
// -------------------------------------------------------------------------------------

class OptimalCircularSolution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int n : nums) {
            curMax = max(n, curMax + n);
            maxSum = max(maxSum, curMax);

            curMin = min(n, curMin + n);
            minSum = min(minSum, curMin);

            total += n;
        }

        // If all numbers are negative, total - minSum = 0 (invalid)
        if (maxSum < 0) return maxSum;

        return max(maxSum, total - minSum);
    }
};
