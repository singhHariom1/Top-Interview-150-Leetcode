#include <bits/stdc++.h>
using namespace std;

/*───────────────────────────────────────────────────────────────*
  🟠 Approach 1: Brute Force (check every substring)

    Time Complexity  :  O(m · n)   (≈ O(m²) when n ≪ m)
    Space Complexity :  O(n)       (fresh hash‑map copy per i)
 *───────────────────────────────────────────────────────────────*/
 class Solution1 {
    public:
        string minWindow(string s, string t) {
            string str = "";
            int minLen = INT_MAX;
            int m = s.length(), n = t.length();
            if (m < n)
                return str;
            unordered_map<char, int> freq;
    
            for (char ch : t) {
                freq[ch]++;
            }
    
            for (int i = 0; i < m; i++) {
                unordered_map<char, int> copy = freq;
                for (int j = i; j < m; j++) {
                    char ch = s[j];
                    if (copy.find(ch) != copy.end()) {
                        if (--copy[ch] == 0)
                            copy.erase(ch);
                    }
    
                    if (copy.empty() && j - i + 1 < minLen) {
                        str = s.substr(i, j - i + 1);
                        minLen = j - i + 1;
                        break;
                    }
                }
            }
            return str;
        }
};    

/*───────────────────────────────────────────────────────────────*
  🟢 Approach 2: Optimal Sliding Window

    Time Complexity  :  O(m + n)   (each index processed ≤ 2 times)
    Space Complexity :  O(Σ alphabet) ≈ O(1) for ASCII
 *───────────────────────────────────────────────────────────────*/
 class Solution2 {
    public:
        string minWindow(string s, string t) {
            int m = s.length(), n = t.length();
            int l = 0, r = 0;
            int minLen = INT_MAX, sIdx = -1;
            int cnt = 0;
    
            vector<int> hash(128, 0);
    
            // Step 1: Fill the hash array with frequencies of characters in t
            for (char ch : t) {
                hash[(unsigned char)ch]++;
            }
    
            // Step 2: Start sliding window from left to right
            while (r < m) {
                // If current character is needed (i.e., still positive in hash), count it
                if (hash[(unsigned char)s[r]] > 0) {
                    cnt++;
                }
                // Decrease the frequency of current character regardless
                hash[(unsigned char)s[r]]--;
    
                // Step 3: If we have found all characters (cnt == length of t)
                while (cnt == n) {
                    // Update result if current window is smaller
                    if (r - l + 1 < minLen) {
                        minLen = r - l + 1;
                        sIdx = l;
                    }
    
                    // Before moving l forward, we need to undo its contribution
                    hash[(unsigned char)s[l]]++;
    
                    // If the character at l is needed again (i.e., becomes > 0), reduce cnt
                    if (hash[(unsigned char)s[l]] > 0) {
                        cnt--;
                    }
    
                    // Move the left boundary
                    l++;
                }
    
                // Move the right boundary
                r++;
            }
    
            return sIdx == -1 ? "" : s.substr(sIdx, minLen);
        }
};    
    