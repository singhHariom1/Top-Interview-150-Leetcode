#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach 1: Recursive Evaluation
// Time Complexity: O(n)
// Space Complexity: O(n) — due to recursion depth

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return evaluate(s, i);
    }

private:
    int evaluate(const string& s, int& i) {
        int res = 0;
        int num = 0;
        int sign = 1;

        while (i < s.size()) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '+') {
                res += sign * num;
                num = 0;
                sign = +1;
            }
            else if (ch == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            }
            else if (ch == '(') {
                i++; // move past '('
                int innerResult = evaluate(s, i); // recursive call
                res += sign * innerResult;
                num = 0; // reset num after handling inner expression
            }
            else if (ch == ')') {
                res += sign * num; // add last number before ')'
                return res;        // return to previous context
            }
            // Ignore spaces
            i++;
        }

        res += sign * num; // final number
        return res;
    }
};



// 🟢 Approach 2: Stack-Based Evaluation
// Time Complexity: O(n), Space Complexity: O(n)
class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, num = 0;
        stack<int> stk;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (ch == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (ch == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            } else if (ch == ')') {
                res += sign * num;
                num = 0;
                res *= stk.top(); stk.pop(); // sign before '('
                res += stk.top(); stk.pop(); // result calculated before '('
            }
        }
        res += sign * num;
        return res;
    }
};
