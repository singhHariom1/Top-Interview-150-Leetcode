#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force using n & 1
// Time Complexity: O(log n)
// Space Complexity: O(1)

class BruteForceSolution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
};

// 🟢 Approach 2: Brian Kernighan’s Algorithm
// Time Complexity: O(number of set bits)
// Space Complexity: O(1)

class BrianKernighanSolution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1); // removes the lowest set bit
            count++;
        }
        return count;
    }
};

// 🔵 Approach 3: Using Built-in Function
// Time Complexity: O(1) (internally optimized)
// Space Complexity: O(1)

class BuiltinFunctionSolution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n); // GCC/Clang specific
    }
};