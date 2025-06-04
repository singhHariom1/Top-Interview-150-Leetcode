#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1: Brute Force (Rotate by 1 step, k times)
// Time Complexity: O(n * k)
// Space Complexity: O(1)
// Not efficient for large inputs

class Solution_BruteForce {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        for (int t = 0; t < k; t++) {
            int last = nums[n - 1];
            for (int i = n - 1; i > 0; i--) {
                nums[i] = nums[i - 1];
            }
            nums[0] = last;
        }
    }
};


// 🟠 Approach 2: Extra Array with Manual Slicing
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution_ExtraArrayManual {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> temp(n);

        int i = 0;

        for (int j = n - k; j < n; j++) {
            temp[i++] = nums[j];
        }

        for (int j = 0; j < n - k; j++) {
            temp[i++] = nums[j];
        }

        for (int j = 0; j < n; j++) {
            nums[j] = temp[j];
        }
    }
};


// 🟡 Approach 3: Extra Array using Modulo Index Trick
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution_ModIndex {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};


// 🟢 Approach 4: In-Place Reversal Method (Optimal)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        // Reverse entire array
        reverse(nums.begin(), nums.end());

        // Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse remaining n - k elements
        reverse(nums.begin() + k, nums.end());
    }
};
