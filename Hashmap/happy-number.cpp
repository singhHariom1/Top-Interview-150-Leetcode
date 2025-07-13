#include <bits/stdc++.h>
using namespace std;

// Utility: Sum of squares of digits
int getNext(int n) {
    int sum = 0;
    while (n) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

// 🟠 Approach 1: Using unordered_set to detect cycle
// Time Complexity: O(1) (practically bounded, see note below)
// Space Complexity: O(1)
// Note: The number of unique values before a cycle or 1 is reached is bounded for base 10, so both time and space are constant in practice.

class SolutionSet {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};

// Time Complexity: O(1) (practically bounded, see note above)
// Space Complexity: O(1)
// Approach 2: Floyd's Cycle Detection (Tortoise and Hare)
class SolutionFloyd {
public:
    bool isHappy(int n) {
        int slow = n, fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};