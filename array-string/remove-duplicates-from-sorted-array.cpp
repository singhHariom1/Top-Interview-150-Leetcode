// 🟠 Approach 1: Using Set
// Time Complexity: O(n log n)+O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            s.insert(num);
        }

        int i = 0;
        for (int num : s) {
            nums[i] = num;
            i++;
        }
        return i;
    }
};

// 🟢 Approach 2: Optimal In-Place (Two Pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};