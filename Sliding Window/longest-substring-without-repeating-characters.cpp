#include <bits/stdc++.h>
using namespace std;

/*-------------------------------------------------
 🟠 Approach 1: Sliding Window + Frequency Map
 Time Complexity : O(n)
 Space Complexity: O(128)   
-------------------------------------------------*/
class Solution_FreqMap {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, 0);
        int i = 0, maxLen = 0, n = s.length();

        for (int j = 0; j < n; ++j) {
            unsigned char ch = s[j];
            freq[ch]++;

            while (freq[ch] > 1) {              // shrink window until unique
                freq[(unsigned char)s[i]]--;
                ++i;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};

/*-------------------------------------------------
 🟢 Approach 2: Sliding Window + Last‑Seen Index
 Time Complexity : O(n)
 Space Complexity: O(128)   
-------------------------------------------------*/
class Solution_LastSeen {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIdx(128, -1);
        int i = 0, maxLen = 0, n = s.length();

        for (int j = 0; j < n; ++j) {
            unsigned char ch = s[j];

            if (lastIdx[ch] >= i)               // char repeats inside window
                i = lastIdx[ch] + 1;            // jump left pointer

            lastIdx[ch] = j;                    // update last position
            maxLen = max(maxLen, j - i + 1);    // current window size
        }
        return maxLen;
    }
};
