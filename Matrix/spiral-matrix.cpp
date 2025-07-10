#include <bits/stdc++.h>
using namespace std;

// =======================================================================
// 🟠 Approach 1: Simulation with Visited Matrix
// Time Complexity: O(m * n)
// Space Complexity: O(m * n) for visited
// =======================================================================
class Solution_Simulation {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> result;
        int dirs[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        int r = 0, c = 0, d = 0;
        for (int i = 0; i < m * n; ++i) {
            result.push_back(matrix[r][c]);
            visited[r][c] = true;
            int nr = r + dirs[d][0], nc = c + dirs[d][1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                r = nr; c = nc;
            } else {
                d = (d + 1) % 4;
                r += dirs[d][0];
                c += dirs[d][1];
            }
        }
        return result;
    }
};

// =======================================================================
// 🟡 Approach 2: Recursive Layer-by-Layer Traversal
// Time Complexity: O(m * n)
// Space Complexity: O(m * n) for recursion stack in worst case
// =======================================================================
class Solution_Recursive {
    void spiral(vector<vector<int>>& matrix, int top, int bottom, int left, int right, vector<int>& result) {
        if (top > bottom || left > right) return;
        for (int j = left; j <= right; ++j) result.push_back(matrix[top][j]);
        for (int i = top + 1; i <= bottom; ++i) result.push_back(matrix[i][right]);
        if (top < bottom && left < right) {
            for (int j = right - 1; j > left; --j) result.push_back(matrix[bottom][j]);
            for (int i = bottom; i > top; --i) result.push_back(matrix[i][left]);
        }
        spiral(matrix, top + 1, bottom - 1, left + 1, right - 1, result);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        spiral(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, result);
        return result;
    }
};

// =======================================================================
// 🟢 Approach 3: Iterative Layer-by-Layer Traversal (Optimal)
// Time Complexity: O(m * n)
// Space Complexity: O(1) (excluding output)
// =======================================================================
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j)
                result.push_back(matrix[top][j]);
            ++top;
            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            --right;
            if (top <= bottom) {
                for (int j = right; j >= left; --j)
                    result.push_back(matrix[bottom][j]);
                --bottom;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    result.push_back(matrix[i][left]);
                ++left;
            }
        }
        return result;
    }
};