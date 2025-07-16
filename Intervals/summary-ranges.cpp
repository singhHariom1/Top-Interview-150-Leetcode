#include <bits/stdc++.h>
using namespace std;

// 🟢 Optimal Approach: One Pass with Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1) extra (output takes O(n) space)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int a = 0, b = 0;

        while (b < nums.size()) {
            // Move b while the sequence is continuous
            while (b < nums.size() - 1 && nums[b] + 1 == nums[b + 1]) {
                b++;
            }

            // Check if it's a single number or a range
            if (a == b) {
                result.push_back(to_string(nums[a]));
            } else {
                result.push_back(to_string(nums[a]) + "->" + to_string(nums[b]));
            }

            b++;
            a = b; // Start of next range
        }

        return result;
    }
};