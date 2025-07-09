#include <bits/stdc++.h>
using namespace std;

/*-------------------------------------------------------------*
 🟠 Approach 1: HashSet for Rows, Columns, and Boxes
   - Use 3 arrays of sets to track seen digits in rows, columns, and boxes
   - TC: O(1) (since board is always 9x9)
   - SC: O(1)
 *-------------------------------------------------------------*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9), cols(9), boxes(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char curr = board[i][j];
                if (curr == '.') continue;
                int box_index = (i / 3) * 3 + (j / 3);
                if (rows[i].count(curr) || cols[j].count(curr) || boxes[box_index].count(curr))
                    return false;
                rows[i].insert(curr);
                cols[j].insert(curr);
                boxes[box_index].insert(curr);
            }
        }
        return true;
    }
};

/*-------------------------------------------------------------*
 🟢 Approach 2: Bitmask Optimization (optional, for fun)
   - Use bitmasks instead of sets for O(1) lookup/insert
   - TC: O(1), SC: O(1)
 *-------------------------------------------------------------*/
class SolutionBitmask {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {}, cols[9] = {}, boxes[9] = {};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char curr = board[i][j];
                if (curr == '.') continue;
                int mask = 1 << (curr - '1');
                int box_index = (i / 3) * 3 + (j / 3);
                if ((rows[i] & mask) || (cols[j] & mask) || (boxes[box_index] & mask))
                    return false;
                rows[i] |= mask;
                cols[j] |= mask;
                boxes[box_index] |= mask;
            }
        }
        return true;
    }
};