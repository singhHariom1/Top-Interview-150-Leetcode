#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Sorting-based (Brute Force)
// Time Complexity: O(n log n)
// Space Complexity: O(n) due to sorted strings
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

// 🟢 Approach 2: Hash Table with Fixed Array (Optimal for lowercase a-z only)
// Time Complexity: O(n)
// Space Complexity: O(1) — Fixed array size (26)
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;
        for (char c : t) freq[c - 'a']--;

        for (int count : freq) {
            if (count != 0) return false;
        }
        return true;
    }
};

// 🟣 Approach 3: Unicode-compatible using unordered_map
// Time Complexity: O(n)
// Space Complexity: O(u), u = number of unique characters
class Solution3 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        for (char c : t) freq[c]--;
        
        for (auto &[ch, count] : freq) {
            if (count != 0) return false;
        }
        return true;
    }
};
