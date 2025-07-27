#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force (Nested Loops)
// Time Complexity: O(m * n)
// Space Complexity: O(1)
// ✅ Simple but not optimal for large inputs.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};


// 🟢 Approach 2: Optimal - Treat 2D matrix as 1D sorted array
// Time Complexity: O(log(m * n))
// Space Complexity: O(1)
// ✅ Uses binary search by mapping 1D indices to 2D.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s = 0, e = m * n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int i = mid / n;
            int j = mid % n;

            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return false;
    }
};
