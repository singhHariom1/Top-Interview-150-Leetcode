#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Convert to String (Basic)
// Time: O(n) | Space: O(n)

class StringApproach {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s = to_string(x);
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
};

// 🟡 Approach 3: Full Reverse with Strict Overflow Check
// Time: O(log₁₀(n)) | Space: O(1)

class FullReverseStrict {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int original = x, reverse = 0;

        while (x != 0) {
            int digit = x % 10;

            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && digit > 7))
                return false;

            reverse = reverse * 10 + digit;
            x /= 10;
        }

        return reverse == original;
    }
};

// 🟢 Approach 4: Reverse Half the Number (Optimal)
// Time: O(log₁₀(n)) | Space: O(1)

class HalfReverseOptimal {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }
};