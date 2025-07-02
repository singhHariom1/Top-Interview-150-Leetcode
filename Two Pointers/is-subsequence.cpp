#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach: Two Pointers (Optimal)
// Time Complexity: O(n + m)
// Space Complexity: O(1)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.length();
    }
};
