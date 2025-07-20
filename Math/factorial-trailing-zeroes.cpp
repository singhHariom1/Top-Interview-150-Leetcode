#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Direct Formula Implementation
// Time: O(log₅(n)) | Space: O(1)
// This method directly implements the formula: count = floor(n/5) + floor(n/25) + ...

class DirectFormulaApproach {
public:
    int trailingZeroes(int n) {
        // Factorial is not defined for negative numbers.
        // The problem constraints state 0 <= n, but this is good practice.
        if (n < 0) return 0;

        int zeroesCount = 0;
        // Use long long for the divisor to make the code robust for n values
        // larger than the problem's constraints.
        long long divisor = 5;

        while (divisor <= n) {
            zeroesCount += n / divisor;

            // Prevent overflow before the multiplication for very large n.
            if (divisor > LLONG_MAX / 5) break;

            divisor *= 5;
        }
        return zeroesCount;
    }
};


// 🟢 Approach 2: Optimal Logarithmic Calculation
// Time: O(log₅(n)) | Space: O(1)
// A more concise way to compute the same sum by repeatedly dividing n.

class OptimalLogarithmicApproach {
public:
    int trailingZeroes(int n) {
        if (n < 0) return 0;

        int count = 0;
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        return count;
    }
};