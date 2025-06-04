#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force 
// Time Complexity: O(n) + O(n)
// Space Complexity: O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majorityElement;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto it : freq) {
            if (it.second > n / 2) {
                majorityElement = it.first;
                break;
            }
        }
        return majorityElement;
    }
};

// 🟢 Approach 2: Optimal In-Place (Boyer-Moore Voting Algorithm)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majorityElement;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                majorityElement = nums[i];
                count++;
            } else if (nums[i] == majorityElement) {
                count++;
            } else {
                count--;
            }
        }
        return majorityElement;
    }
};