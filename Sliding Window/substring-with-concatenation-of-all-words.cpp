#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1: Brute Force (Generate all permutations)
// Time Complexity: O(k! * k * word_length * n * k * word_length) = O(k! * k² * word_length² * n)
// Space Complexity: O(k! * k * word_length)
// This approach gives TLE due to exponential complexity

class Solution_BruteForce {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        sort(words.begin(), words.end());
        vector<int> result;
        do {
            string concat;
            concat.reserve(words.size() * words[0].size());
            for (const string& w : words)
                concat += w;

            size_t pos = s.find(concat, 0);
            while (pos != string::npos) {
                result.push_back(static_cast<int>(pos));
                pos = s.find(concat, pos + 1);
            }
        } while (next_permutation(words.begin(), words.end()));
        return result;
    }
};

// 🟢 Approach 2: Sliding Window + Hash Map (Optimal)
// Time Complexity: O(n * k * word_length)
// Space Complexity: O(k * word_length)
// Key Insight: Instead of generating permutations, check if each window contains exactly the required words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.length();
        int k = words.size();
        int wordLen = words[0].length();
        int windowLen = k * wordLen;
        
        // Create frequency map for words
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }
        
        // Check each possible starting position
        for (int start = 0; start <= n - windowLen; start++) {
            unordered_map<string, int> seenFreq;
            bool valid = true;
            
            // Check each word in the current window
            for (int i = 0; i < k; i++) {
                string currentWord = s.substr(start + i * wordLen, wordLen);
                
                // If word not in original list or we've seen it too many times
                if (wordFreq.find(currentWord) == wordFreq.end() || 
                    seenFreq[currentWord] >= wordFreq[currentWord]) {
                    valid = false;
                    break;
                }
                seenFreq[currentWord]++;
            }
            
            if (valid) {
                result.push_back(start);
            }
        }
        
        return result;
    }
};

// 🟡 Approach 3: Optimized Sliding Window (Alternative)
// Time Complexity: O(n * k * word_length)
// Space Complexity: O(k * word_length)
// Uses a more efficient approach by checking all possible word lengths

class Solution_Optimized {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.length();
        int k = words.size();
        int wordLen = words[0].length();
        
        // Create frequency map for words
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }
        
        // Try each possible starting position for the first word
        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string, int> seenFreq;
            int left = offset;
            int count = 0;
            
            // Slide window by word length
            for (int right = offset; right <= n - wordLen; right += wordLen) {
                string currentWord = s.substr(right, wordLen);
                
                if (wordFreq.find(currentWord) != wordFreq.end()) {
                    seenFreq[currentWord]++;
                    count++;
                    
                    // Shrink window if we have too many of current word
                    while (seenFreq[currentWord] > wordFreq[currentWord]) {
                        string leftWord = s.substr(left, wordLen);
                        seenFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    
                    // If we have exactly k words, we found a valid substring
                    if (count == k) {
                        result.push_back(left);
                        // Move left pointer to continue searching
                        string leftWord = s.substr(left, wordLen);
                        seenFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    // Reset if we encounter an invalid word
                    seenFreq.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        
        return result;
    }
};