#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force Using All Permutations
// Time Complexity: O(N * K! * K * L)
// Space Complexity: O(K! * K * L)
class BrutePermSolution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        sort(words.begin(), words.end());  // Required for next_permutation

        do {
            string concat = "";
            for (const string& w : words) concat += w;

            size_t pos = s.find(concat);
            while (pos != string::npos) {
                result.push_back(static_cast<int>(pos));
                pos = s.find(concat, pos + 1);
            }
        } while (next_permutation(words.begin(), words.end()));

        sort(result.begin(), result.end());  // For consistent order
        return result;
    }
};

// 🟠 Approach 2: Brute Force Check at Each Index
// Time Complexity: O(N * K * L)
// Space Complexity: O(K)
class BruteWindowSolution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        if ((int)s.size() < totalLen) return ans;

        unordered_map<string, int> freq;
        for (const string& word : words)
            freq[word]++;

        for (int i = 0; i <= (int)s.size() - totalLen; i++) {
            unordered_map<string, int> seen = freq;
            bool valid = true;

            for (int j = 0; j < wordCount; j++) {
                string word = s.substr(i + j * wordLen, wordLen);

                if (seen.find(word) != seen.end()) {
                    if (--seen[word] == 0) seen.erase(word);
                } else {
                    valid = false;
                    break;
                }
            }

            if (valid && seen.empty()) ans.push_back(i);
        }
        return ans;
    }
};

// 🟢 Approach 3: Sliding Window with Word Count
// Time Complexity: O(N * L)
// Space Complexity: O(K)
class SlidingWindowSolution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> need;
        for (const string& word : words)
            need[word]++;

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, right = offset, matched = 0;
            unordered_map<string, int> seen;

            while (right + wordLen <= (int)s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (need.count(word)) {
                    seen[word]++;
                    matched++;

                    while (seen[word] > need[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        matched--;
                        left += wordLen;
                    }

                    if (matched == wordCount) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        matched--;
                        left += wordLen;
                    }
                } else {
                    seen.clear();
                    matched = 0;
                    left = right;
                }
            }
        }
        return ans;
    }
};
