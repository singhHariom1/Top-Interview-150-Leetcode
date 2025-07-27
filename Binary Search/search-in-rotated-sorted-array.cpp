#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force (Linear Search)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) return i;
        }
        return -1;
    }
};



// 🟢 Approach 2: Modified Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
// Intuition:
// - One half of the array is always sorted.
// - Use binary search to identify the sorted half.
// - Check if the target lies within that half; if not, discard it and continue in the other half.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) return mid;

            // Left half is sorted
            if (nums[s] <= nums[mid]) {
                if (nums[s] <= target && target < nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }

            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return -1;
    }
};
