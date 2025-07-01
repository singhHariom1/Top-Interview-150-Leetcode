#include <bits/stdc++.h>
using namespace std;

// =======================================================================
// 🟠 Approach 1: Brute Force - Clean the string first, then check palindrome
// Time Complexity: O(n)
// Space Complexity: O(n) for the cleaned string
// =======================================================================

class Solution1 {
public:
    bool isPalindrome(string s) {
        string cleaned = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        int i = 0, j = cleaned.length() - 1;
        while (i < j) {
            if (cleaned[i] != cleaned[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

// =======================================================================
// 🟢 Approach 2: Optimal - Two Pointers (in-place comparison)
// Time Complexity: O(n)
// Space Complexity: O(1)
// =======================================================================

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) return false;

            i++;
            j--;
        }

        return true;
    }
};