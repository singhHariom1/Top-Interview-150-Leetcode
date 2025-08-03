#include <bits/stdc++.h>
using namespace std;

// 🟢 Optimal Approach: Two Stacks (Main Stack + Min Stack)
// Time Complexity: O(1) for all operations
// Space Complexity: O(n) extra space for minStack

class MinStack {
private:
    vector<int> stack;     // Main stack to store all values
    vector<int> minStack;  // Auxiliary stack to store current minimums

public:
    // Constructor
    MinStack() {}

    // Push value and update minStack if necessary
    void push(int val) {
        stack.push_back(val);
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }

    // Pop from both stacks if top is equal to current min
    void pop() {
        if (!stack.empty()) {
            if (stack.back() == minStack.back()) {
                minStack.pop_back();
            }
            stack.pop_back();
        }
    }

    // Return top element of main stack
    int top() {
        return stack.back();
    }

    // Return current minimum element
    int getMin() {
        return minStack.back();
    }
};

/*
🔹 Example Usage:

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // Output: -3
    minStack.pop();
    cout << minStack.top() << endl;    // Output: 0
    cout << minStack.getMin() << endl; // Output: -2
}
*/

