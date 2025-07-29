#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach 1: Optimal using Stack
// Time Complexity: O(n) — iterate once through string
// Space Complexity: O(n) — for the stack in the worst case

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char ch : s) {
            if (ch == '(') stk.push(')');
            else if (ch == '{') stk.push('}');
            else if (ch == '[') stk.push(']');
            else {
                if (stk.empty() || stk.top() != ch)
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
