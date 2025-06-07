#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach: Optimized (Scan from end)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution_Optimized {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int length = 0;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') i--;

        // Count characters of last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};