#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force (store all zero coordinates)
// TC: O(m * n)
// SC: O(m * n)
class SolutionBrute {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> zeros;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }

        for (auto& p : zeros) {
            for (int j = 0; j < n; ++j) matrix[p.first][j] = 0;
            for (int i = 0; i < m; ++i) matrix[i][p.second] = 0;
        }
    }
};

// 🔵 Approach 2: Row and Column Marker Arrays
// TC: O(m * n)
// SC: O(m + n)
class SolutionMarker {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> rowMark(m, false), colMark(n, false);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rowMark[i] = true;
                    colMark[j] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rowMark[i] || colMark[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// 🟢 Approach 3: Optimal In-Place using first row and column as markers
// TC: O(m * n)
// SC: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row0 = false, col0 = false;

        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == 0) row0 = true;

        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == 0) col0 = true;

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (row0) {
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        }

        if (col0) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};
