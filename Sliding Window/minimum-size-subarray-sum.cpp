#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), minLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                if (sum >= target) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

// 🟢 Approach 2: Optimal (Sliding Window)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0, minLen = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left++];
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};
