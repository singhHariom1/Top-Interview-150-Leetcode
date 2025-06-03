// 🟠 Approach 1: 
// Time Complexity: O(n)+O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0, n = nums.size();
        for (int num : nums) {
            if (num == val)
                k++;
        }

        int i = 0, j = n - 1;
        while (i < j) {
            if (nums[j] == val) {
                j--;
            } else if (nums[i] == val && nums[j] != val) {
                swap(nums[i++], nums[j--]);
            } else {
                i++;
            }
        }
        return n - k;
    }
};

// 🟢 Approach 2: Optimal In-Place (Two Pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};