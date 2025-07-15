#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force using nested loops and sorting comparison
// Time Complexity: O(N^2 * K log K)
// Space Complexity: O(N)
// ⚠️ Inefficient for large inputs, not recommended for production.

class BruteForceSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<bool> used(strs.size(), false);
        vector<vector<string>> result;

        for (int i = 0; i < strs.size(); ++i) {
            if (used[i]) continue;
            vector<string> group = {strs[i]};
            used[i] = true;

            string sorted_i = strs[i];
            sort(sorted_i.begin(), sorted_i.end());

            for (int j = i + 1; j < strs.size(); ++j) {
                if (used[j]) continue;

                string sorted_j = strs[j];
                sort(sorted_j.begin(), sorted_j.end());

                if (sorted_i == sorted_j) {
                    group.push_back(strs[j]);
                    used[j] = true;
                }
            }
            result.push_back(group);
        }

        return result;
    }
};


// 🟢 Approach 2: Optimal using Sorted Strings as Keys (HashMap)
// Time Complexity: O(N * K log K) — K = avg string length
// Space Complexity: O(N * K)

class SortedMapSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : mp) {
            result.push_back(entry.second);
        }

        return result;
    }
};


// 🟢 Approach 3: Optimal using Character Frequency Count as Key
// Time Complexity: O(N * K)
// Space Complexity: O(N * K)
// 🚀 Most efficient for long strings since it avoids sorting

class FrequencyKeySolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& s : strs) {
            vector<int> freq(26, 0);
            for (char ch : s) freq[ch - 'a']++;

            // Build key using freq array
            string key = "";
            for (int count : freq) {
                key += to_string(count) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : mp) {
            result.push_back(entry.second);
        }

        return result;
    }
};