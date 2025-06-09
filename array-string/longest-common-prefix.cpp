#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force Approach (Safe & Clean)
// Time: O(N * M) where N = number of strings, M = length of shortest string
// Space: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string result = "";

        // Find the length of the shortest string
        int minLen = strs[0].length();
        for (const string& str : strs) {
            minLen = min(minLen, (int)str.length());
        }

        for (int i = 0; i < minLen; i++) {
            char currentChar = strs[0][i];
            for (const string& str : strs) {
                if (str[i] != currentChar) {
                    return result;
                }
            }
            result += currentChar;
        }

        return result;
    }
};


// 🟢 Optimized Approach: Sort and Compare First & Last
// Time: O(N log N * K + M)
// Space: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());
        string result = "";
        const string& first = strs.front();
        const string& last = strs.back();
        int i = 0;

        while (i < first.length() && i < last.length() && first[i] == last[i]) {
            result += first[i];
            i++;
        }

        return result;
    }
};
