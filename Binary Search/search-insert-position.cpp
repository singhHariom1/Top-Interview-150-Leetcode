#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] >= target)
                return i;
        }

        // If target is greater than all elements
        return n;
    }
};

// 🟢 Approach 2: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // target not found, return insertion position
        return low;
    }
};