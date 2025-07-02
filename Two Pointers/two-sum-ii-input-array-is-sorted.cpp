#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach 1: Two Pointers (Optimal)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution_TwoPointers {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};

// 🟡 Approach 2: Binary Search for Complement
// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution_BinarySearch {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int left = i + 1, right = numbers.size() - 1;
            int complement = target - numbers[i];
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == complement) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] < complement) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return {};
    }
};

// 🟠 Approach 3: Hash Map (General Two Sum, not optimal for sorted input)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution_HashMap {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < numbers.size(); ++i) {
            int complement = target - numbers[i];
            if (seen.count(complement)) {
                return {seen[complement] + 1, i + 1};
            }
            seen[numbers[i]] = i;
        }
        return {};
    }
};