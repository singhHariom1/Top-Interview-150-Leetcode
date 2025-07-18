#include <bits/stdc++.h>
using namespace std;

/*
🧠 Problem: Minimum Number of Arrows to Burst Balloons
Given intervals [xstart, xend], an arrow at x bursts all balloons with xstart <= x <= xend.
Goal: Minimize number of arrows to burst all balloons.
*/

// ============================================================================
// 🟠 Approach 1: Brute Force (TLE for large inputs)
// Time: O(n^2) | Space: O(n)

class BruteForce {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        int arrows = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            int x = points[i][0]; // Shoot at xstart
            arrows++;

            for (int j = 0; j < n; j++) {
                if (!visited[j] && points[j][0] <= x && x <= points[j][1]) {
                    visited[j] = true;
                }
            }
        }

        return arrows;
    }
};

// ============================================================================
// 🟡 Approach 2: Greedy by Sorting on xstart + Interval Intersection
// Time: O(n log n) | Space: O(1)

class GreedyXStart {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end()); // Sort by xstart
        int arrows = 1;
        int start = points[0][0];
        int end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= end) {
                // Update overlapping interval window
                start = max(start, points[i][0]);
                end = min(end, points[i][1]);
            } else {
                // No overlap, shoot new arrow
                arrows++;
                start = points[i][0];
                end = points[i][1];
            }
        }

        return arrows;
    }
};

// ============================================================================
// 🟢 Approach 3: Greedy by Sorting on xend (Optimal)
// Time: O(n log n) | Space: O(1)

class GreedyXEnd {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by xend
        });

        int arrows = 1;
        int lastArrow = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > lastArrow) {
                arrows++;
                lastArrow = points[i][1]; // Shoot at current balloon's end
            }
        }

        return arrows;
    }
};