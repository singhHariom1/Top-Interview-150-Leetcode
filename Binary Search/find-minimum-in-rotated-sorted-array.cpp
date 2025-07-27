#include <bits/stdc++.h>
using namespace std;

// Time: O(n), Space: O(1)
int findMin(vector<int>& nums) {
    int mini = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        mini = min(mini, nums[i]);
    }
    return mini;
}


// 🟢 Approach: Modified Binary Search
// Time: O(log n), Space: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        
        while (start < end) {
            int mid = start + (end - start) / 2;

            // If mid element is greater than end, min is in right half
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            // Else, min is in left half including mid
            else {
                end = mid;
            }
        }
        
        return nums[start];
    }
};
