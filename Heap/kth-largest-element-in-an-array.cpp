#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1: Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution_Sorting {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};


// 🟢 Approach 2: Min-Heap (Optimal)
// Time Complexity: O(n log k)
// Space Complexity: O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        return minHeap.top();
    }
};
