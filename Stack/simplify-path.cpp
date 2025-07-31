#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach: Stack-based Simulation of Unix Path Resolution
// Time Complexity: O(n), where n = length of path string
// Space Complexity: O(k), where k = number of valid folder names

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens = splitPath(path); // Tokenize by '/'
        stack<string> st;

        for (const string& token : tokens) {
            if (token.empty() || token == ".") {
                // Skip empty tokens and current directory
                continue;
            }
            if (token == "..") {
                // Go back to parent directory
                if (!st.empty()) st.pop();
            } else {
                // Valid directory or file name
                st.push(token);
            }
        }

        // 🧱 Rebuild the simplified canonical path
        vector<string> simplified;
        while (!st.empty()) {
            simplified.push_back(st.top());
            st.pop();
        }

        reverse(simplified.begin(), simplified.end());

        string res;
        for (const string& dir : simplified) {
            res += "/" + dir;
        }

        return res.empty() ? "/" : res;
    }

private:
    // 🔧 Utility: Custom string split by delimiter '/'
    vector<string> splitPath(const string& path) {
        vector<string> result;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            result.push_back(token);
        }

        return result;
    }
};
