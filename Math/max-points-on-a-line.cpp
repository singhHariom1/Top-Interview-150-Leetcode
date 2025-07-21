#include <bits/stdc++.h>
using namespace std;

// 🟢 Optimal Approach: Slope Hashing (O(n^2))
// Time Complexity: O(n^2)
// Space Complexity: O(n) per iteration

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> slopeCount;
            int vertical = 0;
            int currMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0) {
                    // 🟠 Vertical line (undefined slope)
                    vertical++;
                } else {
                    // 🟢 Normalize slope using GCD
                    int gcd = __gcd(dy, dx);
                    dy /= gcd;
                    dx /= gcd;

                    // 🔁 Ensure dx is positive for consistent slope representation
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }

                    slopeCount[{dy, dx}]++;
                    currMax = max(currMax, slopeCount[{dy, dx}]);
                }
            }

            // Consider vertical lines too
            currMax = max(currMax, vertical);

            // +1 for the base point itself
            ans = max(ans, currMax + 1);
        }

        return ans;
    }
};



// 🟢 Optimal Approach: Slope Hashing (O(n^2)) + Duplicate Handling
// Time Complexity: O(n^2)
// Space Complexity: O(n) per iteration

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> slopeCount;
            int duplicate = 0;
            int vertical = 0;
            int currMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    // 🟡 Duplicate point
                    duplicate++;
                } else if (dx == 0) {
                    // 🟠 Vertical line (undefined slope)
                    vertical++;
                } else {
                    // 🟢 Normalize slope using GCD
                    int gcd = __gcd(dy, dx);
                    dy /= gcd;
                    dx /= gcd;

                    // 🔁 Keep dx positive for unique representation
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }

                    slopeCount[{dy, dx}]++;
                    currMax = max(currMax, slopeCount[{dy, dx}]);
                }
            }

            // Consider vertical lines as well
            currMax = max(currMax, vertical);

            // +1 for the base point itself, +duplicate for exact copies
            ans = max(ans, currMax + duplicate + 1);
        }

        return ans;
    }
};
