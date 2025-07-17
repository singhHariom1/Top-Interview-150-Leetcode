#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach: Insert and Merge (Optimal)
// Intuition:
// 1. Add all intervals that end before the new interval starts.
// 2. Merge overlapping intervals with the newInterval.
// 3. Add all intervals that start after the newInterval ends.
// Time Complexity: O(n)
// Space Complexity: O(n) for result array

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // Step 1: Add intervals that come before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i++]);
        }

        // Step 2: Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval); // merged interval

        // Step 3: Add remaining intervals
        while (i < n) {
            result.push_back(intervals[i++]);
        }

        return result;
    }
};
