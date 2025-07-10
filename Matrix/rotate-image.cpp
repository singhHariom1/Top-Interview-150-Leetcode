#include <bits/stdc++.h>
using namespace std;

// =======================================================================
// 🟠 Approach 1: Extra Matrix (Copy and Assign)
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// =======================================================================
class Solution_ExtraMatrix {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> copy(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                copy[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = copy;
    }
};

// =======================================================================
// 🟡 Approach 2: Layer-by-Layer Rotation (In-Place, Four-Way Swap)
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// =======================================================================
class Solution_LayerByLayer {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int layer = 0; layer < n / 2; ++layer) {
            int first = layer, last = n - layer - 1;
            for (int i = first; i < last; ++i) {
                int offset = i - first;
                int top = matrix[first][i];
                // left -> top
                matrix[first][i] = matrix[last - offset][first];
                // bottom -> left
                matrix[last - offset][first] = matrix[last][last - offset];
                // right -> bottom
                matrix[last][last - offset] = matrix[i][last];
                // top -> right
                matrix[i][last] = top;
            }
        }
    }
};

// =======================================================================
// 🟢 Approach 3: In-Place Transpose + Reverse Rows (Optimal)
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// =======================================================================
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};