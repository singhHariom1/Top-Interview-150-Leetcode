#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Sorting-based (Brute Force)
// Time Complexity: O(n log n)
// Space Complexity: O(1) if in-place sorting, else O(n) for copy
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int longest = 1, current = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) continue;  // skip duplicates
            if (nums[i] == nums[i-1] + 1)
                current++;
            else {
                longest = max(longest, current);
                current = 1;
            }
        }
        return max(longest, current);
    }
};


// 🟢 Approach 2: HashSet-based Optimal Solution (O(n))
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Only try to build sequence from the *start* of a streak
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};