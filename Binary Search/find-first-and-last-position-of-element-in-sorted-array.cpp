#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 0: Brute Force (Linear Scan)
// - Loop through the array and record the first and last index where target is found

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                if (first == -1) first = i;
                last = i;
            }
        }
        return {first, last};
    }
};


// 🟠 Approach 1: Binary Search + Expand Linearly
// Time: O(log n) for binary search + O(n) in worst case
// Space: O(1)
// - Do binary search once to find one occurrence
// - Expand left and right linearly to find full range
// ⚠️ Still not O(log n) in worst-case scenarios like [2,2,2,...,2]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int firstIndex = -1, lastIndex = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                firstIndex = mid;
                lastIndex = mid;
                while (firstIndex >= 0 && nums[firstIndex] == target) firstIndex--;
                while (lastIndex < nums.size() && nums[lastIndex] == target) lastIndex++;
                return {firstIndex + 1, lastIndex - 1};
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return {-1, -1};
    }
};


// 🟢 Approach 2: Optimal Binary Search (O(log n))
// - Do binary search TWICE:
//   - First to find leftmost (first) occurrence
//   - Second to find rightmost (last) occurrence

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int s = 0, e = nums.size() - 1, ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (findFirst)
                    e = mid - 1; // go left
                else
                    s = mid + 1; // go right
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
};


// 🤖 Approach 3: Using STL (lower_bound & upper_bound)
// Time: O(log n)
// Space: O(1)
// ⚠️ Only works in C++ with lower_bound / upper_bound

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(), nums.end(), target);
        auto up = upper_bound(nums.begin(), nums.end(), target);
        if (low == nums.end() || *low != target) return {-1, -1};
        return {int(low - nums.begin()), int(up - nums.begin() - 1)};
    }
};
