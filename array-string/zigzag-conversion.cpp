#include <bits/stdc++.h>
using namespace std;


// 🟢 Approach: Zigzag Conversion
// Time Complexity: O(n)
// Space Complexity: O(n) - for storing rows

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows)
            return s;

        vector<string> rows(min(numRows, int(s.length())));
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;

            // Change direction if we hit top or bottom
            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;

            currRow += goingDown ? 1 : -1;
        }

        string result;
        for (string row : rows)
            result += row;

        return result;
    }
};