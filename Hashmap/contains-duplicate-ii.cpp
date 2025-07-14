#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force
// Time Complexity: O(n * k)
// Space Complexity: O(1)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= i + k && j < n; ++j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};

// 🟢 Approach 2: Hash Map for Last Seen Indices (Your Approach)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;

        for (int i = 0; i < nums.size(); ++i) {
            if (hashMap.count(nums[i]) && abs(hashMap[nums[i]] - i) <= k) {
                return true;
            }
            hashMap[nums[i]] = i;
        }

        return false;
    }
};

// 🟣 Approach 3: Sliding Window using Hash Set
// Time Complexity: O(n)
// Space Complexity: O(min(n, k))
class Solution3 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); ++i) {
            if (window.count(nums[i])) return true;

            window.insert(nums[i]);

            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};
