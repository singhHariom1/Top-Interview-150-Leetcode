#include <bits/stdc++.h>
using namespace std;

// 🟢 Time Complexity: O(n), where n = number of tokens
// 🔵 Space Complexity: O(n) for the stack

class Solution {
private:
    // ✅ Utility to check if token is an operator
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();

                if (token == "+") stk.push(b + a);
                else if (token == "-") stk.push(b - a);
                else if (token == "*") stk.push(b * a);
                else if (token == "/") stk.push(b / a); // Truncate towards 0
            } else {
                stk.push(stoi(token)); // Convert string to int
            }
        }

        return stk.top(); // Final result
    }
};
