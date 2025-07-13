#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class SolutionBruteForce {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// 🟢 Approach 2: Optimized using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
class SolutionOptimal {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // num -> index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {}; // Should not happen, as one solution is guaranteed
    }
};