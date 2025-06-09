#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach: Split + Filter + Reverse
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ')
                i++;
            string word = "";
            while (i < s.length() && s[i] != ' ') {
                word += s[i++];
            }
            if (!word.empty()) {
                words.push_back(word);
            }
        }
        reverse(words.begin(), words.end());
        return join(words, " ");
    }

private:
    string join(const vector<string>& words, const string& delimiter) {
        string result;
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i != words.size() - 1)
                result += delimiter;
        }
        return result;
    }
};



// 🔵 Approach: In-place string manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove extra spaces
        removeExtraSpaces(s);
        
        // Step 2: Reverse the whole string
        reverse(s.begin(), s.end());

        // Step 3: Reverse each word in-place
        int start = 0;
        for (int end = 0; end <= s.size(); ++end) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }

private:
    void removeExtraSpaces(string& s) {
        int n = s.length();
        int i = 0, j = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        while (i < n) {
            if (s[i] != ' ') {
                s[j++] = s[i++];
            } else {
                // Insert one space
                s[j++] = ' ';
                // Skip all spaces
                while (i < n && s[i] == ' ') i++;
            }
        }

        // Remove trailing space if any
        if (j > 0 && s[j - 1] == ' ') j--;

        s.resize(j);
    }
};
