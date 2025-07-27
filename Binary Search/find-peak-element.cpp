#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force
// Time Complexity: O(n)
// Space Complexity: O(1)
// Check each element and see if it is greater than its neighbors
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool left = (i == 0) || (nums[i] > nums[i - 1]);
            bool right = (i == n - 1) || (nums[i] > nums[i + 1]);
            if (left && right)
                return i;
        }
        return -1; // Shouldn't be reached as there's always one peak
    }
};


// 🟢 Approach 2: Binary Search (Optimal)
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Use the fact that if nums[mid] < nums[mid+1], then peak lies on the right
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] < nums[mid + 1])
                s = mid + 1;
            else
                e = mid;
        }
        return s;
    }
};
