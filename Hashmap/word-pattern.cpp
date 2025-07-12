#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Manual string split + Bijection Check using Two HashMaps
// Time Complexity: O(n), where n = number of words in string `s`
// Space Complexity: O(n), for the hash maps and word list

class Solution {
public:
    // Utility function to split the string into words
    vector<string> stringToWords(string& s) {
        vector<string> result;
        string word = "";
        for (char ch : s) {
            if (ch == ' ') {
                result.push_back(word);
                word = "";
            } else {
                word += ch;
            }
        }
        result.push_back(word); // Add the last word
        return result;
    }

    bool wordPattern(string pattern, string s) {
        vector<string> words = stringToWords(s);

        // Step 1: Pattern and words must be of same size
        if (pattern.size() != words.size())
            return false;

        // Step 2: Use two hash maps to store mappings
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string word = words[i];

            // Forward mapping check
            if (charToWord.count(ch)) {
                if (charToWord[ch] != word)
                    return false;
            } else {
                charToWord[ch] = word;
            }

            // Reverse mapping check
            if (wordToChar.count(word)) {
                if (wordToChar[word] != ch)
                    return false;
            } else {
                wordToChar[word] = ch;
            }
        }

        // Step 3: All mappings are consistent
        return true;
    }
};