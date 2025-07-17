#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force (using nested loops to compare each interval with every other)
// Time Complexity: O(n^2)
// Space Complexity: O(n) for storing result

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<bool> merged(intervals.size(), false);
        vector<vector<int>> result;

        for (int i = 0; i < intervals.size(); ++i) {
            if (merged[i]) continue;
            int start = intervals[i][0];
            int end = intervals[i][1];
            for (int j = i + 1; j < intervals.size(); ++j) {
                if (merged[j]) continue;
                if (!(end < intervals[j][0] || start > intervals[j][1])) {
                    start = min(start, intervals[j][0]);
                    end = max(end, intervals[j][1]);
                    merged[j] = true;
                }
            }
            result.push_back({start, end});
        }

        return result;
    }
};


// 🟢 Approach 2: Optimal Greedy using Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(n) for result

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end()); // sort by start time

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= merged.back()[1]) {
                // Overlapping: merge
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // No overlap
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};


// 🟢 Approach: Greedy + Sorting (Optimal)
// Intuition: Sort intervals by start time. Merge overlapping intervals greedily.
// Time Complexity: O(n log n) for sorting + O(n) for merging = O(n log n)
// Space Complexity: O(n) for the output vector

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;

        // Edge case: if input is empty
        if (intervals.empty()) return mergedIntervals;

        // Step 1: Sort the intervals by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Initialize start and end of the first interval
        int start = intervals[0][0];
        int end = intervals[0][1];

        // Step 3: Traverse the remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval overlaps with the previous one
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);  // merge
            } else {
                // No overlap → push previous interval and reset start & end
                mergedIntervals.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // Step 4: Push the last interval
        mergedIntervals.push_back({start, end});

        return mergedIntervals;
    }
};