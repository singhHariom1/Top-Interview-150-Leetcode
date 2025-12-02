#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1: Brute Force
// Time Complexity: O(n*m log(n*m)) where n and m are sizes of arrays
// Space Complexity: O(n*m)

class Solution_BruteForce {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> pairs;
        for (int x : nums1) {
            for (int y : nums2) {
                pairs.push_back({x, y});
            }
        }
        
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] + a[1]) < (b[0] + b[1]);
        });
        
        if (pairs.size() > k) pairs.resize(k);
        return pairs;
    }
};


// 🟢 Approach 2: Min-Heap (Optimal)
// Time Complexity: O(k log k)
// Space Complexity: O(k)

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;
        
        // Min-heap stores {sum, i, j} where i and j are indices in nums1 and nums2
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Initialize heap with pairs (nums1[i], nums2[0])
        for (int i = 0; i < nums1.size() && i < k; i++) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }
        
        while (k-- && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            
            int i = top[1];
            int j = top[2];
            
            result.push_back({nums1[i], nums2[j]});
            
            // If there is a next element in nums2 for the current nums1[i], add it
            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }
        
        return result;
    }
};
