#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m > n) return -1; // Needle can't be found if it's longer than haystack

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i; // Full match found
        }

        return -1; // No match found
    }
};
